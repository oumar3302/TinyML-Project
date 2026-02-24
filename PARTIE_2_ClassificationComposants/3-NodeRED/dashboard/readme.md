📊 Dashboard Node-RED

# 🎯 Objectif
Le dashboard Node-RED permet de visualiser en temps réel le nombre de composants électroniques détectés par le système de classification embarqué.

Il constitue l’interface utilisateur finale du projet.

# 🧱 Structure du dashboard
Le dashboard est composé d’un onglet principal : Classification composants
Cet onglet contient un groupe nommé : Compteurs
Dans ce groupe, plusieurs widgets numériques affichent les compteurs associés à chaque classe :
- LED
- Résistance
- Condensateur
Aperçu: ![alt text](dashboard_screenshot.png)

# 🔄 Mise à jour des données
Chaque widget est mis à jour automatiquement à chaque nouvelle détection transmise par l’Arduino via le port série.
Les valeurs affichées correspondent au nombre total de détections par classe depuis le lancement du système.
Aperçu: ![alt text](dashboard_screenshot1.png)

# 🛠️ Implémentation
Le dashboard est implémenté à l’aide des nœuds ui_numeric fournis par le module Node-RED Dashboard.
La configuration complète du dashboard (onglets, groupes et widgets) est incluse dans le fichier flows.json.
Aperçu: ![alt text](figure-node-red.png)

# 📌 Remarque
Aucun fichier de configuration supplémentaire n’est nécessaire pour le dashboard.
L’importation du fichier flows.json dans Node-RED suffit à recréer automatiquement l’interface utilisateur.

## NB: Le tableau de bord Node-RED est intégré directement dans le flow et sauvegardé dans le fichier flows.json. Le dossier dashboard contient une description de l’interface ainsi qu’une capture illustrant la visualisation des compteurs.