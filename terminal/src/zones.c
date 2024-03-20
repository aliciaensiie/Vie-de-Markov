#include "../headers/zones.h"
#include "../headers/interface.h"
#include "../headers/cartes.h"
#include "../headers/joueuses.h"
#include "../headers/personnages.h"
#include "../headers/structures.h"
#include <stdio.h>
#include <stdlib.h>

struct zone {
  int id;
  personnage *pj_zone;
  zone* suivante; 
};

struct zones{
  zone *cases;
  double **matrice;
  int taille; 
};

// tache b6
//creation de la map
map *create_map(){
  map *m = malloc(sizeof(map));
  zone* cases =NULL;
  int compteur=0;
  while (compteur <10){
        zone* new_zone=malloc(sizeof(zone));
        new_zone->id=compteur;
        new_zone->pj_zone=NULL;
        new_zone->suivante= cases;
        cases=new_zone;
        compteur++;
      }
  m->cases=cases;

  m->matrice = creer_graphe(10);
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      m->matrice[i][j] = 0.1;
    }
  }
  m-> taille=10;
  return m;
}


// liberer la mémoire attribuer à la map 
/* a revoir */
void free_map(map *m){

  free_graphe(m->matrice, getTaille(m));

  zone* cases=m->cases;
  while (cases !=NULL){
    personnage* liste_perso=cases->pj_zone;
    while (liste_perso !=NULL){
      personnage* prec_perso=getPersonnageSuivantZone(liste_perso);
      free_personnage(liste_perso);
      liste_perso=prec_perso;
    }
    zone* prec_cases=getZoneSuivante(cases);
    free(cases);
    cases=prec_cases;
  }
  free(m);
} 


// Récuperer une zone à partir de son numéro allant de 1 a 10

zone *zone_recherche(map *la_map,int numero){
  zone* list=la_map->cases;
  int i=0;
  while (i<numero && list!=NULL){
        list=getZoneSuivante(list);
        i+=1;
  }
  return list;
}


// changer les probabilites de la matrice

void changer_proba(map *la_map, double **changement_proba){
  for(int i=0; i<getTaille(la_map); i++){
    for(int j=0; j<getTaille(la_map); j++){
      la_map->matrice[i][j] += changement_proba[i][j];
    }
  }
}

// recuperer une zone successeur aleatoire 

zone *zone_suivante_aleatoire(map *la_map){
  int alea = rand()%10;
  return zone_recherche(la_map, alea);
}

//tache b5 getter+setter

int getId(zone *z){
  return z->id;
}

void setId(int nv_id, zone *z){
  z->id=nv_id;
}

personnage *getPj_Zone(zone *z){
  return z->pj_zone;
}

void setPjZone(personnage *nv_PjZone, zone *z){
  z->pj_zone=nv_PjZone;
}

zone *getCases(map *Z){
  return Z->cases;
}

void setCases(zone* nouvelles_cases, map *Z){
  Z->cases=nouvelles_cases;
}

double **getMatrice(map *Z){
  return Z->matrice;
}

void setMatrice(double **Nv_Matrice, map* Z){
  Z->matrice=Nv_Matrice;
}

int getSizeOfZone(){
  return sizeof(zone);
}

void setZoneSuivante(zone *z, zone *suiv){
  z->suivante=suiv;
}
zone *getZoneSuivante(zone *z){
  return z->suivante;
}

void setTaille(map* z, int new_taille){
  z->taille=new_taille;
}

int getTaille(map* z){
  return z-> taille;
}
