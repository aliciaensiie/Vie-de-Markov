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
#include <time.h>

void initialisation_carte(int nom, carte* macarte){

//typedef struct carte carte

    switch (nom) {

        case 1 : 

        setNom(Merabet,macarte);
        setDesc( "Merabet : Pendant vos 3 prochains tours, votre capital augmente de 2." ,macarte) ;
        setEtatCarte(INACTIVE ,macarte); 
        setNbTour(3,macarte);
        break;

        case 2 : 

        setNom(Bannour ,macarte) ;
        setDesc( "Bannour : Choisissez deux zones, les personnages présents sur ces deux zones sont échangés.",macarte) ;
        setEtatCarte(INACTIVE,macarte) ; 
        setNbTour(0,macarte);
        break;

        case 3 : 

        setNom(Honore,macarte);
        setDesc("Honore : Chaque monstre se déplace 3 fois. Chaque membre d école qu un monstre rencontre est mangé.",macarte)  ;
        setEtatCarte(INACTIVE,macarte) ; 
        setNbTour(0,macarte);
        break;

        case 4:

        setNom(Rioboo,macarte) ;
        setDesc("Rioboo : Lors du prochain tour, le joueur adverse ne choisis pas comment est utilisé son capital. Chaque point de capital est utilisé aléatoirement.",macarte)  ;
        setEtatCarte(INACTIVE,macarte);  
        setNbTour(2,macarte);
        break;

        case 5 :

        setNom( Goilard ,macarte) ;
        setDesc("Goilard : Lors du prochain tour et du suivant, c est vous qui jouez. Lors des deux tours suivant, c'est la joueuse adverse qui joue.",macarte)  ;
        setEtatCarte( INACTIVE,macarte) ;  
        setNbTour(4,macarte) ;
        break;

        case 6 :

        setNom(Bourard,macarte)  ;
        setDesc("Bourard : Lors du prochain déplacement, si deux membres d écoles adverses se retrouvent sur la même zone, ils se déplacent de nouveau. Si ces deux membres sont sur la zone du monstre avant le second déplacement, ils ne sont pas mangés. On recommence l'opération au plus 100 fois, jusqu'à ce que les membres des écoles adverses soient sur des zones distinctes.",macarte)  ;
        setEtatCarte(INACTIVE,macarte)  ; 
        setNbTour(2,macarte);
        break;

        case 7 :

        setNom( Munante,macarte) ;
        setDesc("Munante : Les membres d écoles présents sur la zone où était un monstre avant son dernier déplacement sont mangés.",macarte)  ;
        setEtatCarte( INACTIVE,macarte) ; 
        setNbTour(0,macarte);
        break;

        case 8 : 

        setNom(Benezet,macarte)  ;
        setDesc("Benezet : Déplacez un des monstres sur la zone de votre choix. Si un membre d école se trouve sur la zone du monstre, il n est pas mangé.",macarte)  ;
        setEtatCarte( INACTIVE,macarte) ;  
        setNbTour(0,macarte) ;
        break;


        case 9 :

        setNom(Ligozat,macarte)  ;
        setDesc( "Ligozat : Choisissez un membre de votre école, il effectue désormais deux déplacements au lieu d un à chaque tour.",macarte) ;
        setEtatCarte(INACTIVE,macarte)  ;  
        setNbTour(-1,macarte) ;
        break;

        case 10 :

        setNom(Mouilleron,macarte)  ;
        setDesc( "Mouilleron : Choisissez un membre de l école de la joueuse adverse. Ce membre devient un membre de votre école.",macarte) ;
        setEtatCarte( INACTIVE,macarte) ; 
        setNbTour(-1,macarte) ;
        break;

        case 11 :

        setNom( DembeleCabot,macarte) ;
        setDesc("DembeleCabot : Sacrifiez un membre de votre école de votre choix. Vous avez 15 points de capital en plus à votre prochain tour.",macarte)  ;
        setEtatCarte(INACTIVE,macarte)  ; 
        setNbTour(1,macarte) ;
        break;

        case 12 :

        setNom(  Pacave ,macarte);
        setDesc("Pacave : Créez une nouvelle zone. Les membres de votre école sont les seuls à pouvoir se déplacer sur cette zone. Un membre de l école de l autre joueuse qui devrait se déplacer sur cette zone ne se déplace pas. La probabilité d'aller sur cette zone est de 0. Depuis cette zone, la probabilité de rester sur cette zone est 1",macarte)  ;
        setEtatCarte( INACTIVE,macarte) ; 
        setNbTour(0,macarte) ;
        break;

        case 13 :

        setNom( Huet,macarte) ;
        setDesc("Huet : Chaque zone effectue une rotation de probabilité. La probabilité d aller de la zone i à la zone j devient la probabilité d'aller de la zone i à la zone j + 1. La probabilité d'aller de la zone i à la zone 10 devient la probabilité d'aller de la zone i à la zone 1.",macarte)  ;
        setEtatCarte(INACTIVE,macarte)  ; 
        setNbTour(0,macarte) ;
        break;
    

        case 14 :

        setNom(Matias,macarte)  ;
        setDesc("Matias : Chaque monstre disparaît pendant 2 tours. Il réapparaîtra sur la zone d où il est parti.",macarte)  ;
        setEtatCarte( INACTIVE,macarte) ; 
        setNbTour( 3,macarte);
        break;

        case 15 :

        setNom(Salhab,macarte)  ;
        setDesc( "Salhab : Pendant vos 3 prochains tours, un point de capital permet de déplacer une quantité 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9 ou 1 de probabilité.",macarte) ;
        setEtatCarte( INACTIVE,macarte) ; 
        setNbTour(4,macarte) ;
        break;

        case 16 :

        setNom(PulidoNino,macarte)  ;
        setDesc("PulidoNino : Mettez à 0 les probabilités permettant de sortir de la zone de chaque monstre et mettez à 1 la probabilité de rester dans la zone de chaque monstre.",macarte)  ;
        setEtatCarte(INACTIVE,macarte)  ; 
        setNbTour(0,macarte) ;
        break;

        case 17 : 

        setNom(Watel,macarte)  ;
        setDesc( "Watel : Choisissez un membre de votre école, il devient FISA et effectue désormais son déplacement un tour sur deux.",macarte) ;
        setEtatCarte(INACTIVE,macarte)  ; 
        setNbTour(-1,macarte) ;
        break;

        case 18:

        setNom(Szafranski,macarte)  ;
        setDesc("Szafranski : un monstre sera ajouté sur la zone 1, un membre de votre école sera ajouté sur la zone 2 et un membre de l école adverse sera ajouté sur la zone 3. Si un membre d école se trouve sur la même zone qu'un monstre, il n'est pas mangé.",macarte)  ;
        setEtatCarte(INACTIVE,macarte)  ; 
        setNbTour(0,macarte) ;
        break;
        case 19 :

        setNom(Forest,macarte)  ;
        setDesc("Forest : Mettez toutes les probabilités à 0. Puis, pour chaque zone, la probabilité de se déplacer de cette zone vers la zone contenant le monstre passe à 0.5 (si il y a plusieurs monstres, un des monstres est choisi aléatoirement) ; et la probabilité de se déplacer de cette zone vers une autre zone ne contenant pas de monstre choisie aléatoirement passe également à 0.5",macarte)  ;
        setEtatCarte(INACTIVE,macarte)  ;  
        setNbTour(0,macarte) ;
        break;

        case 20 :

        setNom(Prevel,macarte)  ;
        setDesc( "Prevel : Pendant 4 tours, les membres de votre école ne peuvent être mangés par un monstre. Si ils sont sur sa zone à la fin du tour, rien ne se passe, ils restent sur cette case.",macarte) ;
        setEtatCarte(INACTIVE,macarte)  ; 
        setNbTour(5,macarte) ;
        break;

        default :
            break;

    }
}



