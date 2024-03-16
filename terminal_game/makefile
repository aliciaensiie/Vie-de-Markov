SRCD =src
HDRD =headers
OBJD =obj
BIND =bin

CC=gcc
CFLAGS= -std=c99 -Wall -g -Wextra -I$(HDRD)

PROJET_O= interface.o structures.o cartes.o zones.o joueuses.o personnages.o main.o effets.o
TEST_O=interface.o structures.o cartes.o zones.o joueuses.o personnages.o test.o effets.o

jeu: jeu.out


jeu.out: $(addprefix $(OBJD)/, $(PROJET_O))
	$(CC) -std=c99 $^ -o $(BIND)/$@

$(OBJD)/%.o: $(SRCD)/%.c $(HDRD)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

obj/main.o: src/main.c headers/cartes.h headers/interface.h headers/joueuses.h headers/personnages.h headers/structures.h headers/zones.h headers/effets.h
	gcc -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJD)/*.o all

run: jeu.out
	./$(BIND)/jeu.out


test: prog.out

prog.out: $(addprefix $(OBJD)/, $(TEST_O))
	$(CC) -std=c99 -o $(BIND)/$@ $^ -lcunit


obj/test.o: src/test.c headers/cartes.h headers/interface.h headers/joueuses.h headers/personnages.h headers/structures.h headers/zones.h
	gcc -c $(CFLAGS) $< -o $@