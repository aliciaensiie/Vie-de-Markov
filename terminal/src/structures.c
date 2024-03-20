#include<stdio.h>
#include<stdlib.h>
#include "../headers/structures.h"
#include "../headers/interface.h"
#include "../headers/cartes.h"
#include "../headers/joueuses.h"
#include "../headers/personnages.h"
#include "../headers/zones.h"


personnage* creer_pliste_vide()
{
    return NULL;
}

int test_vide_pliste(personnage* pliste)
{
    return (pliste==NULL);
}

int taille_pjliste(personnage* liste)
{
    if (liste==NULL){
        return 0;
    }
    int n=0;
    while (liste!=NULL){
        liste=getPersonnageSuivantJoueur(liste);
        n+=1;
    }
    return n;
}

int taille_pzliste(personnage* liste)
{
    if (liste==NULL){
        return 0;
    }
    int n=0;
    while (liste!=NULL){
        liste=getPersonnageSuivantZone(liste);
        n+=1;
    }
    return n;
}

personnage* ajouter_pjliste( personnage* liste, personnage* perso)
{
    setPersonnageSuivantJoueur(perso, liste);
    return perso;
}

personnage* ajouter_pzliste( personnage* liste, personnage* perso)
{
    setPersonnageSuivantZone(perso, liste);
    return perso;
}

personnage* chercher_pjliste( personnage* liste,  int id_zone, enum nom_joueuse proprietaire)
{
    while (getZone(liste)!=id_zone || getProprietaireJoueuse(liste)!=proprietaire){
        liste=getPersonnageSuivantJoueur(liste); 
    }
    return liste; 
    
}
personnage* chercher_pzliste( personnage* liste,  int id_zone, enum nom_joueuse proprietaire)
{
    while (getZone(liste)!=id_zone || getProprietaireJoueuse(liste)!=proprietaire){
        liste=getPersonnageSuivantZone(liste); 
    }
    return liste; 
    
}
 
personnage* parcourir_pjliste(personnage* list, int numero){
    int i=0;
    while (i<numero && list!=NULL){
        list=getPersonnageSuivantJoueur(list);
        i+=1;
    }
    return list;
}

personnage* parcourir_pzliste(personnage* list, int numero){
    int i=0;
    while (i<numero && list!=NULL){
        list=getPersonnageSuivantZone(list);
        i+=1;
    }
    return list;
}

personnage* enlever_pjliste(personnage* pliste, personnage* aenlever){
    personnage* curr=pliste;
    personnage* prec =pliste;
    if (curr==NULL){
        return NULL;
    }
    if (curr== aenlever){
        setPersonnageSuivantJoueur( prec, getPersonnageSuivantJoueur(curr));
        return pliste;
    }
    curr=getPersonnageSuivantJoueur(curr);
    while(curr!=aenlever && curr!=NULL ){
        prec=curr;
        curr=getPersonnageSuivantJoueur(curr);
    }
    if (curr==NULL){
        return pliste;
    }
    if (curr==aenlever){
        setPersonnageSuivantJoueur(prec, getPersonnageSuivantJoueur(curr));
        return pliste;
    }
    
    return NULL;
}

personnage* enlever_pzliste(personnage* pliste, personnage* aenlever){
    if (aenlever==NULL){
        return pliste;
    }
    personnage* curr=pliste;
    personnage* prec =pliste;
    if (curr==NULL){
        return NULL;
    }
    if (curr== aenlever){
        prec=getPersonnageSuivantZone(curr);
        return prec;
    }
    curr=getPersonnageSuivantZone(curr);
    while(curr!=aenlever && curr!=NULL ){
        prec=curr;
        curr=getPersonnageSuivantZone(curr);
    }
    if (curr==NULL){
        return pliste;
    }
    if (curr==aenlever){
        setPersonnageSuivantZone(prec, getPersonnageSuivantZone(curr));
        return pliste;
    }
    
    return NULL;
}

void free_pjliste(personnage* liste){
   while (liste!=NULL){
        personnage* prec= liste;
        liste=getPersonnageSuivantJoueur(liste);
        free(prec);
   }
}

void free_pzliste(personnage* liste){
   while (liste!=NULL){
        personnage* prec= liste;
        liste=getPersonnageSuivantZone(liste);
        free(prec);
   }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

zone* creer_zliste_vide()
{
   return NULL;
}

int test_vide_zliste(zone* liste){
    return (liste==NULL);
}



zone* ajouter_zliste( zone* liste, zone* z){
    setZoneSuivante(z, liste);
    return z; 
}

int taille_zliste(zone* liste)
{
    if (liste==NULL){
        return 0;
    }
    int n=0;
    while (liste!=NULL){
        liste=getZoneSuivante(liste);
        n+=1;
    }
    return n;
}

void free_zliste(zone* liste){
   while (liste!=NULL){
        zone* prec= liste;
        liste=getZoneSuivante(liste);
        free(prec);
   }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------_


carte* creer_cliste_vide()
{
   return NULL;
}

int taille_cliste(carte* liste){
    if (liste==NULL){
        return 0;
    }
    int n=0;
    while (liste!=NULL){
        liste=getCarteSuivante(liste);
        n+=1;
    }
    return n;
}

carte* ajouter_cliste( carte* liste, carte *c){
    setCarteSuivante(c, liste);
    return c; 
}

carte* parcourir_cliste(carte* list, int numero){
    int i=0;
    while (i<numero){
        list=getCarteSuivante(list);
        i+=1;
    }
    return list;
}

void free_cliste(carte* liste)
{
    while (liste!=NULL){
        carte* prec= liste;
        liste=getCarteSuivante(liste);
        free(prec);
   } 
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

double** creer_graphe(int taille)
{
    double** matrice= malloc(taille * sizeof(double*));
    for (int i=0; i< taille ;i++){
        matrice[i]=malloc(taille * sizeof(double));
        for (int j=0; j< taille;j++){
            matrice[i][j]=0.0;
        }
    }
    return matrice;
}

void free_graphe( double** graphe, int taille)
{
    for (int i=0; i<taille ;i++)
    {
        free (graphe[i]);       
    }
    free (graphe);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------


int test_vide_pvliste(enum titre* pouvoir)
{
    for (int i=0; i<10;i++){
        if (pouvoir[i]!=0){
            return 1;
        }
    }  
    return 0;   
}

int taille_pvliste(enum titre* pouvoir)
{
    int n=0;
    for (int i=0; i<10;i++){
        if (pouvoir[i]!=0){
            n+=1;
        }
    }
    return n;
}

enum titre* ajouter_pvliste(enum titre* liste, enum titre pouvoir)
{
    int i=0;
    while (liste[i]!=0 && i<10){
        i+=1;
    }
    if (i==10){
        fprintf(stderr, "Problème du nombre de pouvoir d'un joueur");
        exit(0);
    }
    liste[i]=pouvoir;
    return liste; 
}

void free_pouvoir(enum titre* pvliste)
{
    free (pvliste);
}
