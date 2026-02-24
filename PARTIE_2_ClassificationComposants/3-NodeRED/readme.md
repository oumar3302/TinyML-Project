Envoi des résultats à Node-RED et comptage des composants

# 🎯 Objectif
Cette partie du projet vise à exploiter les résultats de classification fournis par l’Arduino afin de réaliser un comptage des composants électroniques détectés.
La communication entre l’Arduino et l’interface de visualisation est assurée par Node-RED, via le port série USB.
---

# 🧠 Principe de fonctionnement
Le système repose sur une architecture événementielle simple :

L’Arduino Nano 33 BLE exécute le modèle de classification déployé depuis Edge Impulse.

À chaque inférence, la classe prédite (par exemple led, resistor, capacitor) est envoyée via le port série.

Node-RED reçoit cette information, l’analyse et l’utilise pour incrémenter un compteur spécifique à chaque classe.

Les compteurs sont affichés en temps réel sur un tableau de bord web.
---

# 🔌 Communication Arduino – Node-RED
Type de communication : Port série USB

Vitesse de transmission : 115200 bauds

Format des données : Chaîne de caractères (une classe par ligne)

Exemple de donnée reçue : capacitor

Un prétraitement est appliqué dans Node-RED afin de supprimer les caractères de fin de ligne et garantir un traitement fiable.
---

# 🔄 Structure du flow Node-RED
Le flow Node-RED est composé des éléments suivants :
- Serial In
- Réception des données envoyées par l’Arduino.
- Function (clean_payload)
- Nettoyage de la chaîne reçue (suppression des caractères invisibles).
- Switch
- Tri de la donnée en fonction de la classe détectée.
- Function (compteurs)
- Incrémentation d’un compteur spécifique à chaque type de composant.
- Dashboard (Numeric)

Affichage des compteurs sur une interface web.
---

# 📊 Tableau de bord

Le tableau de bord Node-RED affiche un compteur par classe de composant :
- LED
- Résistance
- Condensateur

Il est accessible à l’adresse suivante lorsque Node-RED est lancé : http://127.0.0.1:1880/#flow/0582163ec68a0ba1

le lien du dashboard: http://localhost:1880/ui
---

# 📁 Contenu du dossier

```text
3-NodeRED/
│
├── flows.json   # Flow Node-RED exporté
└── README.md    # Documentation de la partie Node-RED
└── dashboard

```

Le fichier flows.json contient l’ensemble des nœuds nécessaires au fonctionnement du système et permet de recharger le flow dans un autre environnement Node-RED.

