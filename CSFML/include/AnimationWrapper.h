/**
 * @file AnimationWrapper.h
 * @author Félicien Fiscus (felicien.fgay@gmail.com)
 * @brief interface C de l'objet C++ Animation 
 * @see Animation.h
 * @version 0.1
 * @date 2022-05-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ANIMATION_WRAPPER_H
#define ANIMATION_WRAPPER_H

#include "ApplicationWrapper.h"
#include "Utility.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief une class pour gérer les animation,
 * 	Une animation est constitué d'une texture composée
 * de plusieurs rectangles de textures de même taille
 * décrivant la suite d'images composant l'animation.
 * @see Utility.h 
 * 
 */
typedef struct Animation Animation;

/**
 * @brief créer un objet animation,
 * c'est de la responsabilité de l'utilisateur de libérer la mémoire allouer par cette fonction.
 * @see free_animation
 * @see add_Texture
 * 
 * @param app le contexte de l'application
 * @param texID l'id de la texture composée des images composant l'animation (le spritesheet)
 * @return Le pointeur vers l'animation nouvellement crée. 
 */
Animation* createAnimation(Application* app, int texID);
/**
 * @brief créer un objet animation sur le tas
 * et l'initialise complètement, c'est à la responsabilité
 * de l'utilisateur de libérer la mémoire allouer par cette fonction.
 * @see free_animation
 * 
 * @param app 
 * @param texID l'id de la texture utilisée comme spritesheet
 * @see add_Texture
 * @param X_start coordonnée X du point en haut à gauche de la première image constituant l'animation
 * @param Y_start coordonnée Y du point en haut à gauche de la première image constituant l'animation
 * @param spriteReadingDir sens de lecture du spritesheet (+1 -> défile les images de gauche à droite | -1 -> de droite vers la gauche)
 * @return Le pointeur vers l'objet Animation nouvellement crée.
 */
Animation* initAnimation(Application* app, int texID, int X_start, int Y_start, int spriteReadingDir);

/**
 * @brief libère la mémoire allouer par la création de l'objet Animation
 * @see createAnimation
 * @see initAnimation
 * 
 * @param anim (!=NULL)
 */
void free_animation(Animation* anim);

/**
 * @brief Permet de préparer une animation après qu'elle ait été initialiser
 * @see initAnimation
 * 
 * @param anim (!= NULL) l'animatio en question
 * @param frameSize taille d'une image d'animation
 * @see getVect2f
 * @param duration la durée totale de l'animation en secondes
 * @param numFrames le nombres total d'images constituant l'animation
 * @param repeatFlag si oui ou non l'animation se répète (boolean)
 */
	void setupAnim(Animation* anim, Vector2f frameSize, float duration, unsigned int numFrames, int repeatFlag);

/**
 * @brief setter pour le start point de l'animation
 * @see getAnimStartPoint
 * 
 * @param anim (!= NULL)
 * @param newStartPoint les coordonnées du point en haut à gauche de l'image de départ de l'animation
 */
	void setAnimStartPoint(Animation* anim, Vector2f newStartPoint);
/**
 * @brief setter pour le spritesheet utiliser dans l'animation 
 * 
 * @param app (!=NULL)
 * @param anim (!=NULL)
 * @param texID l'id de la texture qui constitue l'animation
 */
	void setAnimTexture(Application* app, Animation* anim, int texID);
/**
 * @brief setter pour le sens de lecture du spritesheet 
 * @see getAnimReadingDirection
 * 
 * @param anim (!=NULL)
 * @param dir (+1 -> défile les images de gauche vers la droite | -1 -> de droite vers la gauche)
 */
	void setAnimReadingDirection(Animation* anim, int dir);
/**
 * @brief setter pour la taille des images composant l'animation
 * (chaque image doit avoir la même taille) 
 * @see getAnimFrameSize
 * @see getVect2f
 * 
 * @param anim (!=NULL)
 * @param framesize la taille de chaque image
 */
	void setAnimFrameSize(Animation* anim, Vector2f framesize);
