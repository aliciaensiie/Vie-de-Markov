#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../headers/personnages.h"
#include "../headers/cartes.h"
#include "../headers/joueuses.h"
#include "../headers/effets.h"
#include "../headers/zones.h"
#include "../headers/structures.h"
#include "ApplicationWrapper.h"
#include "../headers/VueJeu.h"
#include "RenderObjectWrapper.h"

struct personnage {
  int zone;
  int zone_precedente; 
  enum etat_perso etat;
  enum titre *pouvoirs;
  enum nom_joueuse proprietaire;
  personnage *suivant_joueur;
  personnage* suivant_zone;
  RenderObject* image_perso; 
};

//tache b6 
//creation d'un personnage

personnage *creer_personnage(int tour_de_joueur, map* la_map, Application* app) {
  personnage *perso = malloc(sizeof(personnage));
  perso->pouvoirs=malloc(10*sizeof(enum titre));
  for (int i=0; i<10;i++){
    perso->pouvoirs[i]=0;
  }
  perso->suivant_joueur = NULL;
  perso->suivant_zone= NULL;
  perso->etat = vivant;
  perso->proprietaire = (enum nom_joueuse)tour_de_joueur;
 

  if (tour_de_joueur==2)
  {
    perso->zone = 0;
    setPjZone(ajouter_pzliste(getPj_Zone(zone_recherche(la_map,perso->zone)), perso), zone_recherche(la_map,perso->zone));
    perso->zone_precedente = 0;
    perso->image_perso=addNewRenderObject(app, Perso_monstre, getFloatRect(0, 0, 0, 0), ForeGround);
  }
  else if(tour_de_joueur==0)
  {
    perso->zone = 1 + (rand() %2);
    
    setPjZone(ajouter_pzliste(getPj_Zone(zone_recherche(la_map, perso->zone)), perso), zone_recherche(la_map,perso->zone));
    perso->zone_precedente = perso->zone;
    perso->image_perso=addNewRenderObject(app, Perso_j1, getFloatRect(0, 0, 0, 0), ForeGround);
  }
  else
  {
    perso->zone = 3 + (rand() %2);
    setPjZone(ajouter_pzliste(getPj_Zone(zone_recherche(la_map,perso->zone)), perso), zone_recherche(la_map,perso->zone));
    perso->zone_precedente = perso->zone;
    perso->image_perso=addNewRenderObject(app, Perso_j2, getFloatRect(0, 0, 0, 0), ForeGround);
  }
  return perso;
}

//liberer memoire attribueer a un personnage 

void free_personnage(personnage *perso) {
  //regarder  si il y a qqchose pour libeerer memoire des listes dans perso
  if (perso!=NULL){
    free(perso);
  }
}
 




void move_personnage(personnage *perso,map *la_map)
{
    int i=getTaille(la_map);
    perso->zone_precedente = perso->zone;
    setPjZone( enlever_pzliste(getPj_Zone(zone_recherche(la_map, perso->zone)),perso), zone_recherche(la_map, perso->zone)) ;
    double* proba_cumulee=malloc(i*sizeof(double)); //on construit les zones ou peut atterrir le perso 

    double **matrice = getMatrice(la_map);
    proba_cumulee[0] = matrice[perso->zone][0]*100; 
    for (int j=1; j<i; j++)
    {
      proba_cumulee[j] = proba_cumulee[j-1] + matrice[perso->zone][j]*100;
    }
    //tirage au sort d'une probabilité 

    int proba_tiree =rand() % 100 +1 ;
    int j=0;
    while (proba_tiree > proba_cumulee[j] && j<i-1){

      j+=1;
    }
    for(int k=0;k<10;k++){
      if(perso->pouvoirs[k]==Pacave){
        // Effet Pacave : le personnage ne peux pas aller sur la zone 11 
        while(j == 10){
          proba_tiree =rand() % 100 +1 ;
          j=0;
          while (proba_tiree > proba_cumulee[j] && j<i-1){
            j+=1;
          }
        }
      }
    }

    perso->zone = j;
    setPjZone( ajouter_pzliste(getPj_Zone(zone_recherche(la_map, perso->zone)), perso), zone_recherche(la_map, perso->zone));
    free(proba_cumulee);
  
  
}


