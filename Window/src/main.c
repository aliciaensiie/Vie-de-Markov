
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
#include "string.h"

#include "ViewWrapper.h"
#include "AnimationWrapper.h"

#ifdef PATH_RESSOURCES
    
#else
    #define PATH_RESSOURCES "Ressources"
#endif

#ifdef SIZE_PATH_RESSOURCES
    
#else
    #define SIZE_PATH_RESSOURCES 11
#endif

char** listChar(){
    char** list= malloc(34 * sizeof(char*));
    for (int i=0; i<34; i++){
        char* message = malloc(100*sizeof(char));
        for (int j=0; j<SIZE_PATH_RESSOURCES; j++){
            message[j]=PATH_RESSOURCES[j];
        }
        list[i]= message;
    }
    return list;
}


int main()
{
    srand(time(NULL));
    // Création et ouverture de l'application
    Application* app = getNewApplication(WIDTH, HEIGHT, "La Vie De Markov");

    // Ajout des textures
    char ** list = listChar();
    add_Texture(app, strncat(list[0], "/Texture/merabet_bleu.png",26), Merabettex);
    add_Texture(app, strncat(list[1], "/Texture/Bannourd_bleu.png", 27), Bannourtex); 
    add_Texture(app, strncat(list[3], "/Texture/honore_bleu.png",25), Honoretex);  
    add_Texture(app, strncat(list[4], "/Texture/goilard_bleu.png", 26), Goilardtex); 
    add_Texture(app, strncat(list[5], "/Texture/bourard_bleu.png", 26), Bourardtex); 
    add_Texture(app, strncat(list[6], "/Texture/munante_bleu.png", 26), Munantetex); 
    add_Texture(app, strncat(list[7], "/Texture/benezet_bleu.png", 26), Benezettex); 
    add_Texture(app, strncat(list[8], "/Texture/ligozat_bleu.png", 26), Ligozattex); 
    add_Texture(app, strncat(list[9], "/Texture/mouilleron_bleu.png", 29), Mouillerontex); 
    add_Texture(app, strncat(list[10], "/Texture/dc_bleu.png", 21), Dembeletex); 
    add_Texture(app, strncat(list[11], "/Texture/huet_bleu.png", 23), Huettex); 
    add_Texture(app, strncat(list[12], "/Texture/matias_bleu.png", 25), Matiastex); 
    add_Texture(app, strncat(list[13], "/Texture/pn_bleu.png", 21), Pulidotex); 
    add_Texture(app, strncat(list[14], "/Texture/watel_bleu.png", 24), Wateltex); 
    add_Texture(app, strncat(list[15], "/Texture/szafranski_bleu.png", 29), Szafranskitex); 
    add_Texture(app, strncat(list[16], "/Texture/forest_bleu.png", 25), Foresttex); 
    add_Texture(app, strncat(list[17], "/Texture/prevel_bleu.png", 25), Preveltex); 
    add_Texture(app, strncat(list[18], "/Texture/press-start.png", 25), Fond_Generale_debut); 
    add_Texture(app, strncat(list[19], "/Texture/fond_jeu.png", 22), Fond_Jeu);
    add_Texture(app, strncat(list[20], "/Texture/Choix.png", 19), Carte_ou_proba);  
    add_Texture(app, strncat(list[21], "/Texture/choix_carte.png", 25), Choix_Carte); 
    add_Texture(app, strncat(list[22], "/Texture/choix_proba.png", 25), Choix_proba); 
    add_Texture(app, strncat(list[23], "/Texture/the_end.png", 21), TextureFin); 
    add_Texture(app, strncat(list[24], "/Texture/pion_rouge.png", 24), Perso_j1); 
    add_Texture(app, strncat(list[25], "/Texture/pion_bleu.png", 23), Perso_j2);
    add_Texture(app, strncat(list[26], "/Texture/monstre.png", 21), Perso_monstre); 
    add_Texture(app, strncat(list[27], "/Texture/zones.png", 19), Plateau); 
    add_Texture(app, strncat(list[28], "/Texture/matrice.png", 21), matrice);
    add_Texture(app, strncat(list[29], "/Texture/fond_desc.png", 23), Fond_Desc);
    add_Texture(app, strncat(list[30], "/Texture/fond_desc.png", 23), Fond_Rules);

    
    add_Font(app, strncat(list[31], "/Font/Gameplay.ttf", 19), SANSATION_FONT);
    add_Font(app, strncat(list[32], "/Font/desc.ttf", 15), DESC_FONT);
    add_Font(app, strncat(list[33], "/Font/desc_bold.ttf",20), DESC_BOLD_FONT);

    // Création du plateau de jeu

    VueJeu game = creer_VueJeu(app);

    // Initialisation du nombre d'images par seconde (fps), de deltaTime qui stockera la différence de temps entre chaque tour de la boucle qui permet de faire fonctionner le jeu le jeu, de l'accumulateur de temps, et du taux d'image par seconde

    unsigned int fps = 30;
    float deltaTime = 0.f, accumulator = 0.f, frameRate = 1.f / (float)fps;
    //Boucle de jeu
    while(is_running(app))
    {
        deltaTime = getElapsedTime(app);
        accumulator += deltaTime;
        while(accumulator >= frameRate)    // Afin que l'appel des mises à jour soit en raccord avec le jeu, et que l'application soit fluide
        {
            accumulator -= frameRate;
            // événements de manipulation
            SFML_EVENTS event;
            while(isAnEventHappening(app, &event))
            {

                switch(event)
                {
                    case KEY_PRESSED_Esc:
                        closeApplication(app);

                    break;
                    default:
                    break;
                }

                handleJeuEvent(app, game, event);

            }
            
            // Mise à jour du plateau

            updateJeu(app, game, frameRate);
            
        }

        render(app);
    }

    free_Application(app);
}