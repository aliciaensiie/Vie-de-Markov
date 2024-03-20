/**
 * \file : zones.h
 *
 * Ce fichier décrit les informations et actions relatives aux 
 * zones du jeu. On y gere les probabilites qui relie une zone à l'autre
 */
/**
 * Tache A3
 */
#ifndef ZONES_H
#define ZONES_H



/**
 * \brief : la map represente toute la zone de jeu et regroupe les probabilites
 * de se deplacer d'une zone à l'autre
 */
typedef struct zones map;

/**
 * \brief : zone definit les zones de jeu
 */
typedef struct zone zone; 


/**
 * \brief : creer la map en allouant la memoire
 * \return : renvoie une carte initialiser. les probas sont tous à 1/10
 */
map *create_map();

/**
 * \brief : libere la mémoire alloué lors de la création de map
 */
void free_map(map *la_map);

/**
 * \brief : recuperer une zone à partir de son numero
 * \param la_map : le plateau de jeu 
 * \param numero : le numéro de la zone recherchée
 * \return : renvoie la zone cherchée
 */
zone *zone_recherche(map *la_map, int numero);
/**
 * \brief : appliquer les décisions des joueuses de modifier les probabilites 
 * avec son capital
 * \param la_map : pointeur vers le plateau de jeu ou on va recuperer les infos
 * \param changement_proba : matrice contenant les modifications à apporter au proba contenu dans map
 */
void changer_proba(map *la_map,double **changement_proba );

/**
 * \brief : recuperer une zone successeur aleatoire d'une zone données
 * \return : renvoie la zone tirée au sort
 */
zone *zone_suivante_aleatoire(map *la_map);

//tache b5 getter+setter

/**
* \brief : 
* \return : renvoie l'id de la zone choisie
*/

int getId(zone *z);

/**
* \brief : fixe la valeur de l'identitifant de la zone choisie
* \return : 
*/

void setId(int nv_id, zone *z);

/**
* \brief : 
* \return : renvoie la valeur de la zone où se situe le personnage
*/

struct personnage *getPj_Zone(zone *z);

/**
* \brief : fixe la valeur de la zone actuelle du personnage
* \return :
*/

void setPjZone(struct personnage *nv_PjZone, zone *z);

/**
* \brief :
* \return : renvoie la valeur de la liste des cases de la carte des zones
*/

zone *getCases(map *Z);

/**
* \brief : fixe la valeur de la liste des cases de la carte des zones
* \return :
*/

void setCases(zone* nouvelles_cases, map *Z);

/**
* \brief :
* \return : renvoie la matrice correspondante à la carte
*/

double **getMatrice(map *Z);

/**
* \brief : fixe la carte du jeu 
* \return :
*/

void setMatrice(double **Nv_Matrice, map* Z);

/**
* \brief :
* \return : renvoie la taille du struct de zone
*/

int getSizeOfZone();

/***
 * \brief : permet de definir la zone suivante
 */
void setZoneSuivante(zone *z, zone *suiv);

/**
 * \brief : permet de recuperer la zone suivante
 */
zone *getZoneSuivante(zone *z);

/**
 * \brief : permet de modifier la taille de la matrice et le nombre de zones 
 */
void setTaille(map* z, int new_taille);

/**
 * \brief : permet de récupérer la taille de la matrice et le nombre de zones 
 */
int getTaille(map* z);
#endif /* ZONES_H */
