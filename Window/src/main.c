
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



int main()
{
    srand(time(NULL));
    // Création et ouverture de l'application

    Application* app = getNewApplication(WIDTH, HEIGHT, "La Vie De Markov");

    // Ajout des textures

    add_Texture(app, "Ressources/Texture/merabet_bleu.png", Merabettex);
    add_Texture(app, "Ressources/Texture/Bannourd_bleu.png", Bannourtex); 
    add_Texture(app, "Ressources/Texture/honore_bleu.png", Honoretex);  
    add_Texture(app, "Ressources/Texture/goilard_bleu.png", Goilardtex); 
    add_Texture(app, "Ressources/Texture/bourard_bleu.png", Bourardtex); 
    add_Texture(app, "Ressources/Texture/munante_bleu.png", Munantetex); 
    add_Texture(app, "Ressources/Texture/benezet_bleu.png", Benezettex); 
    add_Texture(app, "Ressources/Texture/ligozat_bleu.png", Ligozattex); 
    add_Texture(app, "Ressources/Texture/mouilleron_bleu.png", Mouillerontex); 
    add_Texture(app, "Ressources/Texture/dc_bleu.png", Dembeletex); 
    add_Texture(app, "Ressources/Texture/huet_bleu.png", Huettex); 
    add_Texture(app, "Ressources/Texture/matias_bleu.png", Matiastex); 
    add_Texture(app, "Ressources/Texture/pn_bleu.png", Pulidotex); 
    add_Texture(app, "Ressources/Texture/watel_bleu.png", Wateltex); 
    add_Texture(app, "Ressources/Texture/szafranski_bleu.png", Szafranskitex); 
    add_Texture(app, "Ressources/Texture/forest_bleu.png", Foresttex); 
    add_Texture(app, "Ressources/Texture/prevel_bleu.png", Preveltex); 
    add_Texture(app, "Ressources/Texture/press-start.png", Fond_Generale_debut); 
    add_Texture(app, "Ressources/Texture/fond_jeu.png", Fond_Jeu);
    add_Texture(app, "Ressources/Texture/Choix.png", Carte_ou_proba);  
    add_Texture(app, "Ressources/Texture/choix_carte.png", Choix_Carte); 
    add_Texture(app, "Ressources/Texture/choix_proba.png", Choix_proba); 
    add_Texture(app, "Ressources/Texture/the_end.png", TextureFin); 
    add_Texture(app, "Ressources/Texture/pion_rouge.png", Perso_j1); 
    add_Texture(app, "Ressources/Texture/pion_bleu.png", Perso_j2);
    add_Texture(app, "Ressources/Texture/monstre.png", Perso_monstre); 
    add_Texture(app, "Ressources/Texture/zones.png", Plateau); 
    add_Texture(app, "Ressources/Texture/matrice.png", matrice);
    add_Texture(app, "Ressources/Texture/fond_desc.png", Fond_Desc);
    add_Texture(app, "Ressources/Texture/fond_desc.png", Fond_Rules);

    
    add_Font(app, "Ressources/Font/Gameplay.ttf", SANSATION_FONT);
    add_Font(app, "Ressources/Font/desc.ttf", DESC_FONT);
    add_Font(app, "Ressources/Font/desc_bold.ttf", DESC_BOLD_FONT);

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