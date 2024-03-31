#include "../headers/interface.h"
#include "../headers/cartes.h"
#include "../headers/joueuses.h"
#include "../headers/personnages.h"
#include "../headers/zones.h"
#include "../headers/structures.h"
#include "../headers/effets.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  //FONCTION QUI DEMANDE A LA JOUEUSE SI ELLE VEUT VOIR SES CARTES ET SI OUI LES AFFFICHE


void affichage_cartes(joueuse* joueuse){
    long choix=0;
    int MAX_LENGTH=3;
    char * buffer = (char *) malloc( MAX_LENGTH );
    char * buffer2 = (char *) malloc( MAX_LENGTH );
    printf("\033[36;01mSouhaites-tu voir tes cartes ?\033[00m\n");
    printf("1. oui\n");
    printf("2. non\n");
    printf("Entre le numero correspondant à la reponse souhaitée.\n");
    fgets( buffer, MAX_LENGTH, stdin );
    choix = strtol( buffer, &buffer2, 10 );
    while (((choix!=1) && (choix!=2) )|| buffer==buffer2){
        printf("\033[36;01mSouhaites-tu voir tes cartes ?\033[00m\n");
        printf("1. oui\n");
        printf("2. non\n");
        printf("Entre le numero correspondant à la reponse souhaitée.\n");
        fgets( buffer, MAX_LENGTH, stdin );
        choix = strtol( buffer, &buffer2, 10 );
    }
    
    if (choix==1){
        int j=0;
        carte* main=getMain(joueuse);
        for (int i=0; i<taille_cliste(main); i++){                                                                          
            if (getEtatCarte(parcourir_cliste(main, i))==INACTIVE){                                                                                 
                j+=1;
                printf("carte n°%d:\n",getNom(parcourir_cliste(main, i)));                                                                  
                printf("    %s\n\n", getDesc(parcourir_cliste(main, i)));                                                               
            }
        }
        if (j==0){
            printf("Tu n as plus de cartes\n");
        }
        
    }
}


// FONCTION AUXILIAIRE AFFICHAGE INFO:

//crée un string correspondant à une ligne d'une case pour afficher la présence de personnages ou monstres
char* compte_perso_zone(int Z, char forme, char* j){
    char espace[8];
    sprintf(espace,"%c%c%c%c%c%c%c",' ',' ',' ',' ',' ',' ',' ');
    char f[8];
    
    sprintf(f, "%c%c%c%c%c%c%c", forme, forme, forme, forme, forme, forme, forme);
    sprintf(j, "%c",'\0');
    strncat(j, f, Z);
    strncat(j, espace, 7-Z);

    return j;
}

//crée un string correspondant à une ligne d'une case pour afficher le numéro de la case
char* numero_zone(int numero, char* j){
    char espace[8];
    sprintf(espace,"%c%c%c%c%c%c%c",' ',' ',' ',' ',' ',' ',' ');
    char f[8];
    sprintf(f, "%d%d%d%d%d%d%d", numero, numero, numero, numero, numero, numero, numero);
    sprintf(j, "%c",'\0');
    strncat(j, f, 1);
    strncat(j, espace, 6);
    return j;
}

//compte le nombre de perso de joueurs sur une zone 
int nbre_perso_joueur(map* la_map, int i, enum nom_joueuse  proprietaire, int k){
    int n=0;
    personnage* pj_cette_zone=getPj_Zone(zone_recherche(la_map, k*3+i)); 
    for (int j=0; j<taille_pzliste(pj_cette_zone); j++){
        personnage* perso=parcourir_pzliste (pj_cette_zone, j);
        if (getProprietaireJoueuse(perso)==proprietaire && getEtatPerso(perso)==vivant){                               
            n=n+1;
        }
    }
    return n;
}

void ligne_numero(char* j, int k){
    for (int i=0; i<3;i++){
        j=numero_zone(k*3+i+1, j);
        printf("|%s",j);
    }
    printf("|");
}

void ligne_j1(char* j,map* la_map , int k ){
    for (int i=0; i<3; i++){
            int n=nbre_perso_joueur(la_map, i, 0, k);
            j= compte_perso_zone(n,'x', j); 
            printf("|%s",j);
    } 
    printf("|");
}

void ligne_j2(char* j, map* la_map, int k){
    for (int i=0; i<3; i++){
        int n=nbre_perso_joueur(la_map, i, 1, k);
        j= compte_perso_zone(n,'o', j); 
        printf("|%s",j);
    } 
    printf("|");
}

