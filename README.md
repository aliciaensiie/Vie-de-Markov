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

## Bibliotheque
Elle fonctionne sur linux.
Pour installer la librairie, référer vous au README contenu dans le dossier CSFML.

## Compilation des programmes
1. Faire la commande ```export LD_LIBRARY_PATH=./CSFML/SFML-2.5.1/lib``` si elle n'a pas été faite précedemment

2. make 

   Permet de générer le fichier executable bin/jeu.out contenant le jeu

ATTENTION: Les Warnings "incomptible pointer types" sont normaux et ne sont pas des erreurs ou des oublis puisqu'ils sont à cause du principe d'héritage C++ qu'il n'y a pas en C.



---

## Execution des programmes

1. ./bin/jeu.out

   Permet d'exécuter le jeu

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

Il vous sera d'abord demandé de choisir si vous voulez jouer une carte et si oui laquelle. Sinon, vous possedez à chaque début de tour 5points de capital, vous devez alors choisir combien vous souhaitez en utilisé en tout. Il vous est par la suite possible de découper l'utilisation de ce capital en plusieurs actions. Ces points de capital vous permettent de modifier la probabilite de se déplacer d'une case à une autre. Pour 1 point de capital, la probabilité sera change de 0.1. 

Lorsqu'une personne a joué, la carte choisie ou les probabilités changées s'appliquent et les personnes et le/les monstre(s) bougent. Les personnes se trouvant sur la meme case qu'un monstre sont mangés. Le jeu s'arrete lorsque qu'un joueur n'a plus de personnage. 
