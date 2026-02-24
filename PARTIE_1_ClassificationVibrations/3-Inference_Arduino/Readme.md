🎯 Objectif

Cette partie du projet consiste à déployer un modèle TinyML entraîné pour la classification de vibrations sur une carte Arduino Nano 33 BLE, en utilisant la bibliothèque Harvard TinyML (TensorFlow Lite Micro).
Le système réalise une inférence en temps réel à partir des données issues de l’IMU intégrée.

🧠 Principe de fonctionnement

Lecture des accélérations selon les axes X, Y et Z via l’IMU

Construction d’une fenêtre temporelle de 50 échantillons

Normalisation des données à l’aide des paramètres issus de l’entraînement

Exécution du modèle TensorFlow Lite Micro quantifié en INT8

Affichage de la classe de vibration prédite via le port série

📁 Contenu du dossier
3-Inference_Arduino/
│
├── inference_vibrations.ino
├── vibration_model.h
└── README.md

⚙️ Prétraitement des données

Les données sont normalisées sur la carte Arduino à l’aide des paramètres suivants :

Moyenne (mean)

Écart-type (scale)

Ces valeurs sont calculées lors de l’entraînement à partir du dataset et intégrées manuellement dans le code Arduino afin d’assurer une parfaite cohérence entre l’entraînement et l’inférence.

🧩 Modèle embarqué

Type : Réseau de neurones dense

Entrée : Fenêtre de 50 × 3 (accéléromètre)

Sortie : 3 classes de vibration

Format : TensorFlow Lite

Quantification : float32

Mémoire optimisée pour microcontrôleur

🧪 Utilisation

Flasher le programme inference_vibrations.ino sur l’Arduino Nano 33 BLE

Ouvrir le moniteur série (115200 bauds)

Générer des vibrations correspondant aux classes entraînées

Observer la classe prédite affichée en temps réel

📌 Remarques

La fréquence d’échantillonnage est d’environ 100 Hz

Le modèle est exécuté entièrement sur la carte Arduino

Aucun calcul n’est effectué côté PC durant l’inférence