void ligne_monstre(char* j, map* la_map, int k){
    for (int i=0; i<3; i++){
        int n=nbre_perso_joueur(la_map, i, 2, k);
        j= compte_perso_zone(n,'M', j); 
        printf("|%s",j);
    }
    printf("|");
}

void lignes_cases(char* j, int k, map* la_map){
    printf("________________________\n");
    ligne_numero(j, k);
    printf("\n");
    ligne_j1(j, la_map, k);
    printf("\n");
    ligne_j2(j, la_map, k);
    printf("\n");
    ligne_monstre(j, la_map, k);
    printf("\n");
}

//pour 10 et 11
char* numero_zone_2(int numero, char* j){
    char espace[8];
    sprintf(espace,"%c%c%c%c%c%c%c",' ',' ',' ',' ',' ',' ',' ');
    char f[16];
    sprintf(f, "%d%d%d%d%d%d%d", numero, numero, numero, numero, numero, numero, numero);
    sprintf(j, "%c",'\0');
    strncat(j, f, 2);
    strncat(j, espace, 5);
    return j;
}

void une_case(char* j, map* la_map){
     printf("________________________\n");
    j=numero_zone_2(10, j);
    printf("|%s|",j);
    printf("\n");
    int n=nbre_perso_joueur(la_map, 0, 0, 3);
    j= compte_perso_zone(n,'x', j); 
    printf("|%s",j);
    printf("|");
    printf("\n");
    n=nbre_perso_joueur(la_map, 0, 1, 3);
    j= compte_perso_zone(n,'o', j); 
    printf("|%s",j);
    printf("|");
    printf("\n");
    n=nbre_perso_joueur(la_map, 0, 2, 3);
    j= compte_perso_zone(n,'M', j); 
    printf("|%s",j);
    printf("|");
    printf("\n");
    printf("________________________\n");
}

void deux_cases(char*j, map* la_map){
     printf("________________________\n");
    for (int i=0; i<2;i++){
        j=numero_zone_2(10+i, j);
        printf("|%s",j);
    }
    printf("|\n");
    for (int i=0; i<2;i++){
        int n=nbre_perso_joueur(la_map, i, 0, 3);
        j= compte_perso_zone(n,'x', j); 
        printf("|%s",j);
    }
    printf("|");
    printf("\n");
    for (int i=0; i<2;i++){
        int n=nbre_perso_joueur(la_map, i, 1, 3);
        j= compte_perso_zone(n,'o', j); 
        printf("|%s",j);
    }
    printf("|");
    printf("\n");
    for (int i=0; i<2; i++){
        int n=nbre_perso_joueur(la_map, i, 2, 3);
        j= compte_perso_zone(n,'M', j); 
        printf("|%s",j);
    }
    printf("|");
    printf("\n");
    printf("________________________\n");

}



void plateau(map* la_map){
    printf("\nLes croix sont les personnages de la joueuse 1 et les ronds sont les personnages de la joueuse 2\n");
    char* j = (char*) malloc(8*sizeof(char));
    for (int k=0; k<3; k++){
        lignes_cases(j, k, la_map);
    }
    if (getTaille(la_map)==10){                                           
        une_case(j, la_map);
    }
    else {
        deux_cases(j, la_map);
    }
    
}
//------------------------------------------------------------

void matrice(map* la_map){
    printf("Un noeud (i,j) correspond à la probabilité d aller de i vers j \n");
    printf("  %s%8s%7s%7s%7s%7s%7s%7s%7s%7s%7s","\\ ", "Z1", "Z2","Z3", "Z4", "Z5", "Z6","Z7", "Z8", "Z9","Z10");
    if (getTaille(la_map)==11){                                           
        printf("%7s \n", "Z11");
    }
    else{
        printf("\n");
    }
    double** matrice= getMatrice(la_map);  
    for (int i=0; i<getTaille(la_map); i++){                                
        printf("%s%2d      ","Z",i+1 );
        for (int k=0; k<getTaille(la_map); k++){                     
            printf("%1.1f    ", matrice[i][k]);                               
        }
        printf("\n\n");
    }
}

