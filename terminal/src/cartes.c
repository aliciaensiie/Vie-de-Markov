#include "../headers/cartes.h"
#include "../headers/interface.h"
#include "../headers/joueuses.h"
#include "../headers/personnages.h"
#include "../headers/zones.h"
#include "../headers/structures.h"

#include <stdio.h>
#include <stdlib.h>

struct carte {
  enum titre nom;
  char *description; 
  enum etat_carte etat; 
  int nbtour;
  enum nom_joueuse proprietaire;
  carte *suivante;
};

//tache b5

enum titre getNom(carte *c){
  return c->nom;
}

void setNom(enum titre nouveau_nom, carte *c){
  c->nom=nouveau_nom;
}

char *getDesc(carte *c){
  return c->description;
}

void setDesc(char* nouvelle_description, carte *c){
  c->description=nouvelle_description;
}


enum etat_carte getEtatCarte(carte *c){
  return c->etat;
}

void setEtatCarte(enum etat_carte nouvel_etat, carte *c){
  c->etat=nouvel_etat;
}

int getNbTour(carte *c){
  return c->nbtour;
}

void setNbTour(int nouveau_nb_tour, carte *c){
  c->nbtour=nouveau_nb_tour;
}

enum nom_joueuse getProprietaireCarte(carte *c){
  return c->proprietaire;
}

void setProprietaireCarte(enum nom_joueuse nv_proprietaire, carte *c){
  c->proprietaire=nv_proprietaire;
}

int getSizeOfCarte(){
  return sizeof(carte);
}

void setCarteSuivante(carte *c, carte *suiv){
  c->suivante=suiv;
}
carte *getCarteSuivante(carte *c){
  return c->suivante;
}
