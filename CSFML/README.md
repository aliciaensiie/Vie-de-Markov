# C'est quoi la lib ?

Cette librairie statique a pour but de pouvoir utiliser une version simplifier et plus abstraite de la librairie
graphique SFML en C. Elle est disponible que via des système sous linux ou sur des machines virtuels tournant sous linux
(ce n'est pas garantie que ça marche sous wsl).
Vu que SFML est initialement en C++, le linker de g++ est quand même nécessaire mais la compilation peut totalement
se faire avec gcc et un fichier C.

Pour voir la doc, il suffit de faire 
```bash
make doc
```
dans le répertoire où se trouve ce readme.
(note: ça part du principe que vous avez firefox, sinon modifier la ligne du make doc pour include votre navigateur de recherche)

# Comment build la lib sous linux

Il faut avoir g++ d'installer au préalable.
mettez vous dans le répertoire où se trouve ce readme et rentrer la commande `make lib`.

# Comment utiliser la lib sous linux 

Il faut avoir gcc ET g++ d'installer pour générer l'éxécutable de votre fichier '.c'.
L'exemple de makefile est donné via le fichier `Makefile` qui se situe dans le même répertoire 
que ce README.
Lors de l'éxécution, il faut linker dynamiquement sfml, et donc il suffit de rentrer cette commande:
```bash
export LD_LIBRARY_PATH=<path_to_csfmllib>/SFML-2.5.1/lib
``` 
Où `<path_to_csfmllib>` doit être complètement remplacé par le chemin vers le dossier où se trouve ce readme.

# NOTE

C'est possible que votre version de linux n'accepte pas sfml
car vous avez un des paquets suivants manquants (auquel cas il faut 
les installer) :
- freetype
- x11
- xrandr
- udev
- opengl
- flac
- ogg
- vorbis
- vorbisenc
- vorbisfile
- openal
- pthread