//___________________________________________________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________________________________________________


void effet_Merabet(carte* c)
{
    setEtatCarte(ACTIVE, c);
    
}

void effet_Merabet_prochain_tour(joueuse* j, carte* c){
    setCapital(getCapital(j) + 2,j);
    setNbTour(getNbTour(c)-1, c);
    if (getNbTour(c)==0){
        setEtatCarte(UTILISEE, c);
    }
}

void effet_Bannour(zone* zone1, zone* zone2, carte* c)
{   
    setEtatCarte(UTILISEE, c);
    personnage* temp = getPj_Zone(zone1);
    setPjZone(getPj_Zone(zone2), zone1);
    setPjZone(temp, zone2);
    
}

void effet_Honore(personnage* monstre, joueuse* j1, joueuse* j2, map* la_map, carte* c)
{
    setEtatCarte(UTILISEE, c);
    personnage* liste_monstre=monstre;
    for (int i =0; i<2; i+=1){
        while(liste_monstre!=NULL){
            move_personnage( liste_monstre, la_map);
            liste_monstre=getPersonnageSuivantJoueur(liste_monstre);
        }
        manger_les_persos(j1,j2,monstre);
        liste_monstre=monstre;
    }
    
}
/* z2 est la zone pivot*/
void effet_Rioboo(joueuse* j_adverse, carte* c)
{
    setEtatCarte(UTILISEE, c);
    carte* new_carte=malloc(getSizeOfCarte());
    memcpy(new_carte, c, getSizeOfCarte());
    setEtatCarte(ACTIVE, new_carte);
    setMain( ajouter_cliste(getMain(j_adverse),new_carte), j_adverse);
    
}


