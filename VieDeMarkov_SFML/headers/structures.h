/**
 * \file : structure.h
 *
 * Ce fichier
 */
/**
 * Tache B3
 */
#ifndef structure_H
#define structure_H
#include "personnages.h"

//pour les liste de personnage

 
/**
* \brief : la fonction creer une liste vide 
* d'element de type personnage
* \return : retourne une liste vide
*/
personnage* creer_pliste_vide();

/**
* \brief : la fonction teste si une liste  
* d'element de type personnage est vide ou pas
* \return : retourne 0 si la liste est vide 1 sinon
*/
int test_vide_pliste(personnage* pliste);

/**
* \brief : la fonction calcule le nombre de
*personnage dans une liste de memebre de joueuse
* \return : la taille de la liste 
*/
int taille_pjliste(personnage* pliste);

/**
* \brief : la fonction calcule le nombre de
*personnage dans une liste de personnage d'une zone
* \return : la taille de la liste 
*/
int taille_pzliste(personnage* pliste);

/**
* \brief : la fonction ajoute un personnage a une liste 
* d'element de type personnage dans une liste de memebre de joueuse
*/
personnage* ajouter_pjliste( personnage* pliste, personnage* perso);

/**
* \brief : la fonction ajoute un personnage a une liste 
* d'element de type personnage dans une liste de personnage d'une zone
*/
personnage* ajouter_pzliste( personnage* pliste, personnage* perso);

// pas besoin de fonctionner pour enlever les personnages

/**
* \brief : la fonction retourne un personnage d'une liste 
* d'element de type personnage dans une liste de memebre de joueuse
* \return : le personnage recherche
*/
personnage* chercher_pjliste( personnage* pliste,  int id_zone, enum nom_joueuse proprietaire);

/**
* \brief : la fonction retourne un personnage d'une liste 
* d'element de type personnage dans une liste de personnage d'une zone
* \return : le personnage recherche
*/
personnage* chercher_pzliste( personnage* pliste,  int id_zone, enum nom_joueuse proprietaire);

/**
* \brief : la fonction enleve le personnage aenlever de le liste de personnages dans une liste de memebre de joueuse
* \return : la nouvelle liste de personnages
*/
personnage* enlever_pjliste(personnage* pliste, personnage* aenlever);

/**
* \brief : la fonction enleve le personnage aenlever de le liste de personnages dans une liste de personnage d'une zone
* \return : la nouvelle liste de personnages
*/
personnage* enlever_pzliste(personnage* pliste, personnage* aenlever);

/**
* \return : le ième personnage de la liste de personnage dans une liste de memebre de joueuse
*/
personnage* parcourir_pjliste(personnage* list, int numero);

/**
* \return : le ième personnage de la liste de personnage dans une liste de personnage d'une zone
*/
personnage* parcourir_pzliste(personnage* list, int numero);

/**
* \brief : la procedure libere la memoire prise par la lsite de personnage dans une liste de memebre de joueuse
* \return : rien
*/
void free_pjliste(personnage* liste);

/**
* \brief : la procedure libere la memoire prise par la lsite de personnage dans une liste de personnage d'une zone
* \return : rien
*/
void free_pzliste(personnage* liste);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//pour les listes de zone

/**
* \brief : la fonction creer une liste vide 
* d'element de type zone
* \return : retourne une liste vide
*/
zone* creer_zliste_vide();

/**
* \brief : la fonction teste si une liste  
* d'element de type zone est vide ou pas
* \return : retourne 0 si la liste est vide 1 sinon
*/
int test_vide_zliste( zone* zliste);

/**
 * \brief : la fonction rajoute un element dans la liste
 * \return : la nouvelle liste
*/
zone* ajouter_zliste( zone* liste, zone* z);

/**
 * \return : la taille de la liste de zone
*/
int taille_zliste(zone* liste);

/**
* \brief : la procedure libere la memoire prise par la liste de zone
* \return : rien
*/
void free_zliste(zone* liste);

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Pour les cartes:

/**
* \brief : la fonction creer une liste vide 
* d'element de type carte
* \return : retourne une liste vide
*/
struct carte* creer_cliste_vide();

/**
* \brief : la fonction calcule le nombre de
*carte dans une liste 
* \return : la taille de la liste 
*/
int taille_cliste(struct carte* main);

/**
* \brief : la fonction ajoute un personnage a une liste 
* d'element de type personnage
* \return : la liste avec le personnage ajoute
*/
struct carte* ajouter_cliste( struct carte* liste, struct carte *c);

/**
* \return : la carte numero de la liste de carte
*/
struct carte* parcourir_cliste(carte* list, int numero);


/**
* \brief : la procedure libere la memoire prise par la liste de zcarte
* \return : rien
*/
void free_cliste(struct carte* liste);

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Pour la matrice


/**
* \brief : la fonction retourne une matrice carré de taille 'taille'où
* les composantes representent les probabilites de deplacement de la
* zone i vers la zone j
* \return : une matrice M telle que décrite ci-dessus initialisé à 0.1
*/
double** creer_graphe(int taille);


/**
* \brief : la procedure libere la memoire prise par la matrice
* \return : rien
*/
void free_graphe(double** graphe, int taille);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Pour les pouvoirs des persos

/**
* \brief : la fonction teste si une liste  
* d'element de type enum titre est vide ou pas
* \return : retourne 0 si la liste est vide 1 sinon
*/
int test_vide_pvliste(enum titre* pouvoir);

/**
* \brief : la fonction calcule le nombre de
* pouvoir dans une liste 
* \return : la taille de la liste 
*/
int taille_pvliste(enum titre* pouvoir);

/**
* \brief : la fonction ajoute un pouvoir a une liste 
* d'element de type pouvoir
* \return : la liste avec le pouvoir ajoute
*/
enum titre* ajouter_pvliste(enum titre* liste, enum titre pouvoir);

/**
 * \brief : la fonction libere la memoire allouee dans la liste de pouvoir qu'un personnage a obtenu
 * \return : rien
 */
void free_pouvoir(enum titre* liste);

#endif
