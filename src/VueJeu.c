
#include "../headers/cartes.h"
#include "../headers/joueuses.h"
#include "../headers/personnages.h"
#include "../headers/zones.h"
#include "../headers/structures.h"
#include "../headers/effets.h"
#include "../headers/VueJeu.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "ViewWrapper.h"
#include "AnimationWrapper.h"
#include "LabelWrapper.h"
#include "RenderObjectWrapper.h"

struct VueJeu{
    GamePhase phaseactuelle;
    joueuse* joueuses[3];
    map* la_map;
    Application* app;
    RenderObject* fond_generale;
    Label* fWinnerLabel; 
    RenderObject* EffectDescription;
    Label* tourjoueuse;
    Label* choixzone;
    RenderObject* carte_ou_proba;
    RenderObject* choix_carte; 
    RenderObject* choix_proba;
    enum titre effet_choisi; 
    int zone1_choisi;
    int zone2_choisi;
    int zone3_choisi;
    int numero_tour;
    joueuse* joueuse_ce_tour;

    float fEndGameAccu;
    float fEndGameDelay;

    float fReadingDelay;
    float fReadingAccu;

    Label* fKeyToPressed;
    GamePhase beforeInfoMenuPhase;
};
typedef struct VueJeu* VueJeu;


joueuse** getJoueuses_VueJeu(VueJeu vj){
    return vj->joueuses;
}

RenderObject* getobject_VueJeu(VueJeu vj){
    return vj->fond_generale;
}

GamePhase getPhase_VueJeu(VueJeu vj){
    return vj->phaseactuelle;
}

GamePhase getPhaseBeforeMenu_VueJeu(VueJeu vj){
    return vj-> beforeInfoMenuPhase;
}

void setMap_VueJeu(VueJeu vj, map* la_map){
    vj->la_map=la_map;
}

void setobject_VueJeu(VueJeu vj, RenderObject* new_fond){
    vj->fond_generale=new_fond;
}

void setPhase_VueJeu(VueJeu vj, GamePhase gp){
    vj->phaseactuelle=gp;
}

map* getMap_VueJeu(VueJeu vj){
    return vj->la_map;
}

int getZone1choisi_VueJeu(VueJeu vj){
    return vj->zone1_choisi;
}

int getZone2choisi_VueJeu(VueJeu vj){
    return vj->zone2_choisi;
}

int getZone3choisi_VueJeu(VueJeu vj){
    return vj->zone3_choisi;
}

void setZone1choisi_VueJeu(VueJeu vj, int zone){
    vj->zone1_choisi=zone;
}

void setZone2choisi_VueJeu(VueJeu vj, int zone){
    vj->zone2_choisi=zone;
}

void setZone3choisi_VueJeu(VueJeu vj, int zone){
    vj->zone3_choisi=zone;
}

void setLabelChoixZone_VueJeu(VueJeu vj, const char* text){
    removeRenderObject(vj->app, vj->choixzone);
    Label* label=addNewLabel(vj->app, 0, text, ForeGround);
    vj->choixzone=label;
}

Label* getLabelChoixZone_VueJeu(VueJeu vj){
    return vj->choixzone;
}

joueuse* getJoueuseCeTour_VueJeu(VueJeu vj){
    return vj->joueuse_ce_tour;
}

void setEffetChoisi_VueJeu(VueJeu vj, enum titre carte){
    vj->effet_choisi=carte;
}





VueJeu creer_VueJeu(Application* app){

    VueJeu vj = malloc(sizeof(struct VueJeu));

    vj->app=app;
    vj->joueuses[3]=NULL;
    vj->la_map=NULL;
    vj->fWinnerLabel=NULL;
    vj->EffectDescription=NULL;
    vj->tourjoueuse=NULL;
    vj->fKeyToPressed=NULL;
    vj->carte_ou_proba=NULL;
    vj->choix_carte=NULL;
    vj->choix_proba=NULL;
    vj->effet_choisi=0;
    vj->zone1_choisi=0;
    vj->zone2_choisi=0;
    vj->zone3_choisi=0;
    vj->numero_tour=0;
    vj->joueuse_ce_tour=NULL; 
    vj->choixzone=NULL;

    //creation du fond 
    vj->fond_generale=addNewRenderObject(app, Fond_Generale_debut, getFloatRect(0, 0, 0, 0), Background);



    vj->phaseactuelle = PhaseEntrer;
    vj->fEndGameAccu = 0.f;
    vj->fEndGameDelay = 15.f;


    vj->fReadingAccu = 0.f;
    vj->fReadingDelay = 2.5f;

    vj->beforeInfoMenuPhase = vj->phaseactuelle;
    return vj;


}

