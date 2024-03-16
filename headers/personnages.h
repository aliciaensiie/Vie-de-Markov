/**
 * \file personnages.h 
 *
 * Ce fichier decrit les informations et actions relatives aux
 * monstres et aux membres d'école.
 */
/**
 * Taches A3
 */
#ifndef PERSONNAGES_H
#define PERSONNAGES_H

/**
 * \brief : un personnage est soit mort ou vivant (0,1) soit un membre d'ecole
 * ou un monstre(0,1) est sur une zone, appartient a une joueuse (proprietaire) et a peut etre recu des pouvoirs a cause des effets d'une carte
 */
typedef struct personnage personnage;

enum etat_perso {vivant,mort};

#include "zones.h"
#include "joueuses.h"
#include "ApplicationWrapper.h"

/**
 * \brief : fonction qui creer un personnage de type membre ou monstre 
 * \param type : membre 0, monstre 1 
 * \param tour_de_joueuse : identifie si c'est j1, j2 ou j_monstre
 * \return : un pointeur vers un nouveau personnage et alloue la mémoire
 */
personnage *creer_personnage(int tour_de_joueuse, map* la_map, Application* app);

/**
 * \brief : libere la mémoire allouée à la création du personnage 
 */
void free_personnage(personnage *p);

/**
 * \brief : regarde si un personnage est vivant, si oui le deplace un personnage
 * dans une zone donnée
 * \param la_map : la map sur laquelle on se trouve avec les probas
 */
void move_personnage(personnage *p,map *la_map);

/**
 *\brief: Cette fonction a pour but de faire bouger tous les personnages et les montres pendant un tour de jeu selon les probabilités  
 *\attention:Pour tous les move_personnages utiliser:
                        -localiser_perso(personnage *p); pour savoir où est le perso
                        -move_personnage(personnage *p,map *la_map); pour le faire bouger
                        -zone random_next_zone(map *la_map) pour determiner les zones d'arrivé des personnages
 *\attention: appliquer cette fonction à chaque personnage.localisation et pas a chaque zone car 2 pers sur la même zone peuvent arriver sur 2zones différentes
 */
void move_les_personnages(personnage* p1, personnage* p2,personnage *p_monstre,map * la_map, joueuse* joueuse_ce_tour);
/**
 * \brief : determiner l'endroit ou se situe un personnage:
 * \return : retourne le numéro de la zone ou il se trouve  
 */
int localiser_perso(personnage *p);

/**
 * \brief : indique si un personnae a ete mangé
 * \return : 0 si mort 1 si vivant
 */
int is_alive(personnage *p, personnage* monstre);
/**
 * \brief : indique si les personnages d'un joueur doit être mangé ou pas si celui ci est en vie.
 * utilise is_alive pour savoir si le monstre est en vie
 * \return : change le etat_perso des personnes qui doivent mourir
 */
void manger_les_persos(joueuse* j1, joueuse* j2,personnage *p_monstre);

//tache b5 
/**
* \brief :
* \return : renvoie la zone où se situe le personnage
*/

int getZone(personnage *p);

/**
* \brief :
* \return : renvoie la taille de la structure personnage
*/

int getSizeOfPerso();

/**
* \brief : fixe la zone où doit se situer le personnage
* \return : 
*/

void setZone(int nouvelle_zone, personnage *p);

/**
* \brief :
* \return : renvoie la zone précédente du personnage sélectionné
*/

int getZonePrec(personnage *p);

/**
* \brief : fixe la zone précédente du personnage sélectionné
* \return : 
*/

void setZonePrec(int set_zone_precedente, personnage *p);

/**
* \brief :
* \return : renvoie l'état du perso 
*/

enum etat_perso getEtatPerso(personnage *p);

/**
* \brief : fixe l'état du perso
* \return : 
*/

void setEtatPerso(enum etat_perso nv_etat, personnage *p);

/**
* \brief :
* \return : renvoie les pouvoirs du personnage 
*/

enum titre *getPouvoirs(personnage *p);

/**
* \brief : fixe les pouvoirs du personnage 
* \return : 
*/

void setPouvoirs(enum titre *nv_pouvoirs, personnage *p);

/**
* \brief : 
* \return : renvoie le propriétaire du personnage
*/

enum nom_joueuse getProprietaireJoueuse(personnage *p);

/**
* \brief : fixe le propriétaire du personnage 
* \return : 
*/

void setProprietaireJoueuse(enum nom_joueuse nv_proprio, personnage *p);

/**
 * \brief : renvoie le personnage suivant dans la liste des membres des joueurs 
 */

personnage *getPersonnageSuivantJoueur(personnage *p);

/**
 * \brief : set le personnage suivant dans la liste des memebres des joueurs
 */
void setPersonnageSuivantJoueur(personnage *p, personnage *nv_perso);

/**
 * \brief : renvoie le personnage suivant dans la liste des personnages de la zone du personnage p
 */

personnage *getPersonnageSuivantZone(personnage *p);

/**
 * \brief : set le personnage suivant dans la liste des personnages de la zone du personnage p
 */
void setPersonnageSuivantZone(personnage *p, personnage *nv_perso);

/**
 * \brief : renvoie l'image correspondant au personnage
 */
RenderObject* getImagePerso(personnage *p);



#endif /* PERSONNAGES_H */
