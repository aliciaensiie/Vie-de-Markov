/**
* \files : interface.h 
* Ce fichier décrit l'ensemble des fonctions qui permettent d'echanger les informations avec les joueuses*/

#ifndef INTERFACE_H
#define INTERFACE_H
#include "joueuses.h"
#include "zones.h"

/**
 * \brief: Cette fonction affiche les informations du jeu
 */
void affichage_info(joueuse* joueuse, map* la_map);


/**
 * \brief: demande à la joueuse combien de capital elle veut utiliser, puis modifie son capital et la matrice des probas en fonctions des changements
 * \attention: la joueuse ne peut dépenser plus de capital que ce qu'elle a déjà
 */
void utilisation_capital(joueuse * joueuse_ce_tour, map* la_map);


/**
 *\brief: Cette fonction demande à la joueuse si elle veut jouer une carte durant ce tour 
 *\return:Cette fonction renvoie 0 si la joueuse ne veut pas jouer de carte, le numéro de la carte sinon
 *\attention:Pensez à verifier que la joueuse est bien en possession de la carte 
 */
int demande_carte();

/**
 *\brief: Cette fonction prévient la joueuse qu'elle s'est trompé en donnant le numero de la carte, demande de lui en donner un autre
 *\return: Cette fonction renvoie le numero de la nouvelle carte choisie
 */
int redemande_carte();

/**
 *\brief: Cette fonction prévient la joueuse qu'elle s'est trompé, qu'elle n'a plus de carte
 */
void  plus_de_carte();


/**
 *\brief: Cette fonction affiche le message de fin de jeu
 */
void fin_jeu(joueuse* j1, joueuse* j2);


/**
 *\brief:Cette fonction affiche le nombre de personnes encore en vie  pour chaque joueuse à la fin d'un tour 
 *\param nb_j1: Nombre de personnes encore en vie du joueur 1
 *\param nb_j2: Nombre de personnes encore en vie du joueur 2
 */
void nb_en_vie(int nb_j1, int nb_j2);


/**
 *\brief: Cette fonction affiche un dessin de lancement de jeu 
 */
void lancement_jeu();
 
// Pour les cartes 
/**
 * \brief: cette fonction demande aux joueurs sur quelle zone elle veut deplacer le monstre(Anne-Laure Ligozat) 
 * \return : renvoie un entier correspondant aux numéros de la zone 
 */
int deplacement_montre();



/**
 * \brief: Cette fonction demande aux joueurs quel perso elle veut déplacer
 * \return: le numero de la zone sur laquelle le perso est
 */
int choix_perso();


/**
 * \brief: Cette fonction demande aux joueurs quel perso adverse elle veut déplacer
 * \return: le numero de la zone sur laquelle le perso est
 */
int choix_perso_adverse();

/**
* \brief: Cette fonction demande à la joueuse de choisir une zone
* \return: Le numéro de la zone choisie
*/
int choix_zone();

/**
 * \brief: Cette fonction demande aux joueurs quel monstre elle veut déplacer
 * \return: le numero de la zone sur laquelle le perso est
 */
int choix_monstre();


/**
 * \brief: Cette fonction demande à la joueuse si elle veut voir ses cartes et si oui les affiche 
 */
void affichage_cartes(joueuse* joueuse_ce_tour);

/**
 * \brief: Cette fonction montre que c'est la fin du tour 
 */
void fin_tour();


#endif /* INTERFACE_H */