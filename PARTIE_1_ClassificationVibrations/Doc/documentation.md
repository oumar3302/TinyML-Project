# Documentation Partie 1 – Classification de Vibrations par TinyML

## 1. Introduction

Cette documentation décrit la mise en œuvre complète d’un système TinyML embarqué dédié à la classification de vibrations mécaniques à l’aide d’un microcontrôleur Arduino.

Le projet vise à illustrer une application concrète de l’intelligence artificielle embarquée, depuis la collecte des données jusqu’à l’inférence en temps réel sur cible matérielle.


---
## 2. Génération et acquisition des données

### 2.1 Principe

Les données sont générées à partir de l’accéléromètre embarqué sur l’Arduino Nano 33 BLE Sense.  
Les accélérations selon les axes X, Y et Z sont mesurées en continu et transmises via la liaison série.

Chaque acquisition correspond à un état de vibration bien identifié :
- Absence de vibration
- Vibration moyenne
- Vibration forte

### 2.2 Format des données

Les données sont enregistrées dans des fichiers CSV au format : ax, ay, az, label

où :
- `ax`, `ay`, `az` représentent les accélérations mesurées
- `label` correspond à la classe de vibration

### 2.3 Code Arduino

Le fichier `data_generation.ino` est chargé de :
- Lire les données de l’IMU
- Les transmettre via le port série
- Garantir une fréquence d’échantillonnage stable

Un script Python `collect_data.py` permet ensuite de sauvegarder automatiquement les données reçues dans des fichiers CSV exploitables pour l’entraînement.

---

## 3. Entraînement du modèle de Machine Learning
L’entraînement est réalisé dans le notebook `training_vibrations.ipynb`.


### 3.1 Préparation des données

Les fichiers CSV sont regroupés dans le dossier `dataset/`.  
Ils sont ensuite chargés dans un notebook Jupyter pour :
- Séparer les entrées (ax, ay, az) et les labels
- Normaliser les données si nécessaire
- Diviser le dataset en ensembles d’entraînement et de validation

### 3.2 Modèle utilisé

Un réseau de neurones simple de type **Dense (MLP)** est utilisé, adapté aux contraintes du TinyML :
- Faible nombre de paramètres
- Faible consommation mémoire
- Temps d’inférence réduit

### 3.3 Export du modèle

Une fois entraîné, le modèle est :
- Converti au format TensorFlow Lite (`.tflite`)
- Quantifié afin de réduire l’empreinte mémoire
- Sauvegardé dans le dossier `models/`

---

## 3. Inférence embarquée sur Arduino

### 3.1 Principe de fonctionnement

Le modèle TensorFlow Lite est intégré directement dans le code Arduino sous forme de tableau de bytes.

À chaque itération :
1. Les données de l’accéléromètre sont lues
2. Elles sont injectées dans le modèle
3. Le modèle renvoie des probabilités pour chaque classe
4. La classe la plus probable est sélectionnée

### 3.2 Résultat de l’inférence

La classe prédite est affichée sur le moniteur série sous forme lisible :

- No vibration : `Classe 0`
- Medium vibration : `Classe 1`
- Strong vibration : `Classe 2`

### 3.3 Avantages de l’approche TinyML

- Aucune connexion réseau nécessaire
- Traitement en temps réel
- Faible consommation énergétique
- Protection des données (traitement local)

---
## 4. Résultats attendus

Le système doit être capable de :
- Reconnaître correctement le niveau de vibration
- Fonctionner en temps réel
- Respecter les contraintes mémoire et de calcul du microcontrôleur

---

## 5. Conclusion

Ce projet démontre la faisabilité et l’intérêt de l’intelligence artificielle embarquée pour des applications de détection et de classification de signaux physiques.

La méthodologie employée est générique et peut être facilement adaptée à d’autres types de capteurs ou d’applications industrielles telles que :
- Surveillance de machines
- Maintenance prédictive
- Détection d’anomalies vibratoires

---

## 6. Perspectives d’amélioration

- Ajout de fenêtres temporelles (features temporelles)
- Amélioration du dataset
- Comparaison avec d’autres architectures de modèles
- Intégration d’un affichage ou d’une alerte visuelle
