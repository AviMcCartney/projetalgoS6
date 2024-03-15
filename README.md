# Contenu du Projet

## src

Ce répertoire contient le code source de l'application.

- `main.c` : Fichier principal contenant le menu interactif.
- `rule.c` : Fichier contenant les opérations à effectuer sur les règles.
- `fact.c` : Fichier contenant les opérations à effectuer sur les faits.
- `parse.c` : Fichier contenant la fonction pour parser les données.
- `forward_chaining.c` : Fichier contenant la fonction pour le chaînage avant.
- `backward_chaining.c` : Fichier contenant la fonction pour le chaînage arrière.

## include

Ce répertoire contient les fichiers d'en-tête.

- `rule.h` : Définition de la structure Rule.
- `fact.h` : Définition de la structure Fact.

## kbs

Ce répertoire contient les fichiers .kbs utilisés pour les tests.

## Documentation

Ce répertoire contient la documentation du projet.

## build

Ce répertoire contient les fichiers générés lors de la compilation.

# Compilation et Exécution

1. Cloner le dépôt
2. Lancer la commande `make clean && make run` dans votre terminal en étant à la racine du projet

# Exemple d'Utilisation

1. Sélectionnez l'option dans le menu interactif.
2. Suivez les instructions pour fournir les fichiers .kbs nécessaires.
3. Obtenez les résultats dans votre terminal.

# Gestion du Projet

## Création d'un GitHub

Pour nous organiser, nous avons mis en place un dépôt GitHub dans lequel nous avons chacun notre « branche » afin de pouvoir travailler de manière indépendante sur le projet. Nous pouvions donc suivre les avancements de chacun, et avancer en autonomie.

## Déroulement du Projet

### Compréhension du Sujet, des Exigences, et du Format .kbs

Nous avons dans un premier temps commencé à travailler sur la compréhension de la logique derrière les systèmes experts. Ensuite, il a fallu qu'on comprenne les principes de chaînage avant / arrière pour qu'on arrive à saisir ses subtilités et coder en C. On a aussi beaucoup bloqué pour récupérer et stocker les règles à partir d'un fichier .kbs.

### Blocage

Nous nous sommes rendus compte au cours de notre projet que notre approche n'était pas optimale. En effet, nos fonctions géraient beaucoup de choses en même temps. Par exemple, notre fonction qui convertissait les .kbs en règles et faits s'occupait à la fois :

- de l'ouverture des fichiers
- de la gestion de la mémoire
- de la conversion des données
- du calcul et de l'écriture des données dans les structures

Suite à ces problèmes, nous avons décidés de repartir du début pour repartir sur une base plus adaptée. Nous avons essayé de séparer le plus possible le code en plusieurs fonctions pour éviter les erreurs et les répétitions.

Nous avons dû revoir notre façon de manipuler les données .kbs, de les stocker en mémoire et de les traiter. Malgré ces difficultés, nous avons réussi à implémenter toutes les fonctionnalités demandées et à respecter les normes de codage.