//matrice set aleatoirement 
void effet_Rioboo_prochain_tour(map* la_map, joueuse* j, carte* c){
        srand(time(NULL));
        double** matrice = getMatrice(la_map);
        int capital = getCapital(j);
        int i=0;
        while(i<capital)
            {
                int z1 = rand()%10;
                int z2 = rand()%10;
                int z3 = rand()%10;
                if(matrice[z1][z2]>0 && matrice[z1][z3]<1){
                    matrice[z1][z2] -=0.1;
                    matrice[z1][z3] +=0.1;
                    i+=1;
                }
                
            }
        setMatrice(matrice,la_map);
        setEtatCarte(UTILISEE, c); 
    
    
}


//Je passe
void effet_Goilard(carte* c, joueuse* j_adverse)  
{
    setEtatCarte(ACTIVE, c);
    carte* new_carte=malloc(getSizeOfCarte());
    memcpy(new_carte, c, getSizeOfCarte());
    setEtatCarte(ACTIVE, new_carte);
    setMain( ajouter_cliste(getMain(j_adverse),new_carte), j_adverse);
            
}

//0 tu joues, 1 tu passes
int effet_Goilard_prochain_tour(carte* c, joueuse* joueuse_ce_tour){
    setNbTour(getNbTour(c)-1, c);
    if (getNbTour(c)==0){
        setEtatCarte(UTILISEE, c);
    }
    if ((int)getProprietaireCarte(c)==getTourdeJoueuse(joueuse_ce_tour)){
        if (getNbTour(c)+1==4 || getNbTour(c)+1==3 ){
            return 0;
        }
        else{
            return 1;
        }
    }
    else {
        if (getNbTour(c)+1==2 || getNbTour(c)+1==1 ){
            return 0;
        }
        else{
            return 1;
        }
    }
    
}

/*attention changer zone dans perso et perso dans zone*/
void effet_Bourard(carte* c)
{
    setEtatCarte(ACTIVE, c);
    
}

//après un premier move, remove les personnage autant fois qu'il faut pour qu'il ne soit plus sur les mêmes cases
void effet_Bourard_prochain_tour(map* la_map, carte* la_carte){
    int recommencer=0;
    int nbrecommencement=0;
    while (recommencer==0 && nbrecommencement<100 ){
        for (int i=0; i<getTaille(la_map); i+=1){
        personnage* pj_cette_zone=getPj_Zone(zone_recherche(la_map, i));
        
        int i= getProprietaireJoueuse(pj_cette_zone);
                while (i==2){
                    if (getPersonnageSuivantZone( pj_cette_zone)!=NULL){
                        pj_cette_zone=getPersonnageSuivantZone(pj_cette_zone);
                        i=getProprietaireJoueuse(pj_cette_zone);;
                    }
                    else{
                        return; 
                    }
                }
                
                personnage* pj_liste=pj_cette_zone;
                int j=3;
                while (i==j && getPersonnageSuivantZone( pj_liste)!=NULL){
                        pj_liste=getPersonnageSuivantZone( pj_liste);
                        j=getProprietaireJoueuse(pj_liste);
                }
                if (i!=j){
                        nbrecommencement+=1;
                        personnage* pj_liste2=pj_cette_zone; 
                        while (pj_liste2!=NULL){
                            if (getProprietaireJoueuse(pj_liste2) !=2){
                                    personnage* move=pj_liste2;
                                    pj_liste2=getPersonnageSuivantZone(pj_liste2);
                                    move_personnage(move, la_map);
                            }
                            else{
                                    pj_liste2=getPersonnageSuivantZone(pj_liste2);
                            }

                        }
                }
                else{recommencer=1;}
    }
    }
    setEtatCarte(UTILISEE, la_carte);
    
}


