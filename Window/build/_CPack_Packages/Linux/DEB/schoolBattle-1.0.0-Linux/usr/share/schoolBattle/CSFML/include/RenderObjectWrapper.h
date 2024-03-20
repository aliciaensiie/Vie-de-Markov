/**
 * @file RenderObjectWrapper.h
 * @author Félicien Fiscus (felicien.fgay@gmail.com)
 * @brief ceci est l'interface C pour l'objet C++ RenderObject 
 * @see RenderObject.h
 * @version 0.1
 * @date 2022-04-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef RENDER_OBJECT_WRAPPER_H
#define RENDER_OBJECT_WRAPPER_H

#include "Utility.h"
#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief objet pouvant être rendu à l'écran via l'Application, c'est l'équivalent d'un sprite
 * mais un Label est aussi un RenderObject, d'où certaine fonctions de déplacement et autres
 * qui peuvent être utilisées avec un Label*.
 * 
 */
typedef struct RenderObject RenderObject;
typedef struct Application Application;

/**
 * @brief un pointeur de fonction optionel pour set la fonction 
 * appelé juste avant l'affichage du RenderObject prenant en argument un pointeur vers l'Application et un pointeur vers le RenderObject
 * @see setBeforeDrawingFunction
 * 
 */
typedef void (*PFunction)(Application*, RenderObject*);

/**
 * @brief création d'un nouveau RenderObject qui sera automatiquement mis
 * dans l'application passé en argument et donc rendu à l'écran.
 * @note pour utiliser un rectangle de texture égale à l'entièreté de la texture, 
 * mettez le @textureRect à 0, c'est-à-dire left=top=width=height=0.
 * 
 * @param app l'application valide en question (!= NULL)
 * @param textureID l'entier identifiant de manière unique une texture
 *  @see add_Texture
 * @param textureRect le rectangle de texture spécifiant le rectangle afficher à l'écran
 * @see getFloatRect
 * @param layer la couche de rendu de la texture qui définit l'ordre d'affichage
 * @see Layers
 * @return pointeur vers le RenderObject créer. Sa libération de mémoire aura lieu
 * lors de la destruction de l'application app.
 */
RenderObject* addNewRenderObject(Application* app, int textureID, FloatRect textureRect, int layer);

/**
 * @brief modifie la texture du RenderObject
 * 
 * @param app l'application de contexte (!=NULL)
 * @param obj le renderObject a modifié (!=NULL)
 * @param textureID l'entier identifiant de manière unique une texture
 *  @see add_Texture
 * @param newTextureRect le rectangle de texture spécifiant le rectangle délimitant de la texture qui sera affiché à l'écran
 * @see getFloatRect
 * @param isRepeating si la texture se répète ou pas, càd si lorsque le rectangle de texture est plus grand que la 
 *  texture elle-même, la texture se répète à l'infini au lieu de juste mettre rien
 */
void setTexture(Application* app, RenderObject* obj, int textureID, FloatRect newTextureRect, int isRepeating);

/**
 * @brief change uniquement la texture du RenderObject et laisse le rectangle de texture
 * comme étant la taille de la nouvelle texture et à la position 0,0 (e.g la texture en entier)
 * @see getFloatRect
 * 
 * @param app (!=NULL)
 * @param obj le renderObject a modifié (!=NULL)
 * @param textureID l'entier identifiant de manière unique la texture à set
 *  @see add_Texture
 * @param isRepeating si la texture se répète ou pas, càd si lorsque le rectangle de texture est plus grand que la 
 *  texture elle-même, la texture se répète à l'infini au lieu de juste mettre rien
 */
    void setTextureOnly(Application* app, RenderObject* obj, int newTexID, int isRepeating);

/**
 * @brief change le rectangle de texture à afficher 
 * @note (0,0 correspond au coin en haut à gauche de la texture du RenderObject)
 * @see getFloatRect
 * @param obj le renderObject a modifié (!=NULL)
 * @param textureRect le nouveau rectangle de texture
 */
    void setTextureRectVect(RenderObject* obj, FloatRect textureRect);

/**
 * @brief change le rectangle affiché de la texture du RenderObject
 * @param obj le renderObject a modifié (!=NULL)
 * @param leftRect  les coordonnées du rectangle de texture en x (à gauche -> x = 0) 
 * @param topRect les coordonnées du rectangle de texture en y (en haut -> y = 0)
 * @param widthRect la largeur du rectangle de texture
 * @param heightRect la hauteur du rectangle de texture
 */
    void setTextureRect(RenderObject* obj, int leftRect, int topRect, int widthRect, int heightRect);

