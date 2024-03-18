/**
 * @file Animation.h
 * @author Félicien Fiscus (felicien.fgay@gmail.com)
 * @brief une class pour gérer les animations 2D via des spritesheets
 * @version 0.1
 * @date 2022-05-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML_includes.h"

class Animation
{
	sf::Vector2i StartPoint;    //en coordonnées de textures
	const sf::Texture* fTexture;

	int fNumFrames;
	sf::Vector2i fFrameSize;
	size_t fCurrentFrame;
    
	sf::Time fDuration;
	sf::Time fElapsedTime;

	bool fRepeat;
	int fSpriteReadingDir;  //le spritesheet peut être lu de gauche à droite (+1) ou de droite à gauche (-1)

	bool fStopped = false;
	
public:
	Animation();
    //for good measure
    ~Animation(){}
    /**
     * @brief Constructeur explicite car un objet Animation n'est pas qu'une simple texture
     * @see setNumFrames @see setFrameSize @see setDuration
     * 
     * @param texture le spritesheet a utiliser
     */
	explicit Animation(const sf::Texture& texture);
	
    /**
     * @brief Constructeur explicite car les paramètres ne définissent pas complètement une animation
     * @see setNumFrames @see setFrameSize @see setDuration
     * 
     * @param texture le spritesheet a utiliser
     */
    explicit Animation(const sf::Texture& texture, sf::Vector2i StartPoint, int SpriteReadingDir);

/**
 * @brief setter pour le start point de l'animation @see getStartPoint
 * 
 * @param newStartPoint en coordonnées de texture
 */
	void setStartPoint(sf::Vector2i newStartPoint);
/**
 * @brief setter pour le spritesheet utiliser dans l'animation @see getTexture
 * 
 * @param tex 
 */
	void setTexture(const sf::Texture& tex);
/**
 * @brief setter pour le sens de lecture du spritesheet @see getReadingDirection
 * 
 * @param dir (+1 -> de gauche vers la droite | -1 -> de droite vers la gauche)
 */
	void setReadingDirection(int dir);
/**
 * @brief setter pour la taille d'une frame d'animation @see getFrameSize
 * 
 * @param framesize 
 */
	void setFrameSize(sf::Vector2i framesize);
/**
 * @brief setter pour la durée totale de l'animation @see getDuration
 * 
 * @param newTime 
 */
	void setDuration(sf::Time newTime);
/**
 * @brief setter pour le nombre totale de frames constituant l'animation @see getNumFrames
 * 
 * @param Num 
 */
	void setNumFrames(size_t Num);
/**
 * @brief getter pour le start point de l'animation en coordonnées de texture @see setStartPoint
 * 
 * @return sf::Vector2i 
 */
	sf::Vector2i getStartPoint() const;
/**
 * @brief getter pour le spritesheet utiliser @see setTexture
 * 
 * @return const sf::Texture& 
 */
	const sf::Texture& getTexture() const;
/**
 * @brief getter pour le sens de lecture du spritesheet @see setReadingDirection
 * 
 * @return int 
 */
	int getReadingDirection() const;
/**
 * @brief getter pour la taille d'une frame d'animation @see setFrameSize
 * 
 * @return sf::Vector2i 
 */
	sf::Vector2i getFrameSize() const;
/**
 * @brief getter pour la durée de l'animation @see setDuration
 * 
 * @return sf::Time 
 */
	sf::Time getDuration() const;
/**
 * @brief getter pour le nombres de frames constituant l'animation @see setNumFrames
 * 
 * @return size_t 
 */
	size_t getNumFrames() const;
/**
 * @brief getter pour le numéro de la frame courrante sur laquelle est l'animation
 * 
 * @return size_t 
 */
	size_t getCurrentFrame() const;

/**
 * @brief pour pauser l'animation @see start
 * 
 */
	void stop();
/**
 * @brief pour resume l'animation @see stop
 * 
 */
	void start();

/**
 * @brief setter pour si l'animation doit boucler(true) ou pas(false)
 * 
 * @param flag 
 */
	void Repeat(bool flag);
/**
 * @brief getter pour savoir si l'animation tourne en boucle
 * 
 * @return true 
 * @return false 
 */
	bool isRepeating() const;

/**
 * @brief permet de savoir si l'animation est terminée ou pas
 * 
 * @return true 
 * @return false 
 */
	bool isFinished() const;
/**
 * @brief permet de recommencer l'animation, de la réinitialiser au début
 * 
 */
	void Restart();
/**
 * @brief anime le sprite passé en argument, cette fonction doit être
 * appelé chaque frame de l'application pour être efficace
 * 
 * @param dt le deltaTime entre chaque appel de cette fonction
 * @param sprite le sprite à animer (modifie son rectangle de texture)
 */
	void update(sf::Time dt, sf::Sprite& sprite);
	
};

#endif //ANIMATION_H