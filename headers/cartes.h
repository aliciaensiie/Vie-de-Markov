#ifndef CARTES_H
#define CARTES_H
/**
* \files : cartes.h 
* Ce fichier décrit l'ensemble des fonctions qui donnent l'effet des cartes utilisées dans le jeu*/

typedef struct carte carte;
typedef struct RenderObject RenderObject;

#define debut_carte_longueur 55
#define debut_carte_hauteur 755
#define espace_carte 55
#define taille_carte 100
#define number_of_cards 17

enum titre {
    Merabet = 1, /*Pendant vos 3 prochains tour, votre capital augmente de 2*/
    
    Bannour, /*Choisissez deux zones, les personnages présents sur ces deux zones sont échangés.*/
    
    Honore, /*Chaque monstre se déplace 3 fois. Chaque membre d'école qu'un monstre rencontre est mangé.*/
    
    Goilard, /*Lors du prochain tour et du suivant, c'est vous qui jouez. 
    Lors des deux tours suivant, c'est la joueuse adverse qui joue.*/
    
    Bourard, /*Lors du prochain déplacement, si deux membres d'écoles adverses se retrouvent sur la même zone, 
    ils se déplacent de nouveau. Si ces deux membres sont sur la zone du monstre avant le second déplacement, ils ne sont pas mangés. 
    On recommence l'opération au plus 100 fois, jusqu'à ce que les membres des écoles adverses soient sur des zones distinctes.*/
    
    Munante, /*Les membres d'écoles présents sur la zone où était un monstre avant son dernier déplacement sont mangés.*/
    
    Benezet, /*Déplacez un des monstres sur la zone de votre choix. 
    Si un membre d'école se trouve sur la zone du monstre, il n'est pas mangé.*/
    
    Ligozat, /*Choisissez un membre de votre école, il effectue désormais deux déplacements au lieu d'un à chaque tour.*/
    
    Mouilleron, /*Choisissez un membre de l'école de la joueuse adverse. 
    Ce membre devient un membre de votre école.*/
    
    DembeleCabot, /*Sacrifiez un membre de votre école de votre choix. 
    Vous avez 15 points de capital en plus à votre prochain tour.*/
    
    Huet, /*Chaque zone effectue une rotation de probabilité. La probabilité d'aller de la zone i à la zone j devient la probabilité d'aller de la zone i à la zone j + 1. 
    La probabilité d'aller de la zone i à la zone 10 devient la probabilité d'aller de la zone i à la zone 1.*/
    
    Matias, /*Chaque monstre disparaît pendant 2 tours. Il réapparaîtra sur la zone d'où il est parti.*/
    
    PulidoNino, /*Mettez à 0 les probabilités permettant de sortir de la zone de chaque monstre et mettez à 1 la probabilité de rester dans la zone de chaque monstre.*/
    
    Watel, /*Choisissez un membre de votre école, il devient FISA et effectue désormais son déplacement un tour sur deux.*/
    
    Szafranski, /*Ajoutez un monstre sur la zone 1, un membre de votre école sur la zone 2 et un membre de l'école adverse sur la zone 3. 
    Si un membre d'école se trouve sur la même zone qu'un monstre, il n'est pas mangé.*/
    
    Forest, /*Mettez toutes les probabilités à 0. Puis, pour chaque zone, la probabilité de se déplacer de cette zone vers la zone contenant le monstre passe à 0.5 (s'il y a plusieurs monstres, un des monstres est choisi aléatoirement) ; 
    et la probabilité de se déplacer de cette zone vers une autre zone ne contenant pas de monstre choisie aléatoirement passe également à 0.5.*/
    
    Prevel, /*Pendant 4 tours, les membres de votre école ne peuvent être mangés par un monstre. 
    S'ils sont sur sa zone à la fin du tour, rien ne se passe, ils restent sur cette case.*/
};




enum etat_carte {
  INACTIVE,
  ACTIVE,
  UTILISEE
};
enum nom_joueuse {
  JOUEUSE1,
  JOUEUSE2,
  MONSTRE
};


//tache b5 
/**
 * \return: renvoie lee nom de la carte
*/
enum titre getNom(carte *c);

/**
 * \brief: change le nom de la carte
*/
void setNom(enum titre nouveau_nom, carte *c);

/**
 * \return: renvoie la description de la carte 
*/
char *getDesc(carte *c);

/**
 * \brief: change la descritpion de la carte 
*/
void setDesc(char* nouvelle_description, carte *c);

/**
 * \return: renvoie l'état de la carte 
*/
enum etat_carte getEtatCarte(carte *c);

/**
 * \brief: change l'état de la carte 
*/
void setEtatCarte(enum etat_carte nouvel_etat, carte *c);

/**
 * \return: renvoie le nombre de tour où la carte est active 
*/
int getNbTour(carte *c);

/**
 * \brief: change le nombre de tour de la carte 
*/
void setNbTour(int nouveau_nb_tour, carte *c);

/**
 * \return: renvoie le propriétaire de la carte
*/
enum nom_joueuse getProprietaireCarte(carte *c);

/**
 * \brief: change le propriétaire de la carte
*/
void setProprietaireCarte(enum nom_joueuse nv_proprietaire, carte *c);

/**
 * \brief : renvoie la taille en octet d'une carte
 */
int getSizeOfCarte();

/***
 * \brief : permet de definir la carte suivante
 */
void setCarteSuivante(carte *c, carte *suiv);

/**
 * \brief : permet de recuperer la carte suivante
 */
carte *getCarteSuivante(carte *c);

RenderObject* getImageCarte(carte* c);

void setImageCarte(carte* c, RenderObject* imagecarte);

#endif /* CARTES_H */
