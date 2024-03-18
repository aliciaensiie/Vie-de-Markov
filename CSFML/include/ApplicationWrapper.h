#ifndef APPLICATION_WRAPPER_H
#define APPLICATION__WRAPPER_H
/**
 * @file ApplicationWrapper.h
 * @author Félicien Fiscus (felicien.fgay@gmail.com)
 * @brief ceci est l'interface C pour l'objet C++ Application 
 * @see Application.h
 * @version 0.1
 * @date 2022-04-16
 * 
 * @copyright Copyright (c) 2022
 */

#ifdef __cplusplus
extern "C"
{
#endif
#include "SFMLEvents.h"
#include "Utility.h"


/**
 * @brief L'objet Application est responsable de créer et afficher la fenêtre d'application et son contenu, de stocker les différentes
 *  ressources (textures, polices d'écritures, son et musique) -> add_Texture add_Font add_Sound, et 
 * de gérer et capter les évènements (clavier, souris) -> SFMLEvents.h 
 *  
 * 
 */
typedef struct Application Application;
/**
 * @brief objet pouvant être rendu à l'écran via l'application
 * @see addNewRenderObject 
 * 
 */
typedef struct RenderObject RenderObject;
typedef struct View View;


/*méthodes de l'objet Application*/
/**
 * @brief Construit un nouvelle objet Application, alloué sur le tas. C'est à l'utilisateur de libérer la mémoire allouer par cette fonction
 * @see free_Application
 * 
 * @param width la largeur de la fenêtre afficher à l'écran
 * @param height la hauteur de la fenêtre afficher à l'écran
 * @param winTitle le nom de la fenêtre
 * @return le pointeur vers la nouvelle application crée
 */
Application* getNewApplication(unsigned int winWIDTH, unsigned int winHEIGHT, const char* win_title);

/**
 * @brief détruit l'objet application, en prenant soin de libérer la mémoire alloué par les ressources (cf. add_Texture )
 * ainsi que par les RenderObject 
 * @see addNewRenderObject
 * @param app pointeur valide vers l'application 
 */
void free_Application(Application* app);



/**
 * @brief arrête de rendre la fenêtre de rendu (i.e ça ferme la fenêtre) mais l'application n'est pas détruite !
 * @see free_Application
 * @see is_running
 * 
 * @param app (!= NULL)
 */
void closeApplication(Application* app);

/**
 * @brief getter pour savoir si la fenêtre est ouverte et si l'application tourne
 * @see closeApplication 
 * 
 * @param app (!= NULL)
 * @return 1 si l'application tourne 0 sinon
 */
    int is_running(Application* app);


/**
 * @brief getters pour la taille de la fenêtre
 * @param app (!=NULL)
 */
unsigned int getWindowWIDTH(Application* app);
unsigned int getWindowHEIGHT(Application* app);



/**
 * @brief Getter pour la position X du curseur de la souris
 * la position retourné est celle par rapport à la vue de la fenêtre
 * c'est donc les coordonnées dans le monde et non dans la fenêtre
 * @see setViewSize createView
 * @param app (!=NULL)
 * @return la coordonnée X du curseur de la souris dans le référentiel de la vue actuellement utilisée par l'application
 */
    float getMousePositionX(Application* app);

/**
 * @brief Getter pour la position Y du curseur de la souris
 * la position retourné est celle par rapport à la vue de la fenêtre
 * c'est donc les coordonnées dans le monde et non dans la fenêtre
 * @see setViewSize createView
 * @param app (!=NULL)
 * @return la coordonnée Y du curseur de la souris dans le référentiel de la vue actuellement utilisée par l'application
 */
    float getMousePositionY(Application* app);


/**
 * @brief Getter pour la position du curseur de la souris
 * la position retourné est celle par rapport à la vue de référence passé en argument
 * c'est donc les coordonnées dans le monde de la vue en question et non dans la fenêtre
 * @see setViewSize createView
 * @param app (!=NULL)
 * @param reference_view la vue de référence en question
 * @return le vecteur position (X, Y) du curseur de la souris dans le référentiel de la vue spécifiée en argument
 */
    Vector2f getMousePosition(Application* app, View* reference_view);

/**
 * @brief getter pour la position X de la souris dans le référentiel de la fenêtre, donc sans prendre en compte la vue de la fenêtre
 * 
 * @param app (!= NULL)
 * @return la coordonnée X du curseur par rapport à la fenêtre d'application
 */
    float getAbsoluteMousePositionX(Application* app);
/**
 * @brief getter pour la position Y de la souris dans le référentiel de la fenêtre, donc sans prendre en compte la vue de la fenêtre
 * 
 * @param app (!= NULL)
 * @return la coordonnée Y du curseur par rapport à la fenêtre d'application
 */
    float getAbsoluteMousePositionY(Application* app);

/**
 * @brief getter pour le temps écoulé depuis le dernier appel à cette fonction
 * @param app (!= NULL)
 * @return le différentiel de temps en secondes
 */
    float getElapsedTime(Application* app);

/**
 * @brief fonction permettant de rendre à l'écran la fenêtre créer 
 * par un appel à getNewApplication ainsi que tout les RenderObject et Label dans l'application.
 * La fonction rend les objets dans un certain ordre en fonction de la couche à laquelle ils sont,
 * allant de la couche la plus basse (Background), la première à être affichée, à la couche la 
 * plus haute (UI), la dernière à être affichée.
 * @see Layers
 * @see addNewRenderObject addNewLabel
 * @param app (!= NULL)
 * 
 */
    void render(Application* app);


/**
 * @brief fonction pour gérer les évènements, si un évènement connu à lieu ( SFML_EVENTS )
 * la fonction assigne à 'event' cette évènement
 * @see SFMLEvents.h
 * @param app (!= NULL)
 * @param event le potentiel évènement qui va être retourné (!= NULL) 
 * A noté qu'en une seule frame il peut se passer plusieurs évènements, il est donc judicieux
 * d'utiliser cette fonction avec une while loop plutôt qu'un simple if
 * @return 1 si un évènement connu à lieu, 0 sinon
 */
    int isAnEventHappening(Application* app, SFML_EVENTS* event);


/**
 * @brief vérifie si la touche est pressée actuellement
 * 
 * @param key la touche de clavier pressée
 * @return 1 si la touche est pressée, 0 sinon
 */
    int isKeyPressedRightNow(Application* app, SFML_EVENTS key);

/**
 * @brief vérifie si le bouton est pressé actuellement
 * 
 * @param mouse_button le bouton de la souris pressé
 * @return 1 si le bouton est pressée, 0 sinon
 */
    int isMousePressedRightNow(Application* app, SFML_EVENTS mouse_button);

/**
 * @brief vérifie si l'objet passé en argument est en dehors de la vue de la fenêtre
 * 
 * @param app (!= NULL)
 * @param obj (!= NULL)
 * @param dir (!=NULL) (! nécessite d'être initalisé avec 0, 0 !) vecteur représentant la direction de la potentielle collision entre l'objet est les "murs" de la fenêtre.
 * C'est-à-dire: (-1, 0) -> dépasse à gauche
 *               (1, 0) -> dépasse à droite
 *               (0, -1) -> dépasse en haut
 *               (0, 1) -> dépasse en bas 
 * Si l'objet n'est pas en dehors, alors dir n'est pas modifié.
 * @return 1 si l'objet est en dehors, 0 sinon
 */
    int isOutsideWindow(Application* app, RenderObject* obj, Vector2f* dir);

/**
 * @brief Ajoute une texture à l'application et l'associe via un entier, son 'id', pour faciliter l'obtention de la texture
 * lors de la création de sprite
 * @see addNewRenderObject createAnimation
 * 
 * @param fileName le file path relatif à l'endroit où se trouve votre éxécutable
 * @param id un entier unique correspondant à l'id associé à la texture
 * @param app (!= NULL)
 */
    void add_Texture(Application* app, const char* fileName, int id);


/**
 * @brief Ajoute un effet sonore à l'application et l'associe via un entier, son 'id', pour faciliter l'obtention de l'effet sonore
 * lors de l'ajout à un RenderObject 
 * @see setSoundEffect
 * 
 * @param fileName le file path relatif à l'endroit où se trouve votre éxécutable
 * @param id un entier unique correspondant à l'id associé à l'effet sonore
 * @param app (!= NULL)
 */
    void add_Sound(Application* app, const char* fileName, int id);


/**
 * @brief ouvre le fichier de musique indiquer 
 * pour qu'il soit prêt à être jouer. S'il y a déja une musique, 
 * la fonction arrête la musique courrante et la change en la nouvelle. Par défaut, la musique
 * courrante se joue en boucle.
 * @see playCurrentMusic
 * 
 * @param app (!= NULL)
 * @param fileName le chemin du fichier de musique relatif à l'endroit où se trouve votre éxécutable
 */
    void openMusicFile(Application* app, const char* fileName);

/**
 * @brief joue la musique courrante ou la resume 
 * @see pauseCurrentMusic
 * 
 * @param app (!= NULL)
 */
    void playCurrentMusic(Application* app);

/**
 * @brief met en pause la musique courrante 
 * @see playCurrentMusic
 * 
 * @param app (!= NULL)
 */
    void pauseCurrentMusic(Application* app);

/**
 * @brief met à jour la vue de la fenêtre
 * 
 * @see setViewSize createView
 * @param app(!=NULL)
 * @param viewID l'entier associé de manière unique à la vue en question
 */
void setView(Application* app, int viewID);


/**
 * @brief active ou pas l'affichage des fps en haut à gauche de la fenêtre
 * 
 * @param app (!= NULL)
 * @param flag 1 -> l'active, 0 -> le désactive (désactivé par défaut)
 * @param fontID l'entier indifiant de manière unique le font utilisé pour l'affichage du texte (doit être présent)
 * @see add_Font
 */
void renderFPS(Application* app, int flag, int fontID);

/**
 * @brief getter pour une des vues stocker dans l'application
 * @see createView
 * 
 * @param app != NULL
 * @param id l'entier associé de manière unique une vue
 * @return le pointeur vers la vue associé à l'entier 'id' passé en argument
 */
View* getView(Application* app, int id);

/**
 * @brief arrête complètement la musique courrante 
 * @see playCurrentMusic
 * 
 * @param app (!= NULL)
 */
    void stopCurrentMusic(Application* app);


/**
 * @brief setter pour le volume de la musique courrante
 * 
 * @param app (!=NULL)
 * @param volume le nouveau volume de la musique (entre 0 (aucun son) et 100 (le maximum de son), par défaut est à 100)
 */
    void setMusicVolume(Application* app, float volume);

/**
 * @brief getter pour le volume de la musique courrante
 * @see setMusicVolume
 * 
 * @param app (!=NULL)
 * @return volume sonore entre 0 et 100
 */
    float getMusicVolume(Application* app);

/**
 * @brief Ajoute une police d'écriture comme ressource à l'application et l'associe via un entier, son 'id', pour faciliter l'obtention de la police
 * lors de l'ajout à un Label
 * @see addNewLabel
 * 
 * @param fileName le file path relatif à l'endroit où se trouve votre éxécutable
 * @param id un entier unique correspondant à l'id associé à la police d'écriture
 * @param app (!= NULL)
 */
    void add_Font(Application* app, const char* fileName, int id);

/**
 * @brief change la couche d'ordre d'affichage du RenderObject passé en argument
 * @see Layers
 * 
 * @param app (!= NULL)
 * @param obj le RenderObject en question (!= NULL)
 * @param new_layer la nouvelle couche à laquelle appartiendra obj après l'exécution de la fonction (cf. Layers)
 * @return 1 si l'objet a été trouvé et a changer de couche, 0 sinon
 */
    int changeRenderObjectLayer(Application* app, RenderObject* obj, int new_layer);

/**
 * @brief enlève de l'application et libère la mémoire occupé par un RenderObject 
 * 
 * @param app l'application en question (!= NULL)
 * @param obj_to_remove l'objet a enlever (!= NULL)
 */
    void removeRenderObject(Application* app, RenderObject* obj_to_remove);

/*******************************/

#ifdef __cplusplus
}
#endif

#endif //APPLICATION_WRAPPER_H