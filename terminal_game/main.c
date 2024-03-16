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

int main(){
    srand(time(NULL));
    /* Creation zone , personnages et joueuses*/
    map* la_map =create_map();
    joueuse* joueuse1= creer_joueuse (0, la_map);
    joueuse* joueuse2= creer_joueuse (1, la_map);
    joueuse* monstre= creer_joueuse (2, la_map);

    /*fonction d'affichage début de jeu*/
    lancement_jeu(); 

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


