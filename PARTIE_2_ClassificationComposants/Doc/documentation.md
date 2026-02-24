# Documentation – Classification et comptage de composants électroniques

## 1. Introduction

Cette documentation décrit la mise en œuvre complète d’un système de classification d’images embarqué utilisant Edge Impulse, une caméra OV7675 et un microcontrôleur Arduino Nano 33 BLE.

L’objectif est de reconnaître automatiquement des composants électroniques et de transmettre les résultats à une interface Node-RED pour le comptage et la visualisation.
---

## 2. Projet Edge Impulse

### 2.1 Création du projet

Un projet est créé sur la plateforme Edge Impulse afin de :
- Capturer des images des composants électroniques
- Étiqueter les images selon le type de composant
- Définir un pipeline d’entraînement adapté

La collecte des données est réalisée directement via Edge Impulse, sans importation externe d’images.
Le lien vers le projet est fourni dans : EdgeImpulse/link_to_edge_impulse.md

---

### 2.2 Dataset et étiquetage

Les images sont collectées directement via l’onglet Data Acquisition de Edge Impulse en utilisant la caméra OV7675 connectée à l’Arduino Nano 33 BLE.

Chaque image est capturée en temps réel depuis la caméra, puis immédiatement étiquetée manuellement avec l’une des classes suivantes :
- led
- resistor
- capacitor

Les données sont automatiquement stockées dans le projet Edge Impulse et réparties entre ensemble d’entraînement et ensemble de test.

---

### 2.3 Entraînement du modèle

L’entraînement est effectué directement sur Edge Impulse :
- Création de l’impulse
- Choix du type de modèle (classification d’images)
- Entraînement et validation
- Tests de performance

Aucun notebook local n’est requis pour cette partie.

---

## 3. Déploiement sur Arduino

### 3.1 Génération du code embarqué

Une fois le modèle validé :
- Edge Impulse génère automatiquement le code C++ compatible Arduino
- Le code est intégré dans le sketch Arduino

---

### 3.2 Capture et inférence

Le code Arduino permet :
1. L’initialisation de la caméra OV7675
2. La capture d’une image
3. Le prétraitement défini par Edge Impulse
4. L’inférence embarquée
5. La récupération de la classe prédite
---

## 4. Communication avec Node-RED

### 4.1 Transmission des données

Les résultats de classification sont transmis via la liaison série USB (UART) vers Node-RED.

Chaque message contient uniquement le label de la classe prédite.
---

### 4.2 Node-RED Dashboard

Dans le dossier `3-NodeRED` :
- Le fichier `flows.json` contient l’export du flow Node-RED
- Le flow permet :
  - De recevoir les données
  - D’incrémenter un compteur par type de composant
  - D’afficher les résultats sur un tableau de bord graphique

---

## 5. Résultats attendus

Le système doit être capable de :
- Reconnaître correctement les composants
- Compter chaque type de composant détecté
- Mettre à jour le tableau de bord en temps réel

---

## 6. Conclusion

Cette partie démontre l’efficacité des solutions TinyML basées sur l’analyse d’images pour des applications industrielles telles que le tri, le contrôle qualité ou l’inventaire automatisé.

L’utilisation d’Edge Impulse permet une mise en œuvre rapide et structurée de modèles de vision embarquée.
La collecte directe des données via la caméra embarquée renforce la cohérence entre le dataset et les conditions réelles d’utilisation.