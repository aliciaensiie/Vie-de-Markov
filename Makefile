########################################################
# ----------------------------------------------------------------------------------
# |																				   |
# | Exemple de makefile pour compiler un fichier C qui utilise la librairie csfml. |
# |						(Pour ma chérie d'amour <3)								   | 																			   |
# ----------------------------------------------------------------------------------


SRCD=src
HDRD=headers
OBJD=obj
BIND=bin

PROJET_O=VueJeu.o structures.o cartes.o zones.o joueuses.o personnages.o main.o effets.o

#nom de l'éxécutable
TARGET=jeu.out
#pour inclure la librairie statique dans la compilation
LIB=./CSFML/lib
#pour in clude la librairie sfml dans la compilation
LIBSFML=./CSFML/SFML-2.5.1/lib
#pour pouvoir faire des #include "ApplicationWrapper.h" par exemple
INCLUDE=./CSFML/include/
#compilateur C
CC=gcc
#linker C++
PP=g++
#ce que vous voulez (attention il y a des warnings vis à vis de Utility.h mais c'est normal, n'y tenez pas compte)
CFLAGS=-Wall -Wextra -std=c99 -g
#flags pour le linker vis-à-vis de sfml
LFLAGS_sfml=-lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio
#flags pour le linker vis-à-vis de csfml
LFLAGS_Csfml=-lm -lcsfml-f

$(BIND)/$(TARGET): $(addprefix $(OBJD)/, $(PROJET_O))
	$(PP) $^ -o $@ -L"$(LIB)" -L"$(LIBSFML)" $(LFLAGS_Csfml) $(LFLAGS_sfml)

$(OBJD)/%.o: $(SRCD)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I"$(INCLUDE)"

clean:
	rm -f example_exec $(FILE_OBJ)