void effet_Munante(personnage* perso_monstre, map* la_map, carte* c )
{
    setEtatCarte(UTILISEE, c);
    while (perso_monstre!=NULL){
        int ancien_index = getZonePrec(perso_monstre);
        zone* ancienne_position = zone_recherche(la_map, ancien_index);
        personnage* perso_present = getPj_Zone(ancienne_position);
        for (int i = 0 ; i < taille_pzliste(perso_present) ; i+=1)
            {
                if (getProprietaireJoueuse(parcourir_pzliste(perso_present,i)) == 0 || getProprietaireJoueuse(parcourir_pzliste(perso_present,i)) == 1){
                    setEtatPerso(mort,parcourir_pzliste(perso_present,i));
                }  
            }
        perso_monstre=getPersonnageSuivantJoueur(perso_monstre);
    }
    
}


void effet_Benezet(carte* c, map* la_map)
{
    setEtatCarte(UTILISEE, c);
    int possible=0;
    while (possible==0){
        int idm = choix_monstre();
        zone* zmonstre= zone_recherche(la_map, idm-1);
        personnage* pj_monstre=getPj_Zone(zmonstre);
        if (pj_monstre !=NULL){
            while (getProprietaireJoueuse(pj_monstre)!=2 && getPersonnageSuivantZone(pj_monstre)!=NULL){
                pj_monstre=getPersonnageSuivantZone(pj_monstre);
            }
            if (getProprietaireJoueuse(pj_monstre)==2){
                possible=1;
                int possible2=0;
                while(possible2==0){
                    int idz = choix_zone(); 
                    if (idz>0 && idz<11){
                        possible2=1;
                        setPjZone( enlever_pzliste(getPj_Zone(zmonstre),pj_monstre), zmonstre);
                        setZonePrec(idm-1, pj_monstre);
                        setZone(idz-1, pj_monstre);
                        setPjZone( ajouter_pzliste(getPj_Zone(zone_recherche(la_map, idz-1)), pj_monstre), zone_recherche(la_map, idz-1));

                    }
                }
            }
        }
        
    }   
    
}


void effet_Ligozat(map* la_map, carte* c, joueuse* j)
{
    setEtatCarte(ACTIVE, c);
    int possible=0;
    while (possible==0){
        int idp = choix_perso();
        zone* zperso= zone_recherche(la_map, idp-1);
        personnage* pj_perso=getPj_Zone(zperso);
        while ((int)getProprietaireJoueuse(pj_perso)!=getTourdeJoueuse(j) && getPersonnageSuivantZone(pj_perso)!=NULL){
            pj_perso=getPersonnageSuivantZone(pj_perso);
        }
        if ((int)getProprietaireJoueuse(pj_perso)==getTourdeJoueuse(j)){
            possible=1;
            enum titre* pouvoir=getPouvoirs(pj_perso);
            int i=0;
            while (pouvoir[i]!=0){
                i+=1;
            }
            pouvoir[i]=Ligozat;
            
        }
    }   
}