//---------------------------------------------------------
//affichage tour j1
void tour_j1(){
printf(" _______    _________________________    ______  _______    ________________         _______ _______    ___________      _    \n");
printf("(  ___  )   \\__   __(  ___  )__   __/   (  __  \\(  ____ \\   \\__    _(  ___  )\\     /(  ____ (  ____ )   \\__    _/  \\    ( )    \n");
printf("| (   ) |      ) (  | (   ) |  ) (      | (  \\  ) (    \\/      )  ( | (   ) | )   ( | (    \\/ (    )|      )  ( \\/) )   | |      \n");
printf("| (___) |      | |  | |   | |  | |      | |   ) | (__          |  | | |   | | |   | | (__   | (____)|      |  |   | |   | |     \n");
printf("|  ___  |      | |  | |   | |  | |      | |   | |  __)         |  | | |   | | |   | |  __)  |     __)      |  |   | |   | |    \n");
printf("| (   ) |      | |  | |   | |  | |      | |   ) | (            |  | | |   | | |   | | (     | (\\ (         |  |   | |   (_)   \n");
printf("| )   ( |      | |  | (___) |__) (___   | (__/  ) (____/\\   |\\_)  ) | (___) | (___) | (____/\\ ) \\ \\__   |\\_)  ) __) (_   _    \n");
printf("|/     \\|      )_(  (_______)_______/   (______/(_______/   (____/  (_______|_______|_______//   \\__/   (____/  \\____/  (_)   \n\n");
}

//affichage tour j2
void tour_j2(){
printf(" _______    _________________________    ______  _______    ________________         _______ _______    ________________    _     \n");
printf("(  ___  )   \\__   __(  ___  )__   __/   (  __  \\(  ____ \\   \\__    _(  ___  )\\     /(  ____ (  ____ )   \\__    _/ ___   )  ( )     \n");
printf("| (   ) |      ) (  | (   ) |  ) (      | (  \\  ) (    \\/      )  ( | (   ) | )   ( | (    \\/ (    )|      )  ( \\/   )  |  | |   \n");
printf("| (___) |      | |  | |   | |  | |      | |   ) | (__          |  | | |   | | |   | | (__   | (____)|      |  |     /   )  | |   \n");
printf("|  ___  |      | |  | |   | |  | |      | |   | |  __)         |  | | |   | | |   | |  __)  |     __)      |  |   _/   /   | |    \n");
printf("| (   ) |      | |  | |   | |  | |      | |   ) | (            |  | | |   | | |   | | (     | (\\ (         |  |  /   _/    (_)    \n");
printf("| )   ( |      | |  | (___) |__) (___   | (__/  ) (____/\\   |\\_)  ) | (___) | (___) | (____/\\ ) \\ \\__   |\\_)  ) (   (__/\\   _     \n");
printf("|/     \\|      )_(  (_______)_______/   (______/(_______/   (____/  (_______|_______|_______//   \\__/   (____/  \\_______/  (_)    \n\n");
}



//Fonction finale affichage info: 

