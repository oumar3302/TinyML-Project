# Projet TinyML – Instrumentation 3

## 📌 Présentation générale

Ce dépôt GitHub regroupe le projet **TinyML** réalisé dans le cadre du module **Instrumentation 3**.  
L’objectif est de mettre en œuvre des systèmes d’intelligence artificielle **embarquée sur microcontrôleur**, en respectant une démarche complète allant de la collecte de données jusqu’à l’inférence en temps réel.

Le projet est structuré en **deux parties indépendantes mais complémentaires**, chacune illustrant une application concrète du TinyML.

---

## 🎯 Objectifs pédagogiques

Ce projet vise à permettre aux étudiants de :

- Comprendre le pipeline complet d’un projet TinyML
- Manipuler des capteurs réels et collecter des données exploitables
- Entraîner des modèles de Machine Learning adaptés aux contraintes embarquées
- Déployer des modèles sur microcontrôleur
- Réaliser une inférence locale en temps réel
- Documenter clairement un projet d’IA embarquée

---

## 🧩 Organisation du projet

Le dépôt est structuré comme suit :
TinyML_project/
│
├── README.md
│
├── PARTIE_1_ClassificationVibrations/
│ │ ├── README.md
│ │ ├── 1-DataGeneration_Arduino/
│ │ ├── 2-Training/
│ │ ├── 3-Inference_Arduino/
│ │ └── doc/
│
└── PARTIE_2_ClassificationComposants/
│ ├── README.md
│ ├── 1-EdgeImpulse/
│ ├── 2-ArduinoCamera/
│ ├── 3-NodeRED/
│ └── doc/


Chaque partie dispose de son propre code, de sa documentation et de ses ressources associées.
---

## 🧠 Partie 1 – Classification de vibrations

### Objectif

Mettre en place un système capable de :

1. Générer ou capter des vibrations
2. Collecter les données via l’IMU de l’Arduino Nano 33 BLE
3. Entraîner un modèle de classification (TensorFlow / TensorFlow Lite)
4. Déployer le modèle et effectuer l’inférence en temps réel sur la carte Arduino

### Technologies utilisées

- Arduino Nano 33 BLE Sense
- IMU embarquée (accéléromètre)
- Python / Jupyter Notebook
- TensorFlow / TensorFlow Lite for Microcontrollers

---

## 🖼️ Partie 2 – Classification et comptage de composants électroniques

### Objectif

Mettre en œuvre un système de reconnaissance visuelle permettant de :

1. Reconnaître des composants électroniques (LED, résistances, condensateurs)
2. Utiliser une caméra OV7675 connectée à un Arduino Nano 33 BLE
3. Exploiter la plateforme **Edge Impulse** pour l’entraînement
4. Effectuer l’inférence embarquée
5. Transmettre les résultats à **Node-RED** pour le comptage et l’affichage sur un tableau de bord

### Technologies utilisées

- Arduino Nano 33 BLE
- Caméra OV7675
- Edge Impulse
- Bluetooth (BLE) ou liaison série
- Node-RED Dashboard

---

## 👨‍💻 Cadre académique

Projet réalisé dans le cadre du module **Instrumentation 3 – TinyML**,  
Université / École d’ingénieur.


Réalisé: *** FALL Papa Oumar ***
Session: 2025/2026