void effet_Mouilleron( map* la_map, carte* c, joueuse* j_adverse,  joueuse* j)
{    
    setEtatCarte(UTILISEE, c);
    int tour_de_joueur_adverse=getTourdeJoueuse(j_adverse);
    int possible=0;
    while (possible==0){
        int idp = choix_perso_adverse();
        if (idp>0 && idp<getTaille(la_map)+1){
            zone* zperso= zone_recherche(la_map, idp-1);
            personnage* pj_perso=getPj_Zone(zperso);
            if(pj_perso!=NULL){
                while ((int)getProprietaireJoueuse(pj_perso)!= tour_de_joueur_adverse && getPersonnageSuivantZone(pj_perso)!=NULL){
                    pj_perso=getPersonnageSuivantZone(pj_perso);
                }
                if ((int)getProprietaireJoueuse(pj_perso)==tour_de_joueur_adverse){
                    possible=1;
                    setMembresJoueuse(enlever_pjliste(membre_joueur(j_adverse),pj_perso), j_adverse);
                    setMembresJoueuse(ajouter_pjliste(membre_joueur(j),pj_perso), j);
                    setProprietaireJoueuse(getTourdeJoueuse(j), pj_perso);
                    
                } 
            }
            
        }
        
    }
}


/*parcourir personnage de joueuse et checker les zones */
void effet_Dembele_Cabot(joueuse* j, carte* c, map* la_map)
{
    setEtatCarte(ACTIVE, c);
    int tour_de_joueur=getTourdeJoueuse(j);
    int possible=0;
    while (possible==0){
        int idp = choix_perso();
        zone* zperso= zone_recherche(la_map, idp-1);
        personnage* pj_perso=getPj_Zone(zperso);
        while ((int)getProprietaireJoueuse(pj_perso)!= tour_de_joueur && getPersonnageSuivantZone(pj_perso)!=NULL){
            pj_perso=getPersonnageSuivantZone(pj_perso);
        }
        if ((int)getProprietaireJoueuse(pj_perso)==tour_de_joueur){
            possible=1;
            setEtatPerso(mort,pj_perso);
        }
    }

}

void effet_Dembele_Cabot_prochain_tour(joueuse* j, carte* la_carte){
    setCapital(20, j);
    setNbTour(getNbTour(la_carte)-1, la_carte);
    if (getNbTour(la_carte)==0){
        setEtatCarte(UTILISEE, la_carte);
    }

}


void effet_Pacave(map* la_map, carte* c, joueuse* jadverse)
{
    setEtatCarte(ACTIVE, c);
    double** mat_courante= getMatrice(la_map);
    double** new_mat = creer_graphe(11);
    for (int i =0; i<11; i+=1)
        {
            for(int j=0; j<11; j+=1)
            {
                if (i==10 && j==10){
                    new_mat[i][j]=1;
                }
                else if (i==10 || j==10){
                    new_mat[i][j] = 0;      
                }   
                else {new_mat[i][j]=mat_courante[i][j];}
            }
        }
    free_graphe(mat_courante, getTaille(la_map));
    setMatrice(new_mat,la_map);

    setTaille(la_map, 11);

    zone* new_zone=malloc(getSizeOfZone());
    setId(10, new_zone);
    setPjZone(NULL, new_zone);
    setZoneSuivante(new_zone, NULL);
    zone* liste_zone=getCases(la_map);
    while (getZoneSuivante(liste_zone)!=NULL){
        liste_zone=getZoneSuivante(liste_zone);
    }
    setZoneSuivante(liste_zone, new_zone);

    personnage* pa=membre_joueur(jadverse);
    while (pa!=NULL){
        enum titre* pouvoir= getPouvoirs(pa);
        int i=0;
        while (pouvoir[i]!=0){
            i+=1;
        }
        pouvoir[i]=Pacave;
        pa=getPersonnageSuivantJoueur(pa);
    }
    
}


void effet_Huet(map* la_map, carte* c)
{
    setEtatCarte(UTILISEE, c);
    double** matrice = getMatrice(la_map);
    int taille=getTaille(la_map);
    for (int i=0; i<taille; i++)
        {
            double premier;
            for(int j=0; j<taille; j++)
                {
                    if (j==0){
                        premier= matrice[i][j];
                    }
                    else {} ;
                    if (j==taille-1)
                        {
                            matrice[i][taille-1]=premier;
                        }
                   else{matrice[i][j]=matrice[i][j+1]; }
                }
        }
    setMatrice(matrice,la_map);
}

