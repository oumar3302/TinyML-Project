import serial
import csv
import time

PORT = "COM4"          # à adapter
BAUDRATE = 115200
LABEL = 2              # 0: no vibration, 1: medium, 2: strong
DURATION = 10          # secondes
OUTPUT_FILE = f"vibration_{LABEL}.csv"

ser = serial.Serial(PORT, BAUDRATE, timeout=1)
time.sleep(2)

with open(OUTPUT_FILE, "w", newline="") as f:
    writer = csv.writer(f)
    #writer.writerow(["timestamp", "ax", "ay", "az", "label"])
    writer.writerow(["ax", "ay", "az", "label"])

    start_time = time.time()

    while time.time() - start_time < DURATION:
        line = ser.readline().decode("utf-8").strip()

        if line:
            try:
                ax, ay, az = line.split(",")
                #writer.writerow([timestamp, ax, ay, az, LABEL])
                writer.writerow([ax, ay, az, LABEL])
                
            except ValueError:
                pass

ser.close()
print("Acquisition terminée :", OUTPUT_FILE)
