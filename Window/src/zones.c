#include "../headers/zones.h"
#include "../headers/cartes.h"
#include "../headers/joueuses.h"
#include "../headers/personnages.h"
#include "../headers/structures.h"
#include "ApplicationWrapper.h"
#include "RenderObjectWrapper.h"
#include "LabelWrapper.h"
#include "SFMLEvents.h"
#include "ViewWrapper.h"
#include "../headers/VueJeu.h"
#include <stdio.h>
#include <stdlib.h>
#include "math.h"

#ifndef __FLT_EPSILON__
  #define __FLT_EPSILON__ 1.19209e-07
#endif

//changer le create 

struct zone {
  int id;
  personnage *pj_zone;
  zone* suivante; 
};

struct zones{
  zone *cases;
  RenderObject* vuezones;
  double **matrice;
  RenderObject* vuematrice;
  Label*** coeff_matrice;
  int taille; 

  int capital_utilise; 
  int capital_choisi;  //0 si il n'a pas encore été choisi 1 si il a deja été choisi
};

// tache b6
//creation de la map
map *create_map(Application* app){
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
  m->vuezones=addNewRenderObject(app, Plateau, getFloatRect(0, 0, 0, 0), MiddleGround);
  setPosition(m->vuezones,54,100 );

  m->matrice = creer_graphe(10);
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      m->matrice[i][j] = 0.1;
    }
  }
  m-> taille=10;
  m->vuematrice=addNewRenderObject(app, matrice, getFloatRect(0, 0, 0, 0), MiddleGround);
  setPosition(m->vuematrice,800,100 );
  Label*** matrice= malloc(m->taille * sizeof(Label**));
    for (int i=0; i< m->taille ;i++){
        matrice[i]=malloc(m->taille * sizeof(Label*));
        for (int j=0; j< m->taille;j++){
            matrice[i][j]=addNewLabel(app, 0, "0.1", ForeGround);
            setPosition(matrice[i][j], debut_matrice_longueur+largeur_premierecase+j*longeur_case_matrice+5, debut_matrice_hauteur+hauteur_premierecase+i*hauteur_case_matrice+5);
            setSpriteColor(matrice[i][j], 0,0,0,255);
            setCharacterSize(matrice[i][j], 12);
        }
    }
  m->coeff_matrice=matrice;

  m->capital_utilise=0; 
  m->capital_choisi=0;

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

void updatezone(int numero_zone, map* la_map){
  zone* la_zone=zone_recherche(la_map, numero_zone);
  personnage* perso=getPj_Zone(la_zone);
  int nb_perso_j1=0;
  int nb_perso_j2=0;
  int nb_perso_monstre=0;
  while (perso!=NULL){
    if (getProprietaireJoueuse(perso)==JOUEUSE1){
        setPosition(getImagePerso(perso), 54+(numero_zone%3)*218+41*nb_perso_j1, 100+(int)(numero_zone/3)*150);
        nb_perso_j1+=1;
    }
    else if (getProprietaireJoueuse(perso)==JOUEUSE2 ){
        setPosition(getImagePerso(perso), 54+(numero_zone%3)*218+41*nb_perso_j2, 100+50+(int)(numero_zone/3)*150);
        nb_perso_j2 +=1;
    }
    else {
      setPosition(getImagePerso(perso), 54+(numero_zone%3)*218+41*nb_perso_monstre, 100+50*2+(int)(numero_zone/3)*150);
      nb_perso_monstre +=1;
    }
    perso=getPersonnageSuivantZone(perso);
  }
}

void updatematrice(map* la_map){
  double** matrice=getMatrice(la_map);
  Label*** coeff=la_map->coeff_matrice;
  for (int i=0; i<la_map->taille; i+=1){
    for (int j=0; j<la_map->taille; j+=1){
      if (fabs(matrice[i][j]-0.0)<__FLT_EPSILON__){
        setLabelText(coeff[i][j], "0.0");
      }
      else if (fabs(matrice[i][j]-0.1)<__FLT_EPSILON__){
        setLabelText(coeff[i][j], "0.1");
      } 
      else if (fabs(matrice[i][j]-0.2)<__FLT_EPSILON__){
        setLabelText(coeff[i][j], "0.2");
      } 
      else if (fabs(matrice[i][j]-0.3)<__FLT_EPSILON__){
        setLabelText(coeff[i][j], "0.3");
      } 
      else if (fabs(matrice[i][j]-0.4)<__FLT_EPSILON__){
        setLabelText(coeff[i][j], "0.4");
      } 
      else if (fabs(matrice[i][j]-0.5)<__FLT_EPSILON__){
        setLabelText(coeff[i][j], "0.5");
      } 
      else if (fabs(matrice[i][j]-0.6)<__FLT_EPSILON__){
        setLabelText(coeff[i][j], "0.6");
      } 
      else if (fabs(matrice[i][j]-0.7)<__FLT_EPSILON__){
        setLabelText(coeff[i][j], "0.7");
      } 
      else if (fabs(matrice[i][j]-0.8)<__FLT_EPSILON__){
        setLabelText(coeff[i][j], "0.8");
      } 
      else if (fabs(matrice[i][j]-0.9)<__FLT_EPSILON__){
        setLabelText(coeff[i][j], "0.9");
      } 
      else {
        setLabelText(coeff[i][j], "1.0");
      } 
      
    }
  }
}

void updateMap(VueJeu vj){
  map* la_map=getMap_VueJeu(vj);
  for (int i=0; i<10; i+=1){
    updatezone(i, la_map);
  }
  updatematrice(la_map);
  la_map->capital_utilise=0;

}

