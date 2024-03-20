/**
 * \file joueuses.h
 *
 * Ce fichier décrit l'ensemble des informations et actions relatives
 * aux joueuses de la partie, accès à leur capital, membre, jouer une carte 
 */ 
/**
 * Partie A2
 */

#ifndef JOUEUSES_H
#define JOUEUSES_H

/** 
 * \brief :structure de joueuse avec un capital, une liste de 5 personnages, une liste de 5 cartes et un tour de jeu 
 *  le tour 0 pour j1, le tour 1 pour j2, le tour 2 pour j_monstre
 */
typedef struct joueuse joueuse;
typedef struct zones map;
typedef struct VueJeu* VueJeu;
#include "cartes.h"
#include "ApplicationWrapper.h"

#define longueur_zone 218
#define hauteur_zone 150
#define longueur_perso 41
#define  hauteur_perso 50
#define debut_zones_hauteur 100
#define debut_zones_longueur 54


/**
 * \brief: cette fonction cree une joueuse qui a 5 de capital, 5 membres et 5 cartes
 * \param tour_de_joueuse : attribue un tour de jeu a une joueuse, le tour 0 pour j1, le tour 1 pour j2, le tour 2 pour j_monstre
 * \return : renvoie une joueuse 
 * \attention : bien gerer la memoire !
 */
joueuse *creer_joueuse(int tour_de_joueuse, map* la_map, Application* app);

/**
 * \brief : la procedure libere la memoire allouée lors de la creation de joueuse 
 */

void free_joueuse(joueuse *player);

/**
 * \brief : la fonction indique la joueuse dont c'est le tour
 * \return : retourne la joueuse dont c'est le tour 
 */
joueuse *tour_de_joueur(joueuse *j1, joueuse *j2,int tour_actuel);

/**
 * \brief : donne la liste des membres d'une joueuse 
 * \return : retourne une liste de membre d'une joueuse ou monstre 
 */
struct personnage *membre_joueur(joueuse *j);

/**
 * \brief : prend un joueur et indique le nb de membre vivant
 * \return : retourne le nombre de membre d'une joueur
 */
int compte_membre_joueur(joueuse *j);

/**
 * \brief : indique si tous les membres d'une ecole d'un joueur ont ete mange
 *  donc si un joueur a perdu ou non
 * \return : retourne 1 si le joueur peut encore jouer , 0 sinon
 */
int as_tu_perdu(joueuse *j);

/**
 * \brief : reinitialise le capital d'une joueuse 
 */ 
void reinitialiser_capital(joueuse *j);

/**
 * \brief : reduit le capital d'une joueuse d'un certain montant 
 */
void utiliser_montant_joueur(joueuse *j,int montant);




/*------------------------------------------------------------------------------
 * tache b5
 */


/**
 * \return: renvoie le capital de la joueuse
*/
int getCapital(joueuse *j); 

/**
 * \return: renvoie la liste des cartes de la joueuse
*/
carte *getMain(joueuse *j);

/**
 * \return: renvoie le tour de joueuse
*/
int getTourdeJoueuse(joueuse *j);

/**
 * \brief: change le capital de la joueuse
*/
void setCapital(int nv_capital, joueuse *j); 

/**
 * \brief: change les cartes de la joueuse
*/
void setMain(carte *nouvelle_main, joueuse *j);

/**
 * \brief: change le tour de la joueuse
*/
void setTourdeJoueuse(int nv_tour, joueuse* j);

/**
 * \brief: change la liste de perso de la joueuse
*/
void setMembresJoueuse(struct personnage* new_list, joueuse* j);

void rendre_visible(joueuse* joueuse_ce_tour);

void rendre_invisible(joueuse* joueuse_adverse);

void handleJoueuseEvent(SFML_EVENTS e, struct VueJeu* vj, Application* app);



#endif /* JOUEUSE_H */
