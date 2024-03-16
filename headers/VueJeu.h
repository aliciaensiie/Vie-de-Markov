#ifndef VUEJEU_H
#define VUEJEU_H

#include "ApplicationWrapper.h"
#include "SFMLEvents.h"


typedef struct VueJeu* VueJeu;

typedef enum GamePhase{
    PhaseEntrer, PhaseChoix1, PhaseChoixCarte, PhaseChoixProba, PhaseChoixZone, PhaseAppliqueEffet, PhaseEffet, PhaseFin
} GamePhase;

typedef enum Textures{
    Merabettex=1, Bannourtex, Honoretex, Riobootex, Goilardtex, Bourardtex, Munantetex, Benezettex, Ligozattex, Mouillerontex, Dembeletex, Pacavetex, Huettex, Matiastex, Salhabtex, Pulidotex, Wateltex, Szafranskitex, Foresttex, Preveltex, Fond_Generale_debut, Fond_Jeu, Effet_Carte, Carte_ou_proba, Choix_Carte, Choix_proba, TextureFin, Perso_j1, Perso_j2, Perso_monstre, Plateau, matrice
} Textures; 

typedef enum Fonts{
    SANSATION_FONT
} Fonts; 

/**
 * \brief donne les joueuses et le monstre du jeu
*/
joueuse** getJoueuses_VueJeu(VueJeu vj);

/**
 * \brief donne le fond du jeu
*/
RenderObject* getobject_VueJeu(VueJeu vj);

/**
 * \brief donne la phase actuelle du jeu
 */
GamePhase getPhase_VueJeu(VueJeu vj);

/**
 * \brief donne la phase avant la page Menu
*/
GamePhase getPhaseBeforeMenu_VueJeu(VueJeu vj);


/**
 * \brief change le fond du jeu
*/
void setobject_VueJeu(VueJeu vj, RenderObject* new_fond);

/**
 * \brief change la phase actuelle du jeu
 */
void setPhase_VueJeu(VueJeu vj, GamePhase gp);

/**
 * \brief change la phase avant la page Menu
*/
void setPhaseBeforeMenu_VueJeu(VueJeu vj, GamePhase gp);

/**
 * \brief renvoie la map
*/
map* getMap_VueJeu(VueJeu vj);

/**
 * \brief renvoie la zone 1 choisie
*/
int getZone1choisi_VueJeu(VueJeu vj);

/**
 * \brief renvoie la zone 2 choisie
*/
int getZone2choisi_VueJeu(VueJeu vj);

/**
 * \brief renvoie la zone 3 choisie
*/
int getZone3choisi_VueJeu(VueJeu vj);

/**
 * \brief change la zone 1 choisie
*/
void setZone1choisi_VueJeu(VueJeu vj, int zone);

/**
 * \brief change la zone 2 choisie
*/
void setZone2choisi_VueJeu(VueJeu vj, int zone);

/**
 * \brief change la zone 3 choisie
*/
void setZone3choisi_VueJeu(VueJeu vj, int zone);

void setLabelChoixZone_VueJeu(VueJeu vj, const char* text);

Label* getLabelChoixZone_VueJeu(VueJeu vj);

VueJeu creer_VueJeu(Application* app);

void handleJeuEvent(Application* app, VueJeu vj, SFML_EVENTS e);

void updateJeu(Application* app, VueJeu vj, float dt);

joueuse* getJoueuseCeTour_VueJeu(VueJeu vj);

void setEffetChoisi_VueJeu(VueJeu vj, enum titre carte);



#endif /*VUEJEU_H*/