void initializeVueJeu(VueJeu vj){
    map* la_map=create_map(vj->app);
    vj->la_map=la_map;

    joueuse* j1=creer_joueuse(0,la_map, vj->app);
    joueuse* j2=creer_joueuse(1,la_map, vj->app);
    joueuse* monstre=creer_joueuse(2, la_map, vj->app);

    
    vj->joueuses[0]=j1;
    vj->joueuses[1]=j2;
    vj->joueuses[2]=monstre;
    
    vj->joueuse_ce_tour= tour_de_joueur(j1, j2, vj->numero_tour);

    //creation du fond 
    vj->fond_generale=addNewRenderObject(vj->app, Fond_Jeu, getFloatRect(0, 0, 0, 0), Background);

    //creation fond effet carte
    vj->EffectDescription=addNewRenderObject(vj->app, Effet_Carte, getFloatRect(0, 0, 0, 0), ForeGround);
    setCanRenderObjectBeDrawn(vj->EffectDescription, 0);

    // label tour de joueuse
    vj->tourjoueuse=addNewLabel(vj->app, SANSATION_FONT, "C'est au tour de J1, \nCapital = 5", ForeGround);
    setPosition(vj->tourjoueuse, 800, 650);
    setSpriteColor(vj->tourjoueuse, 250, 0,0,255);

    //Label demande de choisir une zone 
    vj->choixzone=addNewLabel(vj->app, SANSATION_FONT, "Appuie sur space pour choisir le capital \na utiliser et entrer quand tu as fini", ForeGround);
    setPosition(vj->choixzone, 100, 450);
    setCanLabelBeDrawn(vj->choixzone, 0);

    //label winner
    vj->fWinnerLabel = addNewLabel(vj->app, SANSATION_FONT, "The winner is:\n", UI);
    setSpriteColor(vj->fWinnerLabel, 0,255,0,255);
    setCanLabelBeDrawn(vj->fWinnerLabel, 0);

    //keypressed
    vj->fKeyToPressed = addNewLabel(vj->app, SANSATION_FONT, "Press E for effects information", ForeGround);
    setPosition(vj->fKeyToPressed, 15, 870);
    setCharacterSize(vj->fKeyToPressed, 20);

    //Choix
    vj->carte_ou_proba=addNewRenderObject(vj->app, Carte_ou_proba, getFloatRect(0, 0, 0, 0), ForeGround);
    setPosition(vj->carte_ou_proba,500,400 );
    vj->choix_carte=addNewRenderObject(vj->app, Choix_Carte, getFloatRect(0, 0, 0, 0), ForeGround);
    setPosition(vj->choix_carte,472,500 );
    vj->choix_proba=addNewRenderObject(vj->app, Choix_proba, getFloatRect(0, 0, 0, 0), ForeGround);
    setPosition(vj->choix_proba,675,500 );
}

