# School Battle Game

## 2 Versions
L'application est disponible sur Windows et Linux. Pour chaque OS, la version classique du jeu utilise une librairie graphique mais il existe également une version terminal pour jouer, comme son nom l'indique, dans le terminal. 

## Description
School Battle est un jeu où s'affrontent 2 joueuses qui doivent effectuer différents choix pour
que les membres de leur école survivent

### Histoire

La porte interdimensionnelle entre les univers parallèle n'était pas bien refermée. De terribles monstres se sont échappés et arpentent maintenant notre planète. L'ENSIIE doit maintenant survivre dans un monde où règne la terreur: un seul moyen de survivre, espérer que les autres écoles d'ingénieur se fassent manger avant elle.

### Début du jeu :

Au début d'une partie, les 2 joueuses possèdent 5 personnages(des membres) et 5 cartes :

- les personnages de la joueuse 1 sont représentés par des X
- les personnages de la joueuse 2 sont repésentées par des O
- les monstres sont représentés par la lettre M

### Tour de jeu :

Il vous sera d'abord demandé de choisir si vous voulez jouer une carte et si oui laquelle. Sinon, vous possedez à chaque début de tour 5points de capital, vous devez alors choisir combien vous souhaitez en utilisé en tout. Il vous est par la suite possible de découper l'utilisation de ce capital en plusieurs actions. Ces points de capital vous permettent de modifier la probabilite de se déplacer d'une case à une autre. Pour 1 point de capital, la probabilité sera change de 0.1. 

Lorsqu'une personne a joué, la carte choisie ou les probabilités changées s'appliquent et les personnes et le/les monstre(s) bougent. Les personnes se trouvant sur la meme case qu'un monstre sont mangés. Le jeu s'arrete lorsque qu'un joueur n'a plus de personnage. 


## Bibliotheque
La version basique du jeu utilise les librairies SFML et CSFML, adaptation en C de la librairie SFML.

## Utilisation
Premiérement, tu auras besoin d'installer SFML (version 2.5 pour Linux, version 2.6 pour Windows) ainsi que CMake. Tu dois alors changer le chemin de la librarie SFML dans le CMakeLists du dossier window (ligne 6 pour Linux et ligne 8 pour Windows).

Il existe 3 sous-dossiers: window pour la version graphique, terminal pour la version qui se joue dans le terminal et CSFML qui contient la librairie CSFML.
Window et terminal contiennent chacun leur CMakeLists à compiler et construire dans un dossier build. 

Les commandes pour compiler et construire sont: 
<pre>
    cmake ..
    cmake --build .
</pre>
Tu peux alors trouver l'éxécutable dans le dossier build.

ATTENTION: Les Warnings "incomptible pointer types" sont normaux et ne sont pas des erreurs ou des oublis puisqu'ils sont à cause du principe d'héritage C++ qu'il n'y a pas en C.


## Authors
FISCUS Felicien: librairie CSFML


LEFEE FAUVEL Loic: programme du jeu en C en groupe


KOUDIRATY Mohamed: programme du jeu en C en groupe  <br /><br />




PLATH alicia:  
- programme du jeu en C en groupe, 
- librairie dynamique de CSFML pour linux et librairie dynamique et static de CSFML pour Windows,               
- 2 versions d'application du jeu pour Windows/Linux
