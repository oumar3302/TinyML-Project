# Partie 2 – Classification et comptage de composants électroniques (Edge Impulse)

## 1. Présentation

Cette partie du projet TinyML vise à mettre en œuvre un système de **reconnaissance visuelle embarquée** permettant d’identifier et de compter différents composants électroniques à l’aide d’une caméra et d’un microcontrôleur.

Contrairement à la Partie 1, l’entraînement du modèle est réalisé **entièrement sur la plateforme Edge Impulse**, sans notebook local.
Les images utilisées pour l’entraînement sont collectées directement via l’onglet Data Acquisition de Edge Impulse à l’aide de la caméra connectée à l’Arduino.
---

## 2. Objectifs de la partie

Les objectifs sont les suivants :

1. Capturer des images de composants électroniques à l’aide d’une caméra
2. Entraîner un modèle de classification d’images avec Edge Impulse
3. Déployer le modèle sur un Arduino Nano 33 BLE
4. Effectuer l’inférence embarquée en temps réel
5. Transmettre les résultats à Node-RED
6. Compter et afficher les composants détectés sur un tableau de bord

---

## 3. Composants reconnus

Les composants utilisées pour les données de l'entrainement et à classifier sont :

- LED
- Résistances
- Condensateurs

---

## 4. Matériel et outils utilisés

### Matériel
- Arduino Nano 33 BLE Sense
- Caméra OV7675

### Logiciels et plateformes
- Edge Impulse
- Arduino IDE
- Node-RED
- Communication série USB (UART)

---

## 5. Structure de la partie
PARTIE_2_ClassificationComposants/
│
├── README.md
│
├── 1-EdgeImpulse/
│ ├── link_to_edge_impulse.md
│ └── instructions.md
│
├── 2-ArduinoCamera/
│ └── arduino_camera_classification.ino
│
├── 3-NodeRED/
│ ├── flows.json
│ └── dashboard/
│
└── doc/
│ ├── documentation.md
│ └── results.md
│
└── documentation.md
---

## 6. Étape 1 – Projet Edge Impulse

Dans le dossier `1-EdgeImpulse` :
- Le fichier `link_to_edge_impulse.md` contient l’URL du projet Edge Impulse
- Le fichier `instructions.md` décrit toutes les étapes pour reproduire le projet (dataset, entraînement, tests)

---

## 7. Étape 2 – Inférence embarquée avec caméra

Le dossier `2-ArduinoCamera` contient le code Arduino permettant :
- D’initialiser la caméra OV7670
- De capturer les images
- D’exécuter le modèle Edge Impulse embarqué
- D’obtenir la classe prédite pour chaque image

---

## 8. Étape 3 – Communication avec Node-RED

Les résultats de classification sont transmis à Node-RED :
- Via la liaison série USB (UART)
- - Sous forme de labels correspondant à la classe prédite

Node-RED se charge ensuite :
- D’incrémenter un compteur par type de composant
- D’afficher les résultats sur un tableau de bord

---

## 9. Conclusion

Cette partie met en évidence l’utilisation de plateformes spécialisées comme Edge Impulse pour le développement rapide de solutions TinyML basées sur l’analyse d’images, intégrant inférence embarquée et visualisation temps réel.

