#include "../headers/joueuses.h"
#include "../headers/interface.h"
#include "../headers/cartes.h"
#include "../headers/effets.h"
#include "../headers/personnages.h"
#include "../headers/zones.h"
#include "../headers/structures.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//tache b6

struct joueuse {
  int capital;
  personnage *membres;
  carte *main;
  int tour_de_joueuse; 
};


//fonction qui cree une joueuse 

void creation_main_joueuse(joueuse *j1){

  //creation du deck
  int deck[20];
  for (int i=1;i<=20;i++){
    deck[i-1]=i;
  }

  //melange des cartes
  for (int i = 0; i < 20; i++) {
    int j = rand() % 20;
    int temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
  // distribution des cartes 
  int compteur = 0;
  while (compteur <5){
    carte *carte_suivante_j1= malloc(getSizeOfCarte());

    setNom(deck[compteur],carte_suivante_j1);

    setProprietaireCarte(JOUEUSE1,carte_suivante_j1);

    initialisation_carte(getNom(carte_suivante_j1), carte_suivante_j1);
    
    // On gere l'allocation de memoire pour la carte suivante
    compteur++;
    
    
    if(carte_suivante_j1==NULL){
      fprintf(stderr, "Erreur d'allocation mémoire des cartes suivantes");
      exit(EXIT_FAILURE);
    } 
    setCarteSuivante(carte_suivante_j1,j1->main);
    j1->main = carte_suivante_j1;


    
  }
}

joueuse *creer_joueuse(int tour_de_joueuse, map* la_map){
  //on s'occupe de la creation des joueuses 
  joueuse *j1 = malloc(sizeof(joueuse));

  j1->tour_de_joueuse = tour_de_joueuse;

  if (tour_de_joueuse==0 || tour_de_joueuse==1){
      j1->capital = 5;
      creation_main_joueuse(j1);
      j1->membres=NULL;
      
      int compteur = 0;
      
      while (compteur <5){
        personnage* new_perso=creer_personnage(tour_de_joueuse, la_map);
        setPersonnageSuivantJoueur(new_perso, j1->membres);
        j1->membres =new_perso;
        compteur++;
      }
  }
  else{
    j1->capital = 0;
    j1->main=NULL;
    j1->membres=creer_personnage(tour_de_joueuse, la_map);
    setPersonnageSuivantJoueur(j1->membres,NULL);
  }
  //on cree la main des 2 joueuses 
  

  return j1;
  
}


//fonction qui libere la memoire allouee a une joueuse

void free_joueuse(joueuse *j){
  free(j);
}

//fonction qui renvoie le pointeur de la joueuse dont c'est le tour
joueuse *tour_de_joueur(joueuse *j1, joueuse *j2,int tour_actuel){
  if(j1->tour_de_joueuse == (tour_actuel%2)){
    return j1;
  }
  else{
    return j2;
  }
}

//fonction qui renvoie la liste des membres d'une joueuse 
personnage *membre_joueur(joueuse *j){
  return j->membres;
}

/**
 * \brief : prend un joueur et indique le nb de membre vivant
 */

int compte_membre_joueur(joueuse *j){
  int nb_membre_vivant = 0;
  personnage* persos=membre_joueur(j);
  while(persos!=NULL){
    if(getEtatPerso(persos)==vivant){
      nb_membre_vivant++;
    }
    persos = getPersonnageSuivantJoueur(persos);
  }
  return nb_membre_vivant;
}

// fonction qui indique si tous les membres d'une joueuse sont morts ou pas 
int as_tu_perdu(joueuse *j){
  int nb_membre_vivant = compte_membre_joueur(j);
  if(nb_membre_vivant == 0){
    return 0;
  }
  else{
    return 1;
  }
}

// Reinitialise le capital d'une joueuse 

void reinitialiser_capital(joueuse *j){
  j->capital = 5;
}

//utilise un certain capital d'une joueuse 
void utiliser_montant_joueur(joueuse *j, int capital){
  j->capital -= capital;
}




/*----------------------------------------------------------------------------------------*/
//tache b5

int getCapital(joueuse *j){
    return j->capital;
}

void setCapital(int nv_capital, joueuse *j){
    j->capital=nv_capital;
}

carte *getMain(joueuse *j){
    return j->main;
}

void setMain(carte *nouvelle_main, joueuse *j){
    j->main=nouvelle_main;
}
int getTourdeJoueuse(joueuse *j){
    return j->tour_de_joueuse;
}

void setTourdeJoueuse(int nv_tour, joueuse *j){
  j->tour_de_joueuse=nv_tour;
}

void setMembresJoueuse(personnage* new_list, joueuse* j){
  j->membres=new_list;
}