// Warning l'activztion de cette carte doit être pris en compte dans move perso
void effet_Matias(carte* c, joueuse* monstre) 
{
    setEtatCarte(ACTIVE, c);
    personnage* pmonstre=membre_joueur(monstre);
    while(pmonstre!=NULL){
        setEtatPerso(mort, pmonstre);
        pmonstre=getPersonnageSuivantJoueur(pmonstre);
    }

}

void effet_Matias_prochain_tour(carte* c, joueuse* monstre){
    setNbTour(getNbTour(c)-1,c);
    if (getNbTour(c)==0){
        setEtatCarte(UTILISEE, c);
        personnage* pmonstre=membre_joueur(monstre);
        while(pmonstre!=NULL){
            setEtatPerso(vivant, pmonstre);
            pmonstre=getPersonnageSuivantJoueur(pmonstre);
        }
    }
}

//  warning l'activation de cette carte doit être pris en compte dans utilisation capital
void effet_Salhab(carte* c)
{
    setEtatCarte(ACTIVE, c); 
}

void effet_Salhab_prochain_tour(carte* c){
    setNbTour(getNbTour(c)-1,c);
    if (getNbTour(c)==0){
        setEtatCarte(UTILISEE, c);
    }
}

void effet_Pulido(carte* c, map* la_map, joueuse* monstre)
{
    setEtatCarte(UTILISEE, c);
    double** mat_courante= getMatrice(la_map);
    personnage* pmonstre= membre_joueur(monstre);
    while(pmonstre!=NULL){
        for(int i=0; i<getTaille(la_map); i+=1){
            mat_courante[getZone(pmonstre)][i]=0;
        }
        mat_courante[getZone(pmonstre)][getZone(pmonstre)]=1;
        pmonstre=getPersonnageSuivantJoueur(pmonstre);
    }
    
    
}

void effet_Watel(carte* c, map* la_map, joueuse* j)
{
    setEtatCarte(ACTIVE, c);
    int possible=0;
    while (possible==0){
        int idp = choix_perso();
        zone* zperso= zone_recherche(la_map, idp-1);
        personnage* pj_perso=getPj_Zone(zperso);
        while ((int)getProprietaireJoueuse(pj_perso)!=getTourdeJoueuse(j) && getPersonnageSuivantZone(pj_perso)!=NULL){
            pj_perso=getPersonnageSuivantZone(pj_perso);
        }
        if ((int)getProprietaireJoueuse(pj_perso)==getTourdeJoueuse(j)){
            possible=1;
            enum titre* pouvoir=getPouvoirs(pj_perso);
            int i=0;
            while (pouvoir[i]!=0){
                i+=1;
            }
            pouvoir[i]=Watel;
            
        }
    }   


}

void effet_Watel_prochain_tour(carte* c){
    setNbTour(getNbTour(c)+1, c);
}