void affichage_info(joueuse* joueuse_ce_tour, map* la_map){
    plateau(la_map);
    matrice(la_map);
    if (getTourdeJoueuse(joueuse_ce_tour)==0 ){                                                                      
        tour_j1();
    }
    else {
        tour_j2();
    }
    affichage_cartes(joueuse_ce_tour);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------

//FONCTION AUXILIAIRE UTILISATION CAPITAL:

// Regarde si la joueuse a assez de capital
int verification_capital( int capital_voulu, int capital_reel){
    if (capital_voulu >capital_reel){
        printf (" Tu ne peux pas tu as seulement %d \n", capital_reel);
        return 1;
    }
    else {
        return 0;
    }
}

//demande à la joueuse combien de capital elle veut utliser et verifie qu'elle peut
int demande_capital(joueuse* joueuse_ce_tour){
    int i=1;
    long rep=0;
    while(i==1){
        printf("\033[36;01mCombien de capital souhaites-tu utiliser ?\033[00m\n");
        int MAX_LENGTH=3;
        char * buffer = (char *) malloc( MAX_LENGTH );
        char * buffer2 = (char *) malloc( MAX_LENGTH );
        fgets( buffer, MAX_LENGTH, stdin );
        rep = strtol( buffer, &buffer2, 10 );
        while ( buffer==buffer2){
            fgets( buffer, MAX_LENGTH, stdin );
            rep = strtol( buffer, &buffer2, 10 );
        }
            i=verification_capital(rep, getCapital(joueuse_ce_tour));                                    
    }
    return rep;
}


int verif_chgt(int zone1, int zone2, int zone3, map* la_map,int capital_utilise, double capital_1chgt, int capital_tous_chgt, double** matrice_chgt){
    if (zone1<1 ||zone1>getTaille(la_map) || zone2<1 ||zone2>getTaille(la_map) || zone3<1 ||zone3>getTaille(la_map)){     //pb
        printf("Les numeros des zones données ne sont pas possibles, en effet il y a %d zones\n", getTaille(la_map));
        return 1;
    }
    if (capital_utilise-capital_tous_chgt-capital_1chgt<0){
        printf("Il ne vous reste pas assez de capital\n");
        return 1;
    }
    double ** matrice= getMatrice(la_map);
    if (matrice[zone1-1][zone2-1]+matrice_chgt[zone1-1][zone2-1]+(capital_1chgt /10)<=1 && matrice[zone1-1][zone3-1]+matrice_chgt[zone1-1][zone3-1]-(capital_1chgt /10)>=0 ){                                
        return 0;
    }
    else{
        printf("Ces changements ne sont pas permis par la matrice de probabilite\n");
        return 1;
    }
}

int verif_chgt_Salhab(int zone1, int zone2, int zone3, map* la_map, int demande_chgt, double** matrice_chgt){
    if (zone1<1 ||zone1>getTaille(la_map) || zone2<1 ||zone2>getTaille(la_map) || zone3<1 ||zone3>getTaille(la_map)){     //pb
        printf("Les numeros des zones données ne sont pas possibles, en effet il y a %d zones\n", getTaille(la_map));
        return 1;
    }
    double ** matrice= getMatrice(la_map);
    if (matrice[zone1-1][zone2-1]+matrice_chgt[zone1-1][zone2-1]+(demande_chgt /10)<=1 && matrice[zone1-1][zone3-1]+matrice_chgt[zone1-1][zone3-1]-(demande_chgt /10)>=0 ){                                
        return 0;
    }
    else{
        printf("Ces changements ne sont pas permis par la matrice de probabilite\n");
        return 1;
    }
}

//retourne 1 si existe et active, 0sinon;
int effet_Salhab_interface(joueuse* joueuse_ce_tour){
    carte* main=getMain(joueuse_ce_tour);
    while (main!=NULL){
        if (getNom(main)==Salhab && getEtatCarte(main)==ACTIVE){
                return 1;
        }
        main=getCarteSuivante(main);
    }
    return 0;
}

//demande les chagements voulus 
void changement_prob(int capital_utilise, map* la_map, joueuse* j){
    int capital_tous_chgt=0;
    double** matrice_chgt=creer_graphe(getTaille(la_map));
    while (capital_utilise-capital_tous_chgt>0){
        long zone1;
        long zone2;
        long zone3;
        double capital_1chgt=0;
        int i=1;
        while (i==1){
            printf("\033[36;01mAu départ de quelle zone (numero de zone) veux-tu changer la proba ?\033[00m\n");
            int MAX_LENGTH=3;
            char * buffer = (char *) malloc( MAX_LENGTH );
            char * buffer2 = (char *) malloc( MAX_LENGTH );
            fgets( buffer, MAX_LENGTH, stdin );
            zone1 = strtol( buffer, &buffer2, 10 );
             while (buffer==buffer2){
                fgets( buffer, MAX_LENGTH, stdin );
                zone1 = strtol( buffer, &buffer2, 10 );
            }
            printf("\033[36;01m Vers quelle première zone (numero de zone) veux tu changer pour augmenter la proba ?\033[00m\n");
            buffer = (char *) malloc( MAX_LENGTH );
            buffer2 = (char *) malloc( MAX_LENGTH );
            fgets( buffer, MAX_LENGTH, stdin );
            zone2 = strtol( buffer, &buffer2, 10 );
            while (buffer==buffer2){
                fgets( buffer, MAX_LENGTH, stdin );
                zone2 = strtol( buffer, &buffer2, 10 );
            }
            printf(" \033[36;01mVers quelle deuxième zone (numero de zone) veux tu changer pour diminuer la proba ?\033[00m\n");
            buffer = (char *) malloc( MAX_LENGTH );
            buffer2 = (char *) malloc( MAX_LENGTH );
            fgets( buffer, MAX_LENGTH, stdin );
            zone3 = strtol( buffer, &buffer2, 10 );
            while (buffer==buffer2){
                fgets( buffer, MAX_LENGTH, stdin );
                zone3 = strtol( buffer, &buffer2, 10 );
            }
            if (effet_Salhab_interface(j)==1){
                double demande_chgt;
                printf("\033[36;01m De combien de décimal veux-tu changer la probabilité entre ces zones?\033[00m\n");
                buffer = (char *) malloc( MAX_LENGTH );
                buffer2 = (char *) malloc( MAX_LENGTH );
                fgets( buffer, MAX_LENGTH, stdin );
                demande_chgt= strtol( buffer, &buffer2, 10 );
                 while (buffer==buffer2){
                    fgets( buffer, MAX_LENGTH, stdin );
                    demande_chgt = strtol( buffer, &buffer2, 10 );
                }
                i=verif_chgt_Salhab(zone1,zone2,zone3, la_map, demande_chgt, matrice_chgt);
                capital_tous_chgt+=1;
            }
            else {
                printf("\033[36;01m Combien de capital souhaites-tu utiliser pour ce changement ?\033[00m\n");
                buffer = (char *) malloc( MAX_LENGTH );
                buffer2 = (char *) malloc( MAX_LENGTH );
                fgets( buffer, MAX_LENGTH, stdin );
                capital_1chgt= strtol( buffer, &buffer2, 10 );
                 while (buffer==buffer2){
                    fgets( buffer, MAX_LENGTH, stdin );
                    capital_1chgt = strtol( buffer, &buffer2, 10 );
                }
                i=verif_chgt(zone1, zone2,zone3, la_map, capital_utilise, capital_1chgt, capital_tous_chgt, matrice_chgt);
                if (i==0){
                  capital_tous_chgt+=capital_1chgt;  
                }
                
            }
        }
        matrice_chgt[zone1-1][zone2-1]=matrice_chgt[zone1-1][zone2-1]+capital_1chgt/10;
        matrice_chgt[zone1-1][zone3-1]=matrice_chgt[zone1-1][zone3-1]+(-1)*capital_1chgt/10;
        
    }
    changer_proba(la_map, matrice_chgt);
}

//retourne 1 si elle est active 0 sinon
int effet_rioboo(joueuse* joueuse_ce_tour){
    carte* main=getMain(joueuse_ce_tour);
    int i=0;
    while (main!=NULL){
        if (getNom(main)==Rioboo && getEtatCarte(main)==ACTIVE){
                return i;
        }
        main=getCarteSuivante(main);
        i+=1;
    }
    return 100;
}


//FONCTION UTILISATION CAPITAL
void utilisation_capital(joueuse * joueuse_ce_tour, map* la_map){
    if (effet_rioboo(joueuse_ce_tour)!=100){
        int j=effet_rioboo(joueuse_ce_tour);
        printf("Suite à l utilisation de la carte Rioboo au tour précédent, tu ne peux pas choisir ton capital\n");
        for (int i=0; i<getCapital(joueuse_ce_tour); i++){
            effet_Rioboo_prochain_tour(la_map, joueuse_ce_tour, parcourir_cliste(getMain(joueuse_ce_tour), j));
        }
        
    }
    else {
        int capital_utilise=demande_capital(joueuse_ce_tour );
        utiliser_montant_joueur(joueuse_ce_tour,capital_utilise); 
        changement_prob(capital_utilise, la_map, joueuse_ce_tour);
    }
    
    //matrice(la_map);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//FONCTION DEMANDE UTILISATION CARTE
int demande_carte(){
    int choix=0;
    while (choix!=1 && choix!=2){
        printf("\033[36;01mSouhaites-tu jouer une carte ?\033[00m\n");
        printf("1. Oui\n");
        printf("2. Non\n");
        printf("Entre 1 ou 2\n");
        int MAX_LENGTH=3;
        char * buffer = (char *) malloc( MAX_LENGTH );
        char * buffer2 = (char *) malloc( MAX_LENGTH );
        fgets( buffer, MAX_LENGTH, stdin );
        choix = strtol( buffer, &buffer2, 10 );
        while (buffer==buffer2){
            fgets( buffer, MAX_LENGTH, stdin );
            choix = strtol( buffer, &buffer2, 10 );
        }
    }
    if (choix==2){
        return 0;
    }
    else {
        int numero;
        printf ("\033[36;01mQuelles cartes veux-tu jouer ?\033[00m\n");
        printf ("Rentre le numero de la carte.\n");
        int MAX_LENGTH=3;
        char * buffer = (char *) malloc( MAX_LENGTH );
        char * buffer2 = (char *) malloc( MAX_LENGTH );
        fgets( buffer, MAX_LENGTH, stdin );
        numero = strtol( buffer, &buffer2, 10 );
        while (buffer==buffer2){
            fgets( buffer, MAX_LENGTH, stdin );
            numero = strtol( buffer, &buffer2, 10 );
        }
        return numero;
    }
}

//-----------------------------------------------------------------------
//FONCTION EN CAS D'ERREUR DANS LE NUMERO DE CARTE 
int redemande_carte(){
    int numero;
    printf("Tu ne possèdes pas cette carte, tu dois donc en choisir une autre! \n");
    printf ("\033[36;01mQuelles cartes veux-tu jouer ?\033[00m\n");
    printf ("Rentre le numero de la carte.\n");
    int MAX_LENGTH=3;
    char * buffer = (char *) malloc( MAX_LENGTH );
    char * buffer2 = (char *) malloc( MAX_LENGTH );
    fgets( buffer, MAX_LENGTH, stdin );
    numero = strtol( buffer, &buffer2, 10 );
    while (buffer==buffer2){
        fgets( buffer, MAX_LENGTH, stdin );
        numero = strtol( buffer, &buffer2, 10 );
    }
    return numero;
}

//---------------------------------------------------------------------
void plus_de_carte(){
    printf("Tu n as plus de cartes\n");
    printf("Tu as donc gaché ton tour, fait attention la prochaine fois\n");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// FONCTIONS AUXILIARES FIN JEU
void game_overj1(){
printf("_______  _______  _______  _______    _______           _______  _______   _________ __\n"); 
printf("(  ____ \\(  ___  )(       )(  ____ \\  (  ___  )|\\     /|(  ____ \\(  ____ )  \\__    _//  \\ \n");  
printf("| (    \\/| (   ) || () () || (    \\/  | (   ) || )   ( || (    \\/| (    )|     )  (  \\/) )   \n");
printf("| |      | (___) || || || || (__      | |   | || |   | || (__    | (____)|     |  |    | |  \n");
printf("| | ____ |  ___  || |(_)| ||  __)     | |   | |( (   ) )|  __)   |     __)     |  |    | |  \n");
printf("| | \\_  )| (   ) || |   | || (        | |   | | \\ \\_/ / | (      | (\\ (        |  |    | |  \n");
printf("| (___) || )   ( || )   ( || (____/\\  | (___) |  \\   /  | (____/\\| ) \\ \\__  |\\_)  )  __) (_   \n");
printf("(_______)|/     \\||/     \\|(_______/  (_______)   \\_/   (_______/|/   \\__/  (____/   \\____/   \n");
}

void game_overj2(){
    printf(" _______  _______  _______  _______    _______           _______  _______   _________ _______   \n");
    printf("(  ____ \\(  ___  )(       )(  ____ \\  (  ___  )|\\     /|(  ____ \\(  ____ )  \\__    _// ___   )    \n");
    printf("| (    \\/| (   ) || () () || (    \\/  | (   ) || )   ( || (    \\/| (    )|     )  (  \\/   )  |   \n");
    printf("| |      | (___) || || || || (__      | |   | || |   | || (__    | (____)|     |  |      /   )    \n");
    printf("| | ____ |  ___  || |(_)| ||  __)     | |   | |( (   ) )|  __)   |     __)     |  |    _/   /    \n");
    printf("| | \\_  )| (   ) || |   | || (        | |   | | \\ \\_/ / | (      | (\\ (        |  |   /   _/    \n");
    printf("| (___) || )   ( || )   ( || (____/\\  | (___) |  \\   /  | (____/\\| ) \\ \\__  |\\_)  )  (   (__/\\   \n");
    printf("(_______)|/     \\||/     \\|(_______/  (_______)   \\_/   (_______/|/   \\__/  (____/   \\_______/   \n");
}

void victoirej1(){
printf("         _________ _______ _________ _______ _________ _______  _______    _______  _______           _______   _________ __       _   \n");
printf("|\\     /|\\__   __/(  ____ \\__   __/(  ___  )\\__   __/(  ____ )(  ____ \\  (  ____ )(  ___  )|\\     /|(  ____ )  \\__    _//  \\      ( )   \n");
printf("| )   ( |   ) (   | (    \\/  ) (   | (   ) |   ) (   | (    )|| (    \\/  | (    )|| (   ) || )   ( || (    )|     )  (  \\/) )     | |    \n");
printf("| |   | |   | |   | |        | |   | |   | |   | |   | (____)|| (__      | (____)|| |   | || |   | || (____)|     |  |    | |     | |    \n");
printf("( (   ) )   | |   | |        | |   | |   | |   | |   |     __)|  __)     |  _____)| |   | || |   | ||     __)     |  |    | |     | |    \n");
printf(" \\ \\_/ /    | |   | |        | |   | |   | |   | |   | (\\ (   | (        | (      | |   | || |   | || (\\ (        |  |    | |     (_)     \n");
printf("  \\   /  ___) (___| (____/\\  | |   | (___) |___) (___| ) \\ \\__| (____/\\  | )      | (___) || (___) || ) \\ \\__  |\\_)  )  __) (_     _   \n");
printf("   \\_/   \\_______/(_______/  )_(   (_______)\\_______/|/   \\__/(_______/  |/       (_______)(_______)|/   \\__/  (____/   \\____/    (_)    \n");
}

void victoirej2(){
printf("         _________ _______ _________ _______ _________ _______  _______    _______  _______           _______   _________ _______    _    \n");
printf("|\\     /|\\__   __/(  ____ \\__   __/(  ___  )\\__   __/(  ____ )(  ____ \\  (  ____ )(  ___  )|\\     /|(  ____ )  \\__    _// ___    )  ( )    \n");
printf("| )   ( |   ) (   | (    \\/   ) (   | (   ) |   ) (   | (    )|| (    \\/  | (    )|| (   ) || )   ( || (    )|     )  (  \\/   )  |  | |   \n");
printf("| |   | |   | |   | |         | |   | |   | |   | |   | (____)|| (__      | (____)|| |   | || |   | || (____)|     |  |      /   )  | |    \n");
printf("( (   ) )   | |   | |         | |   | |   | |   | |   |     __)|  __)     |  _____)| |   | || |   | ||     __)     |  |    _/   /   | |    \n");
printf(" \\ \\_/ /    | |   | |         | |   | |   | |   | |   | (\\ (   | (        | (      | |   | || |   | || (\\ (        |  |   /   _/    (_)     \n");
printf("  \\   /  ___) (___| (____/\\   | |   | (___) |___) (___| ) \\ \\__| (____/\\  | )      | (___) || (___) || ) \\ \\__  |\\_)  )  (   (__/\\   _      \n");
printf("   \\_/   \\_______/(_______/   )_(   (_______)\\_______/|/   \\__/(_______/  |/       (_______)(_______)|/   \\__/  (____/   \\_______/  (_)     \n");
}

//FONCTION FIN JEU
void fin_jeu(joueuse* j1, joueuse* j2){
    if (as_tu_perdu(j1)==0 && as_tu_perdu(j2)==1){
        game_overj1();
        victoirej2();
    }
    else if (as_tu_perdu(j2)==0 && as_tu_perdu(j1)==1){
        game_overj2();
        victoirej1();
    }
    else if (as_tu_perdu(j1)==0 && as_tu_perdu(j2)==0){
        game_overj1();
        game_overj2();
    }
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//FONCTION NOMBRE DE PERSONNES ENCORE EN VIE
void nb_en_vie(int nb_j1, int nb_j2){
    printf("\033[31;01mJoueur1, il te reste encore %d personnages en vie !\033[00m\n", nb_j1);
    printf("\033[31;01mJoueur2, il te reste encore %d personnages en vie !\033[00m\n\n", nb_j2);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//FONCTION AUXILIAIRE LANCEMENT DU JEU
void laviedemarkov(){
printf(" _        _______              _________ _______      ______   _______      _______  _______  _______  _        _______   \n");         
printf("( \\      (  ___  )    |\\     /|\\__   __/(  ____ \\    (  __  \\ (  ____ \\    (       )(  ___  )(  ____ )| \\    /\\(  ___  )|\\     /|    \n"); 
printf("| (      | (   ) |    | )   ( |   ) (   | (    \\/    | (  \\  )| (    \\/    | () () || (   ) || (    )||  \\  / /| (   ) || )   ( |    \n");
printf("| |      | (___) |    | |   | |   | |   | (__        | |   ) || (__        | || || || (___) || (____)||  (_/ / | |   | || |   | |    \n");
printf("| |      |  ___  |    ( (   ) )   | |   |  __)       | |   | ||  __)       | |(_)| ||  ___  ||     __)|   _ (  | |   | |( (   ) )    \n");
printf("| |      | (   ) |     \\ \\_/ /    | |   | (          | |   ) || (          | |   | || (   ) || (\\ (   |  ( \\ \\ | |   | | \\ \\_/ /     \n");
printf("| (____/\\| )   ( |      \\   /  ___) (___| (____/\\    | (__/  )| (____/\\    | )   ( || )   ( || ) \\ \\__|  /  \\ \\| (___) |  \\   /      \n");
printf("(_______/|/     \\|       \\_/   \\_______/(_______/    (______/ (_______/    |/     \\||/     \\||/   \\__/|_/    \\/(_______)   \\_/       \n"); 
}

// FONCTION LANCEMENT DU JEU
void lancement_jeu(){
    laviedemarkov();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//FONCTION DEMANDANT OU DEPLACER LE MONSTRE: attention j'ai pas le nombre de zones je peux pas demander si le numero est correct
int deplacement_montre(){
    int choix=0;
    printf("\033[36;01mOù souhaites-tu déplacer le monstre ?\033[00m\n");
    printf("Entre le numero d une zone\n");
    int MAX_LENGTH=3;
    char * buffer = (char *) malloc( MAX_LENGTH );
    char * buffer2 = (char *) malloc( MAX_LENGTH );
    fgets( buffer, MAX_LENGTH, stdin );
    choix = strtol( buffer, &buffer2, 10 );
    while (buffer==buffer2){
        fgets( buffer, MAX_LENGTH, stdin );
        choix = strtol( buffer, &buffer2, 10 );
    }
    return choix; 
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//FONCTION DEAMNDANT AUX JOUEURS QUEL PERSO IL VEUT DEPLACER : meme pb
int choix_perso(){
    int choix;
    printf("\033[36;01mQuel personnage souhaites-tu choisir?\033[00m\n");
    printf("Entre le numero de la zone sur laquelle se situe ce personnage.\n");
    int MAX_LENGTH=3;
    char * buffer = (char *) malloc( MAX_LENGTH );
    char * buffer2 = (char *) malloc( MAX_LENGTH );
    fgets( buffer, MAX_LENGTH, stdin );
    choix = strtol( buffer, &buffer2, 10 );
    while (buffer==buffer2){
        fgets( buffer, MAX_LENGTH, stdin );
        choix = strtol( buffer, &buffer2, 10 );
    }
    return choix ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//FONCTION DEAMNDANT AUX JOUEURS QUEL PERSO ADVERSE IL VEUT DEPLACER : meme pb
int choix_perso_adverse(){
    int choix;
    printf("\033[36;01mQuel personnage adverse souhaites-tu choisir ?\033[00m\n");
    printf("Entre le numero de la zone sur laquelle se situe ce personnage.\n");
    int MAX_LENGTH=3;
    char * buffer = (char *) malloc( MAX_LENGTH );
    char * buffer2 = (char *) malloc( MAX_LENGTH );
    fgets( buffer, MAX_LENGTH, stdin );
    choix = strtol( buffer, &buffer2, 10 );
    while (buffer==buffer2){
        fgets( buffer, MAX_LENGTH, stdin );
        choix = strtol( buffer, &buffer2, 10 );
    }
    return choix ;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//FONCTION DEAMNDANT AUX JOUEURS QUELLE ZONE IL VEUT DEPLACER : meme pb
int choix_zone(){
    int choix;
    printf("\033[36;01mQuelle zone choisis-tu  pour deplacer le personnage/monstre?\033[00m\n");
    printf("Entre le numero de la zone .\n");
    int MAX_LENGTH=3;
    char * buffer = (char *) malloc( MAX_LENGTH );
    char * buffer2 = (char *) malloc( MAX_LENGTH );
    fgets( buffer, MAX_LENGTH, stdin );
    choix = strtol( buffer, &buffer2, 10 );
    while (buffer==buffer2){
        fgets( buffer, MAX_LENGTH, stdin );
        choix = strtol( buffer, &buffer2, 10 );
    }
    return choix ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//FONCTION DEAMNDANT AUX JOUEURS QUEL MONSTRE IL VEUT DEPLACER : meme pb
int choix_monstre(){
    int choix;
    printf("\033[36;01mQuel monstre souhaites-tu choisir ?\033[00m\n");
    printf("Entre le numero de la zone  sur laquelle se situe ce monstre.\n");
    int MAX_LENGTH=3;
    char * buffer = (char *) malloc( MAX_LENGTH );
    char * buffer2 = (char *) malloc( MAX_LENGTH );
    fgets( buffer, MAX_LENGTH, stdin );
    choix = strtol( buffer, &buffer2, 10 );
    while (buffer==buffer2){
        fgets( buffer, MAX_LENGTH, stdin );
        choix = strtol( buffer, &buffer2, 10 );
    }
    return choix ;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void fin_tour(){
    printf("_______________________________________________________________________________________________________________________\n");
    printf("_______________________________________________________________________________________________________________________\n");
    printf("\n");
}
