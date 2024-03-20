#ifndef APPLICATION_H
#define APPLICATION_H
/**
 * @file Application.h
 * @author Félicien Fiscus (felicien.fgay@gmail.com)
 * @brief class Application qui est responsable de l'affichage et de la gestion des évènements
 * @version 0.1
 * @date 2022-04-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "SFML_includes.h"
#include "../include/SFMLEvents.h"
#include <vector>
#include <array>
#include <map>
#include <string>
#include <functional>

class RenderObject;
/**
 * @brief cette class sert aussi de contexte à l'application
 * c'est-à-dire qu'elle stocke et fournit les différentes ressources comme les textures ou les sons
 * 
 */
class Application
{
    std::map<int, sf::Texture*> fTextures;
    std::map<int, sf::SoundBuffer*> fSounds;
    std::map<int, sf::Font*> fFonts;
    std::map<int, class View*> fViews;

    sf::RenderWindow fWindow;

    std::array<std::vector<RenderObject*>, LayersCount> fWhatsToBeRendered;

    sf::Clock fAppClock;
    sf::Clock fInternalClock;   //celle ci est pour afficher le nombre exact de fps et le temps passé entre chaque frame
    sf::Time fDeltaTime = sf::Time::Zero;

    sf::Text fFrameRateText;

    /*ceci est juste pour que l'affichage du framrate soit lisible et donc se fasse pas chaque frame*/
    sf::Time fFpsAccu = sf::Time::Zero;
    sf::Time fFpsDelay = sf::seconds(.7f);

    sf::Music fCurrentMusic;    //on va jamais avoir deux musiques qui jouent en même temps

