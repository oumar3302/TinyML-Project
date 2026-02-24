#include <Arduino_LSM9DS1.h>
#include <TensorFlowLite.h>

#include "vibration_model.h"

#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/version.h"

#define WINDOW_SIZE 50
#define N_FEATURES 3
#define N_CLASSES  3

const float mean[N_FEATURES]  = {-0.16683027f, -0.05503448f,  0.2664418f};
const float scale[N_FEATURES] = { 0.21714608f,  0.0694794f,   0.91890501f};

const float vibThreshold = 0.8f;

static float window_buf[WINDOW_SIZE * N_FEATURES];
static int samplesRead = WINDOW_SIZE;

constexpr int kTensorArenaSize = 32 * 1024;
alignas(16) static uint8_t tensor_arena[kTensorArenaSize];

static const tflite::Model* model = nullptr;
static tflite::MicroInterpreter* interpreter = nullptr;
static TfLiteTensor* input = nullptr;
static TfLiteTensor* output = nullptr;

static const char* labels[N_CLASSES] = {"NORMAL", "FAIBLE", "FORTE"};

static inline float norm_and_clip(float v, int k) {
  float x = (v - mean[k]) / scale[k];
  if (!isfinite(x)) x = 0.0f;
  if (x > 5.0f) x = 5.0f;
  if (x < -5.0f) x = -5.0f;
  return x;
}

static bool readAccelNorm(float &ax, float &ay, float &az) {
  if (!IMU.accelerationAvailable()) return false;
  float x, y, z;
  IMU.readAcceleration(x, y, z);
  ax = norm_and_clip(x, 0);
  ay = norm_and_clip(y, 1);
  az = norm_and_clip(z, 2);
  return true;
}

static void fillInputFromWindow() {
  if (input->type == kTfLiteFloat32) {
    for (int i = 0; i < WINDOW_SIZE * N_FEATURES; i++) {
      input->data.f[i] = window_buf[i];
    }
    return;
  }

  if (input->type == kTfLiteInt8) {
    int8_t* in = input->data.int8;
    const float in_scale = input->params.scale;
    const int in_zp = input->params.zero_point;

    for (int i = 0; i < WINDOW_SIZE * N_FEATURES; i++) {
      float v = window_buf[i];
      int32_t q = (int32_t)lroundf(v / in_scale) + in_zp;
      if (q < -128) q = -128;
      if (q > 127)  q = 127;
      in[i] = (int8_t)q;
    }
    return;
  }
}

static void printResult() {
  if (output->type == kTfLiteFloat32) {
    int best = 0;
    float bestScore = output->data.f[0];
    for (int i = 1; i < N_CLASSES; i++) {
      float s = output->data.f[i];
      if (s > bestScore) { bestScore = s; best = i; }
    }
    Serial.print(labels[best]);
    Serial.print(",");
    Serial.println(bestScore, 4);
    return;
  }

  if (output->type == kTfLiteInt8) {
    const int8_t* out = output->data.int8;
    const float out_scale = output->params.scale;
    const int out_zp = output->params.zero_point;

    int best = 0;
    float bestScore = (out[0] - out_zp) * out_scale;
    for (int i = 1; i < N_CLASSES; i++) {
      float s = (out[i] - out_zp) * out_scale;
      if (s > bestScore) { bestScore = s; best = i; }
    }
    Serial.print(labels[best]);
    Serial.print(",");
    Serial.println(bestScore, 4);
    return;
  }

  Serial.println("ERR_OUTPUT_TYPE");
}

void setup() {
  Serial.begin(115200);
  unsigned long t0 = millis();
  while (!Serial && (millis() - t0 < 1500)) {}

  if (!IMU.begin()) {
    Serial.println("ERR_IMU");
    while (1) {}
  }

  model = tflite::GetModel(vibration_model);
  if (!model) {
    Serial.println("ERR_MODEL");
    while (1) {}
  }

  if (model->version() != TFLITE_SCHEMA_VERSION) {
    Serial.println("ERR_SCHEMA");
    while (1) {}
  }

  static tflite::AllOpsResolver resolver;
  static tflite::MicroErrorReporter micro_error_reporter;

  static tflite::MicroInterpreter static_interpreter(
    model,
    resolver,
    tensor_arena,
    kTensorArenaSize,
    &micro_error_reporter,
    nullptr
  );

  interpreter = &static_interpreter;

  if (interpreter->AllocateTensors() != kTfLiteOk) {
    Serial.println("ERR_ALLOC");
    while (1) {}
  }

  input = interpreter->input(0);
  output = interpreter->output(0);

  samplesRead = WINDOW_SIZE;
  Serial.println("READY");
}

void loop() {
  float ax, ay, az;

  while (samplesRead == WINDOW_SIZE) {
    if (readAccelNorm(ax, ay, az)) {
      float vib = fabs(ax) + fabs(ay) + fabs(az);
      if (vib >= vibThreshold) {
        samplesRead = 0;
        break;
      }
    }
  }

  static unsigned long lastSample = 0;
  if (samplesRead < WINDOW_SIZE) {
    if (millis() - lastSample >= 10) {
      lastSample = millis();
      if (readAccelNorm(ax, ay, az)) {
        int base = samplesRead * N_FEATURES;
        window_buf[base + 0] = ax;
        window_buf[base + 1] = ay;
        window_buf[base + 2] = az;
        samplesRead++;
      }
    }
  }

  if (samplesRead == WINDOW_SIZE) {
    fillInputFromWindow();

    if (interpreter->Invoke() != kTfLiteOk) {
      Serial.println("ERR_INVOKE");
      samplesRead = WINDOW_SIZE;
      return;
    }

    printResult();
    Serial.println();
    samplesRead = WINDOW_SIZE;
  }
}