int trouver_zone( Application* app){
  float x = getMousePositionX(app);
          float y = getMousePositionY(app);
          int zone=0;
          if (x<=272 && x>=54 && y<=250 && y>=100 ){
              zone=1;
          }
          else if (x<=490 && x>=272 && y<=250 && y>=100 ){
              zone=2;
          }
          else if (x<=708 && x>=490 && y<=250 && y>=100 ){
              zone=3;
          }
          else if (x<=272 && x>=54 && y<=400 && y>=250 ){
              zone=4;
          }
          else if (x<=490 && x>=272 && y<=400 && y>=250 ){
            zone=5;
          }
          else if (x<=708 && x>=490 && y<=400 && y>=250 ){
              zone=6;
          }
          else if (x<=272 && x>=54 && y<=550 && y>=400 ){
              zone=7;
          }
          else if (x<=490 && x>=272 && y<=550 && y>=400 ){
              zone=8;
          }
          else if (x<=708 && x>=490 && y<=550 && y>=400 ){
              zone=9;
          }
          else if (x<=272 && x>=54 && y<=700 && y>=550 ){
              zone=10;
          }
          return zone;
}

void verification(VueJeu vj){
  map* la_map=getMap_VueJeu(vj);
  joueuse* j=getJoueuseCeTour_VueJeu(vj);
   double ** matrice= getMatrice(la_map);
  if (getCapital(j)<la_map->capital_utilise){
        setLabelChoixZone_VueJeu(vj, "Pas assez de capital, \nAppuyer sur espace pour choisir votre capital puis ENTRER");
        la_map->capital_choisi=0;
        la_map->capital_utilise=0;
        setZone1choisi_VueJeu(vj, 0);
        setZone2choisi_VueJeu(vj, 0);
        setZone3choisi_VueJeu(vj,0);
    }
  else if (matrice[getZone1choisi_VueJeu(vj)-1][getZone2choisi_VueJeu(vj)-1]+(la_map->capital_utilise/10.0)<=1 && matrice[getZone1choisi_VueJeu(vj)-1][getZone3choisi_VueJeu(vj)-1]-(la_map->capital_utilise /10.0)>=0 ){                                
        setCanLabelBeDrawn(getLabelChoixZone_VueJeu(vj), 0);
        matrice[getZone1choisi_VueJeu(vj)-1][getZone2choisi_VueJeu(vj)-1]+=(la_map->capital_utilise/10.0);
        matrice[getZone1choisi_VueJeu(vj)-1][getZone3choisi_VueJeu(vj)-1]-=(la_map->capital_utilise /10.0);
        joueuse** joueuses=getJoueuses_VueJeu(vj);
        move_les_personnages(membre_joueur(joueuses[0]), membre_joueur(joueuses[1]), membre_joueur(joueuses[2]), la_map, j);
        utiliser_montant_joueur(j, la_map->capital_utilise);
        la_map->capital_utilise;
        la_map->capital_choisi=0;
    }
  else{
        setLabelChoixZone_VueJeu(vj, "Changements non permis, \nAppuyer sur espace pour choisir votre capital puis ENTRER");
        la_map->capital_choisi=0;
        la_map->capital_utilise=0;
        setZone1choisi_VueJeu(vj, 0);
        setZone2choisi_VueJeu(vj, 0);
        setZone3choisi_VueJeu(vj,0);
    }
}

void handlePhaseChoixProba(VueJeu vj, SFML_EVENTS e, Application* app){
  map* la_map=getMap_VueJeu(vj);
  if (la_map->capital_choisi==0){
    if (e==KEY_PRESSED_Enter){
      la_map->capital_choisi=1;
      setLabelChoixZone_VueJeu(vj, "Choisi une premiere zone sur le plateau ");
    }
    if (e==KEY_PRESSED_Space){
      la_map->capital_utilise+=1;
    }
  }
  else{
    if(e==MOUSE_LEFT_Pressed){
          int zone=trouver_zone( app);
          if (zone !=0 && getZone1choisi_VueJeu(vj)==0){
            setZone1choisi_VueJeu(vj, zone);
            setLabelChoixZone_VueJeu(vj, "Choisi une deuxieme zone sur le plateau");
          }
          else if (zone !=0 && getZone2choisi_VueJeu(vj)==0){
            setZone2choisi_VueJeu(vj, zone);
            setLabelChoixZone_VueJeu(vj, "Choisi une troisieme zone sur le plateau");
          }
          else if (zone !=0 && getZone3choisi_VueJeu(vj)==0){
            setZone3choisi_VueJeu(vj, zone);
            verification(vj); 
          }
              
    }
  }
}

void handlePhaseChoixZone(VueJeu vj, SFML_EVENTS e, Application* app){
  if(e==MOUSE_LEFT_Pressed){
    int zone =trouver_zone(app);
    if (zone !=0 && getZone1choisi_VueJeu(vj)==0){
      setZone1choisi_VueJeu(vj, zone);
   }
    else if (zone !=0 && getZone2choisi_VueJeu(vj)==0){
      setZone2choisi_VueJeu(vj, zone);
    }
    else if (zone !=0 && getZone3choisi_VueJeu(vj)==0){
        setZone3choisi_VueJeu(vj, zone);
    }
  }
}

void handleMapEvent(VueJeu vj, SFML_EVENTS e, Application* app) {
  switch (getPhase_VueJeu(vj)){
    case PhaseChoixProba:
    {
     handlePhaseChoixProba(vj, e, app);
     break;
    }
    case PhaseChoixZone:
    {
      handlePhaseChoixZone(vj, e, app);
      break;
    } 
    default:
      break;  
  }
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

Label*** getCoeffMatrice(map* la_map){
  return la_map->coeff_matrice;
}