void chgt_fond_label_effect(VueJeu vj){
    if (vj->phaseactuelle==PhaseChoix1 || vj->phaseactuelle==PhaseChoixCarte || vj->phaseactuelle==PhaseChoixProba){
        setCanLabelBeDrawn(vj->tourjoueuse, 0);
        if (vj->phaseactuelle==PhaseChoix1){
            setCanRenderObjectBeDrawn(vj->carte_ou_proba, 0);
            setCanRenderObjectBeDrawn(vj->choix_carte, 0);
            setCanRenderObjectBeDrawn(vj->choix_proba, 0);
        }
        setCanRenderObjectBeDrawn(vj->fond_generale, 0);
        setCanRenderObjectBeDrawn(vj->EffectDescription, 1);
        setLabelText(vj->fKeyToPressed, "Press E to return in the game");
        setSpriteColor(vj->fKeyToPressed, 0,0,0,255);
        vj->beforeInfoMenuPhase = vj->phaseactuelle;
        vj->phaseactuelle=PhaseEffet;
    }
    else{
        setCanLabelBeDrawn(vj->tourjoueuse, 1);
        if (vj->beforeInfoMenuPhase==PhaseChoix1){
            setCanRenderObjectBeDrawn(vj->carte_ou_proba, 1);
            setCanRenderObjectBeDrawn(vj->choix_carte, 1);
            setCanRenderObjectBeDrawn(vj->choix_proba, 1);
        }
        setCanRenderObjectBeDrawn(vj->fond_generale, 1);
        setCanRenderObjectBeDrawn(vj->EffectDescription, 0);
        setLabelText(vj->fKeyToPressed, "Press E for effects information");
        setSpriteColor(vj->fKeyToPressed, 255,255,255,255);
        vj->phaseactuelle=vj->beforeInfoMenuPhase;
    }
}



void updateJeu(Application* app, VueJeu vj, float dt)
{
    
    switch (vj->phaseactuelle)
    { 
        case PhaseFin: 
            vj->fEndGameAccu += dt;
            if (vj->fEndGameAccu >= vj->fEndGameDelay){
                //free_Vue_Jeu(vj);
                closeApplication(app);
            }
            break;
        default:
            break;
    }
}