/**
 * @brief Getter pour le rectangle de texture
 * 
 * @param obj (!=NULL)
 * @return le rectangle de texture du RenderObject {left, top, width, height}
 */
    FloatRect getTextureRect(RenderObject* obj);

/**
 * 
 * @brief met à jour la position, à l'affichage la position sera par rapport à la vue actuelle de la fenêtre de l'application
 * (en haut à gauche == 0, 0 et en bas à droite == largeur de la vue courante, hauteur de la vue courante)
 * @note par défaut la vue courante de la fenêtre correspond à la fenêtre elle-même, donc 
 * la taille de la vue par défaut == la taille de la fenêtre et de même pour les coordonnées.
 * 
 * @param obj l'objet en question (!= NULL)
 * @param x coordonnées x (augmente vers la droite)
 * @param y coordonnées y (augmente vers le bas)
 */
    void setPosition(RenderObject* obj, float x, float y);
/**
 * 
 * @brief met à jour la position, à l'affichage la position sera par rapport à la vue actuelle de la fenêtre de l'application
 * (en haut à gauche == 0, 0 et en bas à droite == largeur de la vue courante, hauteur de la vue courante)
 * @note par défaut la vue courante de la fenêtre correspond à la fenêtre elle-même, donc 
 * la taille de la vue par défaut == la taille de la fenêtre et de même pour les coordonnées.
 * @see getVect2f
 * @param obj l'objet en question (!= NULL)
 * @param pos vecteur position {x, y} (!=NULL)
 */
    void setPositionVect(RenderObject* obj, Vector2f pos);

/**
 * @brief fait bouger le RenderObject d'une quantité {x, y}, équivalent à setPosition(obj, getX_position(obj) + x, getY_position(obj) + y);
 * @see setPosition
 * 
 * @param obj (!=NULL)
 * @param x la quantité de déplacement en x
 * @param y la quantité de déplacement en y
 */
    void move(RenderObject* obj, float x, float y);

/**
 * @brief fait bouger le RenderObject d'une quantité @a offset, équivalent à setPositionVect(obj, add(get_position(obj), offset));
 * 
 * @see getVect2f
 * @see move
 * @param obj (!=NULL)
 * @param offset le vecteur correspondant à la quantité de déplacement (!=NULL)
 */
    void moveVectRef(RenderObject* obj, const Vector2f* offset);

/**
 * @brief fait bouger le RenderObject d'une quantité @a offset, équivalent à setPositionVect(obj, add(get_position(obj), offset));
 * 
 * @see getVect2f
 * @see move
 * @param obj (!=NULL)
 * @param offset le vecteur correspondant à la quantité de déplacement
 */
    void moveVect(RenderObject* obj, Vector2f offset);

/**
 * @brief getter pour la position de X de l'objet 
 * @see setPosition
 * 
 * @param obj (!=NULL)
 * @return la position X de l'objet
 */
    float getX_position(RenderObject* obj);
    
/**
 * @brief getter pour la position de Y de l'objet
 * @see setPosition
 * 
 * @param obj (!=NULL)
 * @return la position Y de l'objet
 */
    float getY_position(RenderObject* obj);

/**
 * @brief getter pour la position de l'objet à l'aide d'un vecteur position
 * @see getVect2f
 * 
 * @param obj (!= NULL)
 * @return Vector2f le vecteur position {X, Y}
 */
    Vector2f get_position(RenderObject* obj);

/**
 * @brief met à jour le rectangle délimitant le renderObject
 * @note par défaut c'est le rectangle de texture
 * @see getBoundingBox 
 * 
 * @param obj (!= NULL)
 * @param box nouvelle hitbox
 */
    void setBoundingBox(RenderObject* obj, FloatRect box);

/**
 * @brief getter pour le rectangle délimitant le renderObject
 * @note les composantes {left, top} du FloatRect sont les coordonnées du rectangle local au RenderObject, il ne sont pas mis à jour 
 * par les transformations faites sur le RenderObject (i.e move, setPosition, etc.).
 * @see setBoundingBox 
 * 
 * @param obj (!= NULL)
 * @return le membre de la hitbox correspondant
 */
    FloatRect getBoundingBox(RenderObject* obj);

