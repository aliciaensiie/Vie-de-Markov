#include "../headers/joueuses.h"
#include "../headers/cartes.h"
#include "../headers/effets.h"
#include "../headers/personnages.h"
#include "../headers/zones.h"
#include "../headers/structures.h"
#include "../headers/VueJeu.h"
#include "AnimationWrapper.h"
#include "RenderObjectWrapper.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//tache b6

struct joueuse {
  int capital;
  personnage *membres;
  carte *main;
  int tour_de_joueuse;
  Application* app;
};


//fonction qui cree une joueuse 

void creation_main_joueuse(joueuse *j1, Application* app){

  //creation du deck
  int deck[number_of_cards];
  for (int i=1;i<=number_of_cards;i++){
    deck[i-1]=i;
  }

  //melange des cartes
  for (int i = 0; i < number_of_cards; i++) {
    int j = rand() % number_of_cards;
    int temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
  // distribution des cartes 
  int compteur = 0;
  while (compteur <5){
    carte *carte_suivante_j1= malloc(getSizeOfCarte());
    int vraicompteur=deck[compteur];
    int j=1;

    setNom(deck[compteur],carte_suivante_j1);

    setProprietaireCarte(JOUEUSE1,carte_suivante_j1);

    initialisation_carte(getNom(carte_suivante_j1), carte_suivante_j1);

    RenderObject* imagecarte= addNewRenderObject(app,getNom(carte_suivante_j1), getFloatRect(0, 0, 0, 0), ForeGround);
    setPosition(imagecarte, 55+compteur*(100+55),750);
    setImageCarte(carte_suivante_j1, imagecarte);
    
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

joueuse *creer_joueuse(int tour_de_joueuse, map* la_map, Application* app){
  //on s'occupe de la creation des joueuses 
  joueuse *j1 = malloc(sizeof(joueuse));

  j1->tour_de_joueuse = tour_de_joueuse;

  if (tour_de_joueuse==0 || tour_de_joueuse==1){
      j1->capital = 5;
      j1->main=NULL; 
      creation_main_joueuse(j1,app);
      j1->membres=NULL;
      
      int compteur = 0;
      int nb_zone1=0;
      int nb_zone2=0;
      int nb_zone3=0;
      int nb_zone4=0;
      
      while (compteur <5){
        personnage* new_perso=creer_personnage(tour_de_joueuse, la_map, app);
        switch (getZone(new_perso)){
          case 1:
            setPosition(getImagePerso(new_perso),debut_zones_longueur+longueur_zone+nb_zone1*longueur_perso, debut_matrice_hauteur );
            nb_zone1+=1;
            break; 
          case 2: 
            setPosition(getImagePerso(new_perso),debut_zones_longueur+2*longueur_zone+nb_zone2*longueur_perso, debut_matrice_hauteur );
            nb_zone2+=1;
            break;
          case 3: 
            setPosition(getImagePerso(new_perso),debut_zones_longueur+nb_zone3*longueur_perso, debut_matrice_hauteur+hauteur_zone+hauteur_perso );
            nb_zone3+=1;
            break;
          case 4:
            setPosition(getImagePerso(new_perso),debut_zones_longueur+longueur_zone+nb_zone4*longueur_perso, debut_matrice_hauteur+hauteur_zone+hauteur_perso );
            nb_zone4+=1;
            break;
        }
        setPersonnageSuivantJoueur(new_perso, j1->membres);
        j1->membres =new_perso;
        compteur++;
      }
  }
  else{
    j1->capital = 0;
    j1->main=NULL;
    j1->membres=creer_personnage(tour_de_joueuse, la_map, app);
    setPersonnageSuivantJoueur(j1->membres,NULL);
    setPosition(getImagePerso(j1->membres),debut_zones_longueur, debut_matrice_hauteur+2*hauteur_perso);
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

void rendre_visible(joueuse* joueuse_ce_tour){
  carte* main= getMain(joueuse_ce_tour);
  while( main!=NULL){
    if (getEtatCarte(main)==INACTIVE){
      setCanRenderObjectBeDrawn(getImageCarte(main), 1);
    }
    main=getCarteSuivante(main);
  }
}

void rendre_invisible(joueuse* joueuse_adverse){
  carte* main=getMain(joueuse_adverse);
  while(main!=NULL){
    if (canRenderObjectBeDrawn(getImageCarte(main))==1){
      setCanRenderObjectBeDrawn(getImageCarte(main), 0);
    }
    main=getCarteSuivante(main);
  }
}

void handleJoueuseEvent(SFML_EVENTS e, VueJeu vj, Application* app){
  if (e==MOUSE_LEFT_Pressed){
    float x = getMousePositionX(app);
    float y = getMousePositionY(app);
    carte* main=getMain(getJoueuseCeTour_VueJeu(vj));
    for (int i=0; i<5; i++){
        if (getEtatCarte(main)==INACTIVE && containsPoint(getImageCarte(main), x,y)){
            setEffetChoisi_VueJeu(vj, getNom(main));
        }
        main=getCarteSuivante(main);
    }   
  }
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
