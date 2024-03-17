# Contenu du Projet

## src

Ce répertoire contient le code source de l’application.

- `main.c` : Fichier principal contenant le menu interactif.
- `lecture.c` : Fichier contenant les fonctions pour la lecture des fichiers.
- `memoire.c` : Fichier contenant les fonctions pour la gestion de la mémoire.
- `fait.c` : Fichier contenant les opérations à effectuer sur les faits.
- `caractere.c` : Fichier contenant les opérations à effectuer sur les caractères.
- `chainage_avant.c` : Fichier contenant la fonction pour le chaînage avant.
- `chainage_arriere.c` : Fichier contenant la fonction pour le chaînage arrière.
- `menu.c` : Fichier contenant contenant la procédure pour créer le menu.

## include

Ce répertoire contient les fichiers d’en-tête.

- `lecture.h` : Définition des fonctions pour la lecture des fichiers.
- `memoire.h` : Définition des fonctions pour la gestion de la mémoire.
- `fait.h` : Définition de la structure Faits et des fonctions associées.
- `caractere.h` : Définition des fonctions pour la manipulation des caractères.
- `chainage_avant.h` : Définition de la fonction pour le chaînage avant.
- `chainage_arriere.h` : Définition de la fonction pour le chaînage arrière.
- `menu.h` : Définition de la fonction pour le menu.

## kbs

Ce répertoire contient les fichiers .kbs utilisés pour les tests, incluant une base de données représentant le cryptage que nous avons choisi comme sujet pour expérimenter les différents chainages (avant et arriere).

## Documentation

Ce répertoire contient la documentation du projet.

## build

Ce répertoire contient les fichiers générés lors de la compilation.

## Compilation et Exécution

1. Cloner le dépôt.
2. Lancer la commande `make clean && make run` dans votre terminal en étant à la racine du projet.

## Exemple d’Utilisation

1. Sélectionnez l’option dans le menu interactif.
2. Suivez les instructions pour fournir les fichiers .kbs nécessaires.
3. Obtenez les résultats dans votre terminal.

## Gestion du Projet

### Création d’un GitHub

Pour nous organiser, nous avons mis en place un dépôt GitHub dans lequel nous avons chacun notre « branche » afin de pouvoir travailler de manière indépendante sur le projet. Nous pouvions donc suivre les avancements de chacun, et avancer en autonomie.

### Déroulement du Projet

1. **Compréhension du Sujet, des Exigences, et du Format .kbs:** Nous avons dans un premier temps commencé à travailler sur la compréhension de la logique derrière les systèmes experts. Ensuite, il a fallu qu’on comprenne les principes de chaînage avant / arrière pour qu’on arrive à saisir ses subtilités et coder en C. On a aussi beaucoup bloqué pour récupérer et stocker les règles à partir d’un fichier .kbs.

2. **Blocage:** Nous nous sommes rendus compte au cours de notre projet que notre approche n’était pas optimale. En effet, nos fonctions géraient beaucoup de choses en même temps. Par exemple, notre fonction qui convertissait les .kbs en règles et faits s’occupait à la fois :

   - de l’ouverture des fichiers
   - de la gestion de la mémoire
   - de la conversion des données
   - du calcul et de l’écriture des données dans les structures

   Suite à ces problèmes, nous avons décidé de repartir du début pour repartir sur une base plus adaptée. Nous avons essayé de séparer le plus possible le code en plusieurs fonctions pour éviter les erreurs et les répétitions.

3. **Répartition des Tâches:** Nous avons travaillé en binôme pour diviser les tâches et travailler de manière plus efficace. Alexandre et Tom se sont occupés des fonctions de lecture, de gestion de la mémoire, des faits et des caractères. Yanis et Charlotte ont travaillé sur les chaînages avant et arrière. Cette répartition nous a permis de travailler de manière plus organisée et de progresser plus rapidement.

4. **Finalisation:** Nous avons recommencé plusieurs fois avant d’obtenir une version stable de notre projet. Chaque fois, nous avons appris de nos erreurs et amélioré notre code.

Merci de votre attention et bonne utilisation de notre système expert !