void effet_Szafranski(carte* c,map* la_map, joueuse* joueuse_actuelle, joueuse* joueuse_adverse, joueuse* monstre)
{
    setEtatCarte(UTILISEE, c);
    personnage* pmonstre= creer_personnage(2, la_map);
    setZone(0,pmonstre );
    setMembresJoueuse(ajouter_pjliste(membre_joueur(monstre), pmonstre), monstre);

    int tour=getTourdeJoueuse(joueuse_actuelle);

    personnage* pjac= creer_personnage(getTourdeJoueuse(joueuse_actuelle), la_map);
    
    if(tour==1){
        setPjZone( enlever_pzliste(getPj_Zone(zone_recherche(la_map,getZone( pjac))),pjac), zone_recherche(la_map, getZone( pjac))) ;
        setZone(2,pjac );
        setPjZone(ajouter_pzliste(getPj_Zone(zone_recherche(la_map, 2)), pjac), zone_recherche(la_map, 2));
    }
    else{
        setPjZone( enlever_pzliste(getPj_Zone(zone_recherche(la_map,getZone( pjac))),pjac), zone_recherche(la_map, getZone( pjac))) ;
        setZone(1,pjac );
        setPjZone(ajouter_pzliste(getPj_Zone(zone_recherche(la_map, 1)), pjac), zone_recherche(la_map, 1));
    }
    setMembresJoueuse(ajouter_pjliste(membre_joueur(joueuse_actuelle), pjac), joueuse_actuelle);

    personnage* pjad;
    if (tour==0){
        pjad= creer_personnage(1, la_map);
        setPjZone( enlever_pzliste(getPj_Zone(zone_recherche(la_map,getZone( pjad))),pjad), zone_recherche(la_map, getZone( pjad))) ;
        setZone(2,pjad );
        setPjZone(ajouter_pzliste(getPj_Zone(zone_recherche(la_map, 2)), pjad), zone_recherche(la_map, 2));
    }
    else{
        pjad= creer_personnage(1, la_map);
        setPjZone( enlever_pzliste(getPj_Zone(zone_recherche(la_map,getZone( pjad))),pjad), zone_recherche(la_map, getZone( pjad))) ;
        setZone(1,pjad );
        setPjZone(ajouter_pzliste(getPj_Zone(zone_recherche(la_map, 1)), pjad), zone_recherche(la_map, 1));
    }
    
    
    setMembresJoueuse(ajouter_pjliste(membre_joueur(joueuse_adverse), pjad), joueuse_adverse);

}

void effet_Forest(carte* c,joueuse* monstre, map* la_map )
{
    setEtatCarte(UTILISEE, c);
    double** mat_courante= getMatrice(la_map);
    srand(time(NULL));
    for(int i=0; i<getTaille(la_map);i+=1)
    {
        for(int j=0; j<getTaille(la_map);j+=1)
            mat_courante[i][j]=0;
    }
    personnage* monstre_liste = membre_joueur(monstre);
    int idz= getZone(monstre_liste);
    for (int i=0; i<getTaille(la_map); i++){
        int p = rand()%10;
        while(p==idz){
            p=rand()%10;
        }
        mat_courante[i][idz]=0.5;
        mat_courante[i][p]=0.5;
    }
     
}

void effet_Prevel(carte* c,joueuse* joueuse)
{
    setEtatCarte(ACTIVE, c);
    personnage* perso = membre_joueur(joueuse);
    while (perso != NULL)
    {
        int i=0; 
        enum titre * pouvoir=getPouvoirs(perso);
        while (pouvoir[i]!=0){
            i+=1;
        }
        pouvoir[i]=Prevel;
        perso = getPersonnageSuivantJoueur(perso);
    }

}

void effet_Prevel_prochain_tour(carte* c, joueuse* j)
{
    setNbTour((getNbTour(c)-1), c);
    if (getNbTour(c)<1){
        setEtatCarte(UTILISEE, c);
    }
    personnage* pliste= membre_joueur(j);
    while (pliste !=NULL){
        enum titre * pouvoir=getPouvoirs(pliste);
        for (int i=0; i<10; i++){
            if (pouvoir[i]==Prevel){
                pouvoir[i]=0;
            }
        }
        pliste=getPersonnageSuivantJoueur(pliste);
    }
    
}




int carte_dans_main( carte* main, int num_carte){
    int i=0;
    carte* main2= main; 
    int j=0;
    while (main2!=NULL){
        if (getEtatCarte(main2)==INACTIVE){
            j+=1;
        }
        main2=getCarteSuivante(main2);
    }
    if (j==0){
        return 1000;
    }
    while(main!=NULL){
        if ((int)getNom(main)==num_carte && getEtatCarte(main)==INACTIVE){
            return i;
        }
        main=getCarteSuivante(main);
        i+=1;
    }
    return 100;
}


