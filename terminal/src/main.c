#include "../headers/interface.h"
#include "../headers/cartes.h"
#include "../headers/joueuses.h"
#include "../headers/personnages.h"
#include "../headers/zones.h"
#include "../headers/structures.h"
#include "../headers/effets.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FIFO_FILE "/tmp/my_fifo"

#ifndef OPEN_TERMINAL
    #define OPEN_TERMINAL "gnome-terminal --geometry=125x40 -- bash -c 'cat /tmp/my_fifo; read'"
#endif

void rules() {
    // Créer le tube nommé ("named pipe")
    mkfifo(FIFO_FILE, 0666);

    //open a new terminal, wrote the contents of my_fifo in there and wait for user to write something and press ENTER.
    system(OPEN_TERMINAL);


    // Écrire dans le tube nommé
    int fd = open(FIFO_FILE, O_WRONLY);
    if (fd == -1) {
        perror("Failed to open FIFO");
    }
    char message[] = "\033[36;01mOUVRE LA FENETRE DU JEU EN PLEINE ECRAN\n\n\nRegle Du Jeu:\033[00m\n\nLa Vie de Markov est un jeu ou s'affrontent 2 joueuses qui doivent effectuer differents choix \npour que les membres de leur ecole survivent.\n\nAu debut d'une partie, les 2 joueuses possedent 5 personnages(des membres) et 5 cartes :\n- les personnages de la joueuse 1 sont representes par des X\n- les personnages de la joueuse 2 sont repesentees par des O\n- les monstres sont representes par la lettre M\n\nA chaque tour, il vous sera d'abord demande de choisir si vous voulez jouer une carte et si oui \nlaquelle. Sinon, vous possedez a chaque debut de tour 5 points de capital, vous devez alors choisir \ncombien vous souhaitez en utilise en tout. Il vous est par la suite possible de decouper l'utilisation \nde ce capital en plusieurs actions. Ces points de capital vous permettent de modifier la probabilite \nde se deplacer d'une case a une autre. Pour 1 point de capital, la probabilite sera change de 0.1.\n\nEtape pour changer la probabilite :\n1. Choisir le nombre capital que tu souhaites utiliser\n2. Choisir la zone 1 a partir de laquelle les probabilites changent\n3. Choisir une zone 2 afin que la probabilite d'aller de la zone 1 vers la zone 2 augmente \n4. Choisir une zone 3 afin que la probabilite d'aller de la zone 1 vers la zone 3 diminue\n\nLorsqu'une personne a joue, la carte choisie ou les probabilites changees s'appliquent et les personnes \net le/les monstre(s) bougent. Les personnes se trouvant sur la meme case qu'un monstre sont manges. \nLe jeu s'arrete lorsque qu'un joueur n'a plus de personnage.\n\n\n\033[36;01mPress ENTER to close this terminal\033[00m\n";
    write(fd, message, sizeof(message));

    close(fd);
    unlink(FIFO_FILE); // Supprimer le tube nommé après utilisation
}


int main(){
    srand(time(NULL));
    /* Creation zone , personnages et joueuses*/
    map* la_map =create_map();
    joueuse* joueuse1= creer_joueuse (0, la_map);
    joueuse* joueuse2= creer_joueuse (1, la_map);
    joueuse* monstre= creer_joueuse (2, la_map);

    /*fonction d'affichage début de jeu*/
    lancement_jeu(); 

    rules();

    /* Creation des variables */
    int carte_ou_pas; 
    int continuer;
    int numero_tour=0;

    /*Tous les tours */
    while (as_tu_perdu(joueuse1) && as_tu_perdu(joueuse2)){
        joueuse* joueuse_ce_tour = tour_de_joueur(joueuse1, joueuse2, numero_tour); 

        /* Verifie si les cartes activées empêchent de continuer le tour */
        continuer = activate_carte(joueuse_ce_tour, monstre);

        /*Si on peut*/
        if (continuer ==0){

            /* Afiichage des infos */
            affichage_info(joueuse_ce_tour, la_map);

            /* Demande si la joueuse veut jouer une carte et si oui, renvoie laquelle*/
            carte_ou_pas = demande_carte(); 
            
            /*Si elle ne veut pas jouer de cartes */
            if (carte_ou_pas==0){
                
                /* Demande ce qu'elle veut changer et change probas + capital*/
                utilisation_capital(joueuse_ce_tour, la_map);
                
                /* Bouge les personnages*/
                move_les_personnages(membre_joueur(joueuse1),membre_joueur(joueuse2),membre_joueur(monstre),la_map, joueuse_ce_tour); 

                /* Tue les personnages qui doivent être tués*/
                manger_les_persos(joueuse1, joueuse2,membre_joueur(monstre));

                /*Affiche le nombre de personnes en vie pour chaque joueuse*/
                nb_en_vie(compte_membre_joueur(joueuse1), compte_membre_joueur(joueuse2));

                reinitialiser_capital(joueuse_ce_tour);
            }
            else{
                jouer_une_carte(joueuse1, joueuse2, monstre, numero_tour, la_map, carte_ou_pas); 
            }   
        }
        numero_tour= numero_tour +1;
        fin_tour();
    }
    /*Affichage fin du jeu*/
    fin_jeu(joueuse1, joueuse2);

    /*Libère la mémoire allouée*/
    free_joueuse(joueuse1); 
    free_joueuse(joueuse2);
    free_joueuse(monstre);
    return 0;
}