    bool fDisplayFPS = false;
public:
/**
 * @brief Construit un nouvelle objet Application
 * 
 * @param width la largeur de la fenêtre afficher à l'écran
 * @param height la hauteur de la fenêtre afficher à l'écran
 * @param fps le nombre continue d'images par secondes afficher à l'écran (cela correspons au nombre de fois que la fonction @a update sera appelé en 1 seconde)
 * @param winTitle le nom de la fenêtre
 */
    Application(unsigned int width, unsigned int height, const std::string& winTitle);
/**
 * @brief détruit l'objet application, en prenant soin de libérer la mémoire alloué par les ressources
 * ainsi que par les RenderObjects
 * 
 */
    ~Application();
/**
 * @brief getter pour savoir si la fenêtre est ouverte et si l'application tourne 
 * 
 * @return true si l'application tourne false sinon
 */
bool is_running() const;

/**
 * @brief ferme l'application, ferme la fenêtre de rendu
 * 
 */
void close();

/**
 * @brief getter pour le temps passé depuis le dernier appel à cette fonction
 * 
 * @return sf::Time
 */
    sf::Time getElapsedTime();
/**
 * @brief whether to render the fps and micro seconds at the top left corner
 * 
 * @param flag 
 * @param fontID the valid id uniquely associated with an existing font
 * @see add_Font
 */
    void renderFPS(bool flag, int fontID);

/**
 * @brief contient tout les draw call et display la fenêtre
 * 
 */
    void render();


/**
 * @brief getter pour les différentes vues de fenêtre
 * 
 */
class View* getView(int id);

/**
 * @brief pour ajouter une nouvelle vue dans le contexte @see sf::View
 * 
 * @param view la vue à ajouter
 * @param id l'id à associer à la vue en question
 */
void addView(class View* view, int id);

/**
 * @brief fonction pour gérer les évènements, si un évènement connu à lieu ( @see SFMLEvents.h )
 * 'event' contient cette évènement
 * 
 * @param event le potentiel évènement qui va être retourné (!= NULL)
 * @return true si un évènement connu à lieu, false sinon
 */
    bool isAnEventHappening(SFML_EVENTS* event);

/**
 * @brief vérifie si la touche est pressée actuellement
 * 
 * @param key la touche de clavier pressée
 * @return true si la touche est pressée, faux sinon
 */
    bool isKeyPressedRightNow(SFML_EVENTS key);

/**
 * @brief vérifie si le bouton est pressé actuellement
 * 
 * @param mouse_button le bouton de la souris pressé
 * @return true si le bouton est pressée, faux sinon
 */
    bool isMousePressedRightNow(SFML_EVENTS mouse_button);

/**
 * @brief getter pour la taille de la fenêtre
 * 
 */
unsigned int getWindowWIDTH() const;
unsigned int getWindowHEIGHT() const;


/**
 * @brief l'ajout d'une texture se fait via le path de son fichier
 * 
 * @param fileName le file path
 * @param id l'id correspondant
 */
    void add_Texture(const std::string& fileName, int id);

/**
 * @brief getter pour accéder en lecture à une texture
 * 
 * @param id identificateur de la texture
 * @return la texture en question
 */
    sf::Texture* getTexture(int id);

/**
 * @brief l'ajout d'un son se fait via le path de son fichier
 * 
 * @param fileName le file path
 * @param id l'id correspondant
 */
    void add_Sound(const std::string& fileName, int id);

/**
 * @brief getter pour accéder en lecture à un soundBuffer utilisé pour les effets sonores
 * 
 * @param id identificateur du son
 * @return le soundBuffer en question
 */
    sf::SoundBuffer const* getSound(int id);

/**
 * @brief l'ajout d'un font se fait via le path de son fichier
 * 
 * @param fileName le file path
 * @param id l'id correspondant
 */
    void add_Font(const std::string& fileName, int id);

/**
 * @brief getter pour accéder en lecture à un font, utilisé pour les affichage de sf::Text à l'écran
 * 
 * @param id identificateur du font
 * @return le soundBuffer en question
 */
    sf::Font const* getFont(int id);

/**
 * @brief ouvre le fichier de musique indiquer dans le dossier Resources/Music/
 * pour qu'il soit prêt à être jouer @see playCurrentMusic , si il y a déja une musique, 
 * la fonction arrête la musique courrante et la change en la nouvelle. Par défaut, la musique
 * courrante se joue en boucle.
 * 
 * @param fileName 
 */
    void openMusicFile(const std::string& fileName);

/**
 * @brief joue la musique courrante ou la resume si @see pauseCurrentMusic a été appelé avant
 * 
 */
    void playCurrentMusic();

/**
 * @brief met en pause la musique courrante @see playCurrentMusic
 * 
 */
    void pauseCurrentMusic();

/**
 * @brief arrête la musique courrante @see playCurrentMusic
 * 
 */
    void stopCurrentMusic();


/**
 * @brief setter pour le volume de la musique courrante
 * 
 * @param volume
 */
    void setMusicVolume(float volume);
    

/**
 * @brief getter pour le volume de la musique courrante
 * 
 * @return float 
 */
    float getMusicVolume() const;

/**
 * @brief Getter pour la position du curseur de la souris
 * 
 * @param relative si set à true, alors la position sera par rapport à celle de la fenêtre
 *  sinon ce sera la position absolue (par rapport au coodronnée de l'écran de l'utilisateur)
 * @return la position de la souris 
 */
    sf::Vector2i getMousePosition(bool relative = true);

/**
 * @brief getter pour la fenêtre de rendu
 * 
 * @return sf::RenderWindow* 
 */
sf::RenderWindow* getRenderWindow();

/**
 * @brief ajoute un @see RenderObject à rendre sur la fenetre de l'application, il sera détruit ensuite dans le destructeur
 *  de l'application.
 * 
 * @param obj l'objet en question
 * @param layer la couche correspondant à la position dans 
 */
    void add_RenderObject(RenderObject* obj, Layers layer);

/**
 * @brief change la couche d'ordre de rendu du @see RenderObject correspondant
 * 
 * @param obj l'objet en question
 * @param new_layer la nouvelle couche à laquelle appartiendra @a obj après l'exécution de la fonction
 * @return vrai si l'objet a été trouvé et a changer de couche, faux sinon
 */
    bool changeRenderObjectLayer(RenderObject* obj, Layers new_layer);


/**
 * @brief enlève de l'application un @see RenderObject , l'objet ne sera donc plus rendu à l'écran
 * 
 * @param obj_to_remove l'objet a enlever
 * @return the removed object or nullptr if not found
 */
    RenderObject* removeRenderObject(RenderObject* obj_to_remove);

};

#endif //APPLICATION_H