/**
 * @brief vérifie si le point ( @a x, @a y ) est dans le rectangle délimitant le RenderObject
 * @see getBoundingBox
 * 
 * @param obj (!=NULL)
 * @param x coordonnée x du point 
 * @param y coordonnée y du point
 * @return 1 s'il est dedans, 0 sinon
 */
    int containsPoint(RenderObject* obj, float x, float y);

/**
 * @brief teste les collisions entre deux rectangle délimitant (hitbox)
 * 
 * @param box1 (!=NULL)
 * @param box2 (!=NULL)
 * @return 1 s'il y a intersection, 0 sinon
 */
    int intersect(const FloatRect* box1, const FloatRect* box2);


/**
 * @brief met à jour la fonction qui sera appelé juste avant l'affichage du RenderObject
 * @note cette fonction peut être utilisé pour par exemple modifié la vue de la fenêtre juste avant un draw call
 * @see ViewWrapper.h
 * @param func la fonction en question
 * @see PFunction
 * @param obj (!= NULL)
 * @param app (!= NULL)
 */
void setBeforeDrawingFunction(Application* app, RenderObject* obj, PFunction func);


/**
 * @brief remet le comportement par défaut (qui est de ne rien faire) de la fonction appelé juste avant l'affichage du RenderObject
 * @see setBeforeDrawingFunction
 * @param obj (!= NULL)
 * @param app (!= NULL)
 */
void resetBeforeDrawingFunction(Application* app, RenderObject* obj);

/**
 * @brief met à jour l'origine du renderObject, çàd le point sur le RenderObject qui sera le point de coordonnées
 * (x,y) lors de l'appel à setPosition par exemple.
 * @note par défaut l'origine d'un RenderObject est 0, 0 donc en haut à gauche du RenderObject.
 * 
 * @param obj (!=NULL)
 * @param pos la nouvelle origine
 */
void setRenderObjectOrigin(RenderObject* obj, Vector2f pos);



/**
 * @brief met à jour l'origin du RenderObject comme étant le centre de son rectangle délimitant. 
 * @see setRenderObjectOrigin
 * @see setBoundingBox
 * 
 * @param obj (!= NULL)
 */
void centerRenderObjectOrigin(RenderObject* obj);

/**
 * @brief met à jour la couleur du RenderObject (de son rectangle de texture affiché à l'écran) 
 * 
 * @param r la composante rouge (entre 0 et 255)
 * @param g la composante verte (entre 0 et 255)
 * @param b la composante bleue (entre 0 et 255)
 * @param alpha la composante d'opacité (entre 0 et 255)
 */
    void setSpriteColor(RenderObject* obj, int r, int g, int b, int alpha);
/**
 * @brief met à jour l'effet sonore associé au RenderObject
 * @see playSound
 * @see add_Sound
 * @param app (!= NULL)
 * @param obj (!=NULL)
 * @param soundID l'entier associé de manière unique à l'effet sonore en question
 * 
 */
    void setSoundEffect(Application* app, RenderObject* obj, int soundID);

/**
 * @brief joue l'effet sonore
 * @see setSoundEffect
 * @see setVolume
 * @param obj (!= NULL)
 */
    void playSound(RenderObject* obj);

/**
 * @brief met à jour le volume de l'effet sonore
 * @see setSoundEffect
 * @param obj (!= NULL)
 * @param volume la quantité de volume (0 aucun, 100 volume max)
 */
    void setVolume(RenderObject* obj, float volume);


/**
 * @brief getter pour le volume de l'effet sonore
 * @see setSoundEffect
 * @see setVolume
 * 
 * @param obj (!= NULL)
 * @return la quantité de volume (0 -> aucun volume, 100 -> volume max)
 */
    float getVolume(RenderObject* obj);



/**
 * @brief getter pour savoir si cet objet peut être affiché à l'écran ou pas
 * @see setCanRenderObjectBeDrawn
 * 
 * @param obj (!= NULL)
 * @return 1 s'il peut, 0 sinon
 */
    int canRenderObjectBeDrawn(RenderObject* obj);

/**
 * @brief setter pour faire en sorte que l'objet puisse être dessiner ou pas à l'écran
 * @see canRenderObjectBeDrawn
 * 
 * @param obj (!= NULL)
 * @param flag 1 -> il peut, 0 -> il ne peut pas
 */
    void setCanRenderObjectBeDrawn(RenderObject* obj, int flag);


#ifdef __cplusplus
}
#endif

#endif //RENDER_OBJECT_WRAPPER_H