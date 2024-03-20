# README

## Projet d'informatique effectué par le groupe 3

Description: Vous trouverez dans la branche lot_b du groupe 3 :

- le Makefile,
- le Projet.gan
- le dossier src, contenant tous les fichiers .c
- le dossier headers, contenant tous les fichiers .h
- le dossier obj, contenant tous les fichiers .o
- le dossier bin, contenant tous les executables
- Ce fichier README.md

---

## Compilation des programmes

1. make jeu

   Permet de générer le fichier executable bin/jeu.out contenant le jeu

2. make test

   Permet de générer le fichier executable bin/test.out contenant le test.
   ATTENTION 1 : Cette compilation nécessite d'avoir CUNIT d'installé.
   ATTENTION 2 : Il est parfois demandé à l'utilisateur de rentrer un nombre, les nombres à rentrer sont précisés au dessus de la question.

---

## Execution des programmes

1. ./bin/jeu.out

   Permet d'exécuter le jeu

2. ./bin/prog.out

   Permet d'executer l'ensemble des tests

---

## Mode d'emplois du jeu

La Vie de Markov est un jeu où s'affrontent 2 joueuses qui doivent effectuer différents choix pour
que les membres de leur école survivent

### Histoire

La porte interdimensionnelle entre les univers parallèle n'était pas bien refermée. De terribles monstres se sont échappés et arpentent maintenant notre planète. L'ENSIIE doit maintenant survivre dans un monde où règne la terreur: un seul moyen de survivre, espérer que les autres écoles d'ingénieur se fassent manger avant elle.

### début du jeu :

Au début d'une partie, les 2 joueuses possèdent 5 personnages(des membres) et 5 cartes :

- les personnages de la joueuse 1 sont représentés par des X
- les personnages de la joueuse 2 sont repésentées par des O
- les monstres sont représentés par la lettre M

### Tour de jeu :

Il vous sera d'abord demandé de choisir si vous voulez jouer une carte et si oui laquelle. Sinon, vous possedez à chaque début de tour 5points de capital, vous devez alors choisir combien vous souhaitez en utilisé en tout. Il vous est par la suite possible de découper l'utilisation de ce capital en plusieurs actions.
