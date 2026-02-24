
Déploiement du modèle Edge Impulse sur Arduino

## 🎯 Objectif

Cette partie du projet a pour objectif de déployer un modèle de classification d’images entraîné sur la plateforme Edge Impulse vers une carte Arduino Nano 33 BLE, afin de réaliser une inférence embarquée en temps réel à partir des images capturées par la caméra.
---

## 🧠 Principe de déploiement

Le déploiement du modèle est entièrement pris en charge par Edge Impulse.
À l’issue de l’entraînement et de la validation du modèle, la plateforme permet de générer automatiquement une bibliothèque Arduino contenant :

- Le modèle de classification (format TensorFlow Lite Micro)
- Le code de prétraitement des images
- Les fonctions d’inférence
- Les bibliothèques nécessaires à l’exécution embarquée.
---
 

## 📦 Contenu fourni par Edge Impulse

Lors de l’étape Deploy → Arduino Library, Edge Impulse génère une archive .zip qui contient notamment :

- La bibliothèque Edge Impulse complète
- Un exemple Arduino prêt à l’emploi :
- arduino_camera_classification.ino

Cet exemple constitue le programme principal utilisé pour la classification embarquée des composants électroniques.
---

## ⚙️ Installation dans l’IDE Arduino
Pour utiliser le modèle sur Arduino, les étapes suivantes sont réalisées :

- Télécharger l’archive Arduino Library depuis Edge Impulse.
- Ouvrir l’IDE Arduino.
- Aller dans Sketch → Include Library → Add .ZIP Library….
- Sélectionner l’archive .zip générée par Edge Impulse.

Une fois la bibliothèque installée, l’exemple de classification est automatiquement accessible depuis l’IDE Arduino.
---

## ▶️ Accès à l’exemple
Après l’installation de la bibliothèque, le programme d’inférence est disponible via :
Fichier → Exemples → edge-impulse-project → arduino_camera_classification

Ce fichier est utilisé tel quel comme base pour l’exécution de l’inférence embarquée.
--- 

## 🧪 Utilisation

Ouvrir l’exemple arduino_camera_classification.ino.

Sélectionner la carte Arduino Nano 33 BLE dans l’IDE.

Compiler et téléverser le programme sur la carte.

Ouvrir le moniteur série pour observer les résultats de classification en temps réel.


## Le fichier arduino_camera_classification.ino est généré automatiquement par Edge Impulse lors du déploiement du modèle sous forme de bibliothèque Arduino.
## Pour garantir le bon fonctionnement des dépendances et des chemins d’inclusion, ce fichier est utilisé directement depuis les exemples de la bibliothèque Edge Impulse, sans être déplacé manuellement dans le dépôt du projet. Le dossier 2-ArduinoCamera référence donc ce code et décrit son rôle dans la chaîne d’inférence embarquée.