void jouer_une_carte(joueuse* joueuse1, joueuse* joueuse2,joueuse* monstre, int numero, map* la_map, int num_carte)
{
    joueuse* joueuse_ce_tour ;
    joueuse* joueuse_adverse ;
    
    if (numero %2 ==0)
    {
        joueuse_ce_tour = joueuse1;
        joueuse_adverse = joueuse2;
    }
    else if (numero % 2 == 1)
    {
        joueuse_ce_tour = joueuse2;
        joueuse_adverse = joueuse1;
    }

    carte* main_courante = getMain(joueuse_ce_tour);

    int numero_carte= num_carte;
    while (carte_dans_main(main_courante,numero_carte) == 100)
    {
        numero_carte= redemande_carte();
    }
    if (carte_dans_main(main_courante,numero_carte)==1000){
        plus_de_carte();
    }
    else {
    carte* la_carte=parcourir_cliste(main_courante, carte_dans_main(main_courante,numero_carte));
    switch (numero_carte) {

        case 1 : 
            effet_Merabet(la_carte);
            break;

        case 2 : {
            int id1 = choix_zone();
             while (id1<1 || id1>10 )
            {
                id1 = choix_zone();
            }
            int id2 = choix_zone();
            while (id2<1 || id2>10 )
            {
                id2 = choix_zone();
            }
            zone* zone1 = zone_recherche(la_map, id1-1);
            zone* zone2 = zone_recherche(la_map, id2-1);
            effet_Bannour(zone1, zone2, la_carte);
            break;
        }

        case 3 : 
        {
            personnage* l_monstre=membre_joueur(monstre);
            
            effet_Honore(l_monstre, joueuse_ce_tour, joueuse_adverse, la_map, la_carte);
            break;
        }
        case 4:
            effet_Rioboo(joueuse_adverse, la_carte);
            break;

        case 5 :
            effet_Goilard(la_carte, joueuse_adverse);
            break;

        case 6 :
            effet_Bourard(la_carte);
            break;

        case 7 :
        {
            personnage* l_monstre=membre_joueur(monstre);
            effet_Munante(l_monstre, la_map, la_carte );
            break;
        }

        case 8 : 
            effet_Benezet(la_carte, la_map);
            break;


        case 9 :
        {
            effet_Ligozat(la_map, la_carte, joueuse_ce_tour);
            break;
        }

        case 10 :
            effet_Mouilleron(la_map, la_carte, joueuse_adverse,  joueuse_ce_tour);
            break;

        case 11 :
            effet_Dembele_Cabot(joueuse_ce_tour, la_carte, la_map);
            break;

        case 12 :
             effet_Pacave(la_map, la_carte, joueuse_adverse);
            break;

        case 13 :
            effet_Huet(la_map, la_carte);
            break;
    

        case 14 :
            effet_Matias(la_carte, monstre);
            break;

        case 15 :
            effet_Salhab(la_carte);
             break;

        case 16 :
            effet_Pulido(la_carte, la_map, monstre);
            break;

        case 17 : 
            effet_Watel(la_carte, la_map, joueuse_ce_tour);
            break;

        case 18 :
            effet_Szafranski(la_carte,la_map, joueuse_ce_tour, joueuse_adverse, monstre);
            break;
    
        case 19 :
            effet_Forest( la_carte, monstre, la_map);
             break;

        case 20 :
             effet_Prevel(la_carte, joueuse_ce_tour);
            break;

        default :
            break;

    }
    }
}


int activate_carte(joueuse* joueuse_ce_tour, joueuse* monstre){
    carte* main=getMain(joueuse_ce_tour);
    int i=0;
    while (main !=NULL){
        if (getEtatCarte(main)==ACTIVE){
            switch (getNom(main)){
                case Merabet: 
                    effet_Merabet_prochain_tour(joueuse_ce_tour, main);
                    break; 

                case Rioboo:
                    break;

                case Goilard: 
                    i=effet_Goilard_prochain_tour(main, joueuse_ce_tour); //0 tu joue, 1 tu passes ton tour
                    break;

                case Bourard:
                    break; 

                case Ligozat:
                    break; 

                case DembeleCabot:
                    effet_Dembele_Cabot_prochain_tour(joueuse_ce_tour, main);
                    break; 

                case Pacave:
                    break; 

                case Matias:
                    effet_Matias_prochain_tour(main, monstre);
                    break; 

                case Salhab:
                    effet_Salhab_prochain_tour(main);
                    break; 

                case Watel:
                    break; 
                
                case Prevel: 
                    effet_Prevel_prochain_tour(main, joueuse_ce_tour);
                    break;
                 default :
                    break;

            }
        }
        main=getCarteSuivante(main);
    }
    return i; 
}