void move_les_personnages(personnage* p1_liste, personnage* p2_liste, personnage* p_monstre_liste,map* la_map, joueuse* joueuse_ce_tour){
  personnage* perso_monstre=p_monstre_liste;
  personnage* perso_j1=p1_liste;
  personnage* perso_j2=p2_liste;

  while(perso_j1 != NULL){

    int tour=0; 

    for(int i=0;i<10;i++){
      if(perso_j1->pouvoirs[i]==Prevel){
        // Effet Prevel pendant 4tour
        tour=1;
      } 
    }

    if(tour==0){
      if(perso_j1->etat==vivant){
        for(int i=0;i<10;i++){
          if(perso_j1->pouvoirs[i]==Ligozat){
            // Effet ligozat : le personnage peut se déplacer deux fois
            move_personnage(perso_j1,la_map);
          } 
        }
        move_personnage(perso_j1,la_map);
        
      }
    }
    perso_j1 = perso_j1->suivant_joueur;
  }
    

  while(perso_j2 != NULL){
    if(perso_j2->etat==vivant){
    for(int i=0;i<10;i++){
      if(perso_j2->pouvoirs[i]==Ligozat){
        // Effet ligozat : le personnage peut se déplacer deux fois
        move_personnage(perso_j2,la_map);
      } 
    }
    move_personnage(perso_j2,la_map);
    
    }
    perso_j2 = perso_j2->suivant_joueur;
  }
  while(perso_monstre != NULL){
    move_personnage(perso_monstre,la_map);
    perso_monstre = perso_monstre->suivant_joueur;
  }

  //effet Bourard
  carte* main=getMain(joueuse_ce_tour);
  while (main!=NULL){
      if (getNom(main)==Bourard && getEtatCarte(main)==ACTIVE){
            effet_Bourard_prochain_tour(la_map, main);    
      }
        main=getCarteSuivante(main);
    }
    
}




int localiser_perso(personnage *p){
  return p->zone;
}


int is_alive(personnage *p, personnage* monstre){

  if (p->etat ==mort)
  {
    return 0; //mort
  }
  while (monstre !=NULL){
    if(p->zone == localiser_perso(monstre))
    {
      for (int i = 0; i < 10; i++)
      {
        if (p->pouvoirs[i]==Szafranski)
        {
          //on regarde si l'effet Szafranski est actif
          return 1; //vivant
        }
       if(p->pouvoirs[i]==Prevel)
        {
          //on regarde si l'effet Prevel est actif
          return 1; //vivant
        }
      }
      return 0; //mort
    }
    monstre= getPersonnageSuivantJoueur(monstre);
  }
  
  return 1; //vivant
}


void manger_les_persos(joueuse* j1, joueuse *j2,personnage *p_monstre_liste){
  int i=0;
  personnage* p_monstre=p_monstre_liste;
  while(p_monstre != NULL){
      personnage* p1=membre_joueur(j1);
      personnage* p2=membre_joueur(j2);
     
      while(p1 !=NULL){
         enum titre* pouvoir_j1=getPouvoirs(p1);
         int tour=0;
        for(int i=0;i<10;i++){
            if(pouvoir_j1[i]==Prevel){
              // Effet Prevel pendant 4tour
              tour=1;
            } 
        }
        if (tour==0 && getEtatPerso(p_monstre)==vivant){
          i=is_alive(p1,p_monstre);
          if (i==0){
            setEtatPerso(mort, p1);
            //p1->etat=mort;
          }
        }
        p1 = p1->suivant_joueur;
      }
      while(p2 !=NULL){
         enum titre* pouvoir_j2=getPouvoirs(p2);
         int tour=0;
        for(int i=0;i<10;i++){
            if(pouvoir_j2[i]==Prevel){
              // Effet Prevel pendant 4tour
              tour=1;
            } 
        }
        if (tour==0 && getEtatPerso(p_monstre)==vivant){
          i=is_alive(p2,p_monstre);
          if (i==0){
            setEtatPerso(mort, p2);
            //p2->etat=mort;
          }
        }
        p2 = p2->suivant_joueur;
      }
      p_monstre = p_monstre->suivant_joueur;
  }
}
 /* --------------------------------------------------------------------------------------------------------------- */
//tache b5

int getZone(personnage *p){
  return p->zone;
}

int getSizeOfPerso(){
  return sizeof(personnage);
}


void setZone(int nouvelle_zone, personnage *p){
  p->zone=nouvelle_zone;
}

int getZonePrec(personnage *p){
  return p->zone_precedente;
}

void setZonePrec(int set_zone_precedente, personnage *p){
  p->zone_precedente=set_zone_precedente;
}

enum etat_perso getEtatPerso(personnage *p){
  return p->etat;
}

void setEtatPerso(enum etat_perso nv_etat, personnage *p){
  p->etat=nv_etat;
  if(nv_etat == mort)
  {
    setCanRenderObjectBeDrawn(p->image_perso, 0);
  }
  else{
    setCanRenderObjectBeDrawn(p->image_perso, 1);
  }
}

enum titre *getPouvoirs(personnage *p){
  return p->pouvoirs;
}

void setPouvoirs(enum titre *nv_pouvoirs, personnage *p){
  p->pouvoirs=nv_pouvoirs;
}

enum nom_joueuse getProprietaireJoueuse(personnage *p){
  return p->proprietaire;
}

void setProprietaireJoueuse(enum nom_joueuse nv_proprio, personnage *p){
  p->proprietaire=nv_proprio;
}
personnage *getPersonnageSuivantJoueur(personnage *p){
  return p->suivant_joueur;
}

void setPersonnageSuivantJoueur(personnage *p, personnage *nv_perso){
  p->suivant_joueur=nv_perso;
}

personnage *getPersonnageSuivantZone(personnage *p){
  return p->suivant_zone;
}

void setPersonnageSuivantZone(personnage *p, personnage *nv_perso){
  p->suivant_zone=nv_perso;
}

RenderObject* getImagePerso(personnage *p){
  return p->image_perso; 
}