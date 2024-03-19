#ifndef EFFETS_H
#define EFFETS_H

#include "cartes.h"
#include "joueuses.h"
#include "LabelWrapper.h"

typedef struct Application Application;
/**
 * \brief: initialise une carte avec son nom, sa description, son etat et son nombre de tour d'activation
 * \param nom: nom de la carte a initialiser
*/
void initialisation_carte(int nom, carte* macarte);

/**
 * \brief: applique l'effet bourard au prochain tour
*/
void effet_Bourard_prochain_tour(map* la_map, carte* la_carte);

/**
 * \brief: Regarde si on peut continuer le tour normalement 
 * \param numero: numero du tour
 * \return: renvoie 0 si il n'y a pas de carte activé ou si l'action peut être faite avant de continuer normalement, 1sinon
 * \attention: il peut y avoir plusieurs cartes d'activées en même temps qui font differents trucs
*/
int activate_carte(joueuse* joueuse1, joueuse* monstre);

/** 
 * \brief: Applique l'effet de la carte choisie 
 * \param numero: numero du tour en cours 
 * \param num_carte:  numero de la carte à jouer
*/
int jouer_une_carte(joueuse* joueuse1, joueuse* joueuse2, joueuse* monstre, int numero, map* la_map, int num_carte,int zone1,int zone2,Application *app);

char* description(int nom);
char* name(int nom);

Label** create_desc_effect(Application* app);
void print_desc_effect(Label** list_label);
void remove_desc_effect(Label** list_label);

#endif