void handleJeuEvent(Application* app, VueJeu vj, SFML_EVENTS e)
{

    switch (vj->phaseactuelle)
    {
        case PhaseEntrer:
            if(e==KEY_PRESSED_Enter){
                vj->phaseactuelle=PhaseChoix1;
                initializeVueJeu(vj);
                rendre_visible(vj->joueuse_ce_tour);
                rendre_invisible((vj->joueuse_ce_tour==vj->joueuses[0]) ? vj->joueuses[1]: vj->joueuses[0]);
               
            }
            break;

        case PhaseChoix1:
        {   
            
            if(e == KEY_PRESSED_E)
            {
                chgt_fond_label_effect(vj);
            }
            if( e ==MOUSE_LEFT_Pressed ){
                float x = getMousePositionX(app);
                float y = getMousePositionY(app);
                if (containsPoint(vj->choix_carte, x, y)==1){
                    setCanRenderObjectBeDrawn(vj->carte_ou_proba, 0);
                    setCanRenderObjectBeDrawn(vj->choix_carte, 0);
                    setCanRenderObjectBeDrawn(vj->choix_proba, 0);
                    vj->phaseactuelle=PhaseChoixCarte;
                }
                 if (containsPoint(vj->choix_proba, x, y)==1){
                    setCanRenderObjectBeDrawn(vj->carte_ou_proba, 0);
                    setCanRenderObjectBeDrawn(vj->choix_carte, 0);
                    setCanRenderObjectBeDrawn(vj->choix_proba, 0);
                    setCanLabelBeDrawn(vj->choixzone, 1);
                    setLabelChoixZone_VueJeu(vj, "Appuie n fois sur space = utilise n capital puis ENTRER");
                    vj->phaseactuelle=PhaseChoixProba;
                }
            }

            break;
        }

        case PhaseChoixCarte:
        {
            if(e == KEY_PRESSED_E)
            {
                chgt_fond_label_effect(vj);
            }
            handleJoueuseEvent(e, vj, vj->app);
            if (vj->effet_choisi!=0){
                int besoinzone=jouer_une_carte(vj->joueuses[0], vj->joueuses[1], vj->joueuses[2], vj->numero_tour, vj->la_map, vj->effet_choisi, vj->zone1_choisi, vj->zone2_choisi, vj->app);
                if (besoinzone==1){
                    vj->phaseactuelle=PhaseChoixZone; 
                    setLabelChoixZone_VueJeu(vj, "Choisi une zone sur le plateau");
        
                    
                }
                else{
                    vj->phaseactuelle=PhaseAppliqueEffet;
                }
            }

            break;
        }

        case PhaseChoixZone: 
            handleMapEvent(vj, e, vj->app);
            int besoinzone=jouer_une_carte(vj->joueuses[0], vj->joueuses[1], vj->joueuses[2], vj->numero_tour, vj->la_map, vj->effet_choisi, vj->zone1_choisi, vj->zone2_choisi, vj->app);
                if (besoinzone==1){
                    vj->phaseactuelle=PhaseChoixZone; 
                }
                else{
                    vj->phaseactuelle=PhaseAppliqueEffet;
                    setCanLabelBeDrawn(vj->choixzone, 0);
                }
            break;

        case PhaseAppliqueEffet:
             updateMap(vj);
                if (!as_tu_perdu(vj->joueuses[0]) || !as_tu_perdu(vj->joueuses[1])){
                    vj->phaseactuelle=PhaseFin;
                    vj->fond_generale=addNewRenderObject(vj->app, TextureFin, getFloatRect(0, 0, 0, 0), ForeGround); 
                    setSpriteColor(vj->fond_generale, 255,255,255,50);
                    setCanLabelBeDrawn(vj->fWinnerLabel, 1);
                    appendLabelText(vj->fWinnerLabel, (!as_tu_perdu(vj->joueuses[0])) ? "J2" : "J1");
                }
                else{
                    vj->zone1_choisi=0;
                    vj->zone2_choisi=0;
                    vj->zone3_choisi=0;
                    vj->effet_choisi=0;
                    vj->numero_tour+=1;
                    vj->joueuse_ce_tour=tour_de_joueur(vj->joueuses[0], vj->joueuses[1], vj->numero_tour);
                    vj->phaseactuelle=PhaseChoix1;
                    

                    
                    rendre_visible(vj->joueuse_ce_tour);
                    rendre_invisible((vj->joueuse_ce_tour==vj->joueuses[0]) ? vj->joueuses[1]: vj->joueuses[0]);
                    setCanLabelBeDrawn(vj->carte_ou_proba, 1);
                    setCanLabelBeDrawn(vj->choix_carte, 1);
                    setCanLabelBeDrawn(vj->choix_proba, 1);
                    reinitialiser_capital(vj->joueuse_ce_tour);
                    int i=activate_carte(vj->joueuse_ce_tour, vj->joueuses[2]);
                    setLabelText(vj->tourjoueuse, "C'est au tour de ");
                    char capital[50];
                    sprintf(capital, "%d", getCapital(vj->joueuse_ce_tour));
                    appendLabelText(vj->tourjoueuse, (vj->joueuse_ce_tour == vj->joueuses[0]) ? "J1, \nCapital = " : "J2\n Capital=");
                    appendLabelText(vj->tourjoueuse, capital);
                    if (i==1){
                        vj->numero_tour+=1;
                        vj->joueuse_ce_tour=tour_de_joueur(vj->joueuses[0], vj->joueuses[1], vj->numero_tour);
                        vj->phaseactuelle=PhaseChoix1;
                        setLabelText(vj->tourjoueuse, "C'est au tour de ");
                        appendLabelText(vj->tourjoueuse, (vj->joueuse_ce_tour == vj->joueuses[0]) ? "J1" : "J2");
                        rendre_visible(vj->joueuse_ce_tour);
                        rendre_invisible((vj->joueuse_ce_tour==vj->joueuses[0]) ? vj->joueuses[1]: vj->joueuses[0]); 
                    }
                    if (vj->joueuse_ce_tour==vj->joueuses[0]){
                        setSpriteColor(vj->tourjoueuse, 255,0,0,255);
                    }
                    else{
                        setSpriteColor(vj->tourjoueuse, 0,0,255,255);
                    }
                }
            break; 

        case PhaseChoixProba: 
        {
            if(e == KEY_PRESSED_E)
            {
                chgt_fond_label_effect(vj);
            }
            handleMapEvent(vj, e, vj->app);
            if (vj->zone1_choisi!=0 && vj->zone2_choisi!=0 && vj->zone3_choisi!=0){
                manger_les_persos(vj->joueuses[0], vj->joueuses[1], membre_joueur( vj->joueuses[2]));
               vj->phaseactuelle=PhaseAppliqueEffet;
            }

            break;
        }

        case PhaseEffet:
            if(e == KEY_PRESSED_E)
            {
                chgt_fond_label_effect(vj);
            }
            break;

        default:
            break;
    }
}