/**
 * @brief setter pour la durée totale de l'animation
 * @see getAnimDuration
 * 
 * @param anim (!= NULL)
 * @param newTime en secondes
 */
	void setAnimDuration(Animation* anim, float newTime);
/**
 * @brief setter pour le nombre totale d'images constituant l'animation 
 * @see getAnimNumFrames
 * 
 * @param anim (!=NULL)
 * @param Num nombre d'images total
 */
	void setAnimNumFrames(Animation* anim, unsigned int Num);
/**
 * @brief getter pour le point de départ de l'animation en coordonnées de texture 
 * @see setAnimStartPoint
 * 
 * @param anim (!=NULL)
 * @return le point en haut à gauche de la première image constituant l'animation
 */
	Vector2f getAnimStartPoint(Animation* anim);
/**
 * @brief getter pour le sens de lecture du spritesheet 
 * @see setAnimReadingDirection
 * 
 * @param anim (!=NULL)
 * @return la direction du défilement des images de l'animation (+1 -> de gauche à droite | -1 -> de droite à gauche)
 */
	int getAnimReadingDirection(Animation* anim);
/**
 * @brief getter pour la taille d'une frame d'animation 
 * @see setAnimFrameSize
 * 
 * @param anim (!=NULL)
 * @return taille des images de l'animation
 */
	Vector2f getAnimFrameSize(Animation* anim);
/**
 * @brief getter pour la durée de l'animation 
 * @see setAnimDuration
 * 
 * @param anim (!=NULL)
 * @return la durée en secondes
 */
	float getAnimDuration(Animation* anim);
/**
 * @brief getter pour le nombres de frames constituant l'animation 
 * @see setAnimNumFrames
 * 
 * @param anim (!=NULL)
 * @return nombre d'images de l'animation
 */
	unsigned int getAnimNumFrames(Animation* anim);
/**
 * @brief getter pour le numéro de la frame courrante sur laquelle est l'animation
 * 
 * @param anim (!=NULL)
 * @return l'image affiché actuellement à l'écran par l'animation (entre 0 et @addindex GetNumFrames() - 1) 
 */
	unsigned int getAnimCurrentFrame(Animation* anim);

/**
 * @brief pour pauser l'animation 
 * @see start
 * 
 * @param anim (!=NULL)
 */
	void stopAnim(Animation* anim);
/**
 * @brief pour resumer l'animation @see stop
 * 
 * @param anim (!=NULL)
 */
	void startAnim(Animation* anim);

/**
 * @brief setter pour si l'animation doit boucler(true) ou pas(false)
 * 
 * @param anim (!=NULL)
 * @param flag 0 pour false et 1 pour true
 */
	void RepeatAnim(Animation* anim, int flag);
/**
 * @brief getter pour savoir si l'animation tourne en boucle
 * 
 * @param anim (!=NULL)
 * @return 1 si l'animation tourne en boucle, 0 sinon
 */
	int isAnimRepeating(Animation* anim);

/**
 * @brief permet de savoir si l'animation est terminée ou pas
 * 
 * @param anim (!=NULL)
 * @return 1 si terminée, 0 sinon
 */
	int isAnimFinished(Animation* anim);
/**
 * @brief permet de recommencer l'animation, de la réinitialiser à la première
 * image.
 * 
 * @param anim (!=NULL)
 */
	void RestartAnim(Animation* anim);
/**
 * @brief met à jour la texture du RenderObject passé en argument,
 * la texture du RenderObject doit être la même que celle de l'objet Animation
 * @see RenderObjectWrapper.h
 * 
 * @param anim (!=NULL) doit avoir la même texture que celui du RenderObject passé en argument
 * @param dt le différentiel de temps entre chaque appel de cette fonction (en secondes)
 * @see getElapsedTime
 * @param obj (!=NULL) le render Object à animer (modifie son rectangle de texture)
 */
	void updateAnim(Animation* anim, float dt, RenderObject* obj);
	


#ifdef __cplusplus
}
#endif

#endif /*ANIMATION_WRAPPER_H*/