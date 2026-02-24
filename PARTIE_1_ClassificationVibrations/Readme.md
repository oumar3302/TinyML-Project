# Partie 1 – Classification de vibrations (TinyML)

## 1. Présentation

Cette partie du projet TinyML a pour objectif de concevoir un système embarqué capable de **classifier différents niveaux de vibration** à partir de données issues d’un capteur inertiel.

L’ensemble de la chaîne TinyML est implémentée :
- Collecte de données sur microcontrôleur
- Entraînement d’un modèle de Machine Learning
- Déploiement et inférence embarquée en temps réel

---

## 2. Objectifs de la partie

Les objectifs principaux sont les suivants :

1. Générer ou capter différents niveaux de vibration (absence, vibration moyenne, vibration forte)
2. Collecter les données via l’IMU embarquée sur l’Arduino Nano 33 BLE
3. Construire un dataset exploitable pour l’apprentissage
4. Entraîner un modèle de classification compatible TinyML
5. Déployer le modèle sur la carte Arduino
6. Réaliser une inférence locale en temps réel

---

## 3. Matériel et outils utilisés

### Matériel
- Arduino Nano 33 BLE Sense
- IMU intégrée (accéléromètre 3 axes)

### Logiciels et librairies
- Arduino IDE
- Python
- Jupyter Notebook
- TensorFlow / TensorFlow Lite for Microcontrollers

---

## 4. Structure de la partie
PARTIE_1_ClassificationVibrations/
│
├── README.md
│
├── 1-DataGeneration_Arduino/
│ └── data_generation.ino
│
├── 2-Training/
│ ├── dataset/
│ ├── notebooks/
│ │ └── training_vibrations.ipynb
│ └── models/
│ └── model_vibration.tflite
│
├── 3-Inference_Arduino/
│ └── inference_vibrations.ino
│
└── doc/
└── documentation.md

---

## 5. Étape 1 – Génération et collecte des données

Le dossier `1-DataGeneration_Arduino` contient le code Arduino permettant :

- D’initialiser l’IMU
- De lire les accélérations selon les axes X, Y et Z
- De transmettre les données via la liaison série

Les données sont ensuite récupérées sur le PC et enregistrées dans des fichiers CSV, chaque fichier correspondant à une classe de vibration.

Format des données : ax, ay,az, label

---

## 6. Étape 2 – Entraînement du modèle

L’entraînement est réalisé dans le notebook `training_vibrations.ipynb`.

Cette étape comprend :
- Le chargement et la préparation des données
- La séparation des entrées (ax, ay, az) et des labels
- L’entraînement d’un modèle de classification léger
- L’évaluation des performances
- L’export du modèle au format TensorFlow Lite (`.tflite`)

Le modèle est ensuite placé dans le dossier `models/`.

---

## 7. Étape 3 – Inférence embarquée

Le dossier `3-Inference_Arduino` contient le code permettant :

- D’intégrer le modèle TensorFlow Lite dans l’Arduino
- De lire les données de l’IMU en temps réel
- D’effectuer l’inférence localement
- D’afficher la classe prédite via le moniteur série

Les classes de sortie sont :
- Classe 0 : No vibration
- Classe 1 : Medium vibration
- Classe 2 : Strong vibration

---

## 8. Résultats attendus

Le système doit être capable de :
- Reconnaître correctement le niveau de vibration
- Fonctionner en temps réel
- Respecter les contraintes mémoire et de calcul du microcontrôleur

---

## 9. Documentation associée

Une documentation détaillée est disponible dans le dossier `doc/` :
- Explications techniques
- Détails sur la reproduction de l’expérience
- Captures d’écran des résultats
- Description des librairies utilisées

---

## 10. Conclusion

Cette partie du projet illustre une application concrète du TinyML pour la classification de signaux physiques.  
Elle constitue une base solide pour des applications telles que la surveillance vibratoire ou la maintenance prédictive.
