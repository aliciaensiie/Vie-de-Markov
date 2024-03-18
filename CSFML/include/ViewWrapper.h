/**
 * @file ViewWrapper.h
 * @author Félicien Fiscus (felicien.fgay@gmail.com)
 * @brief petit wrapper pour l'objet sf::View @see ViewInterface.h
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef VIEW_WRAPPER_H
#define VIEW_WRAPPER_H

#include "Utility.h"
#ifdef __cplusplus
extern "C"
{
#endif



/**
 * @brief Une vue (View) est un rectangle d'affichage correspondant à la scène de la fenêtre d'affichage,
 * c'est la caméra du monde qu'affiche l'Application.
 * @see setView
 */
typedef struct View View;

/**
 * @brief construit une View sur le tas, en utilisant la vue par défaut de la fenêtre d'Application, et 
 * en l'ajoute directement à l'application (donc pas besoin de free côté utilisateur)
 * 
 * @param app (!= NULL) l'Application dont la vue de la fenêtre courrante sera utilisé pour créer la nouvelle vue
 * @param id l'id associer de manière unique à la vue
 * @return la nouvelle vue créer
 */
View* createView(struct Application* app, int id);


/**
 * @brief setters pour la taille de la vue de la fenêtre
 * une vue est un rectangle correspondant à la partie visible du monde,
 * par défaut la taille est celle du target (de la fenêtre)
 * @note si la vue est de taille plus grande que la fenêtre, ça fait l'effet de dézoomer sur la partie au centre de la vue.
 * Si la vue est de taille plus petite que la fenêtre, ça fait l'effet de zoomer sur la partie au centre de la vue
 * @see zoomView
 * @see getViewSize
 * 
 * @param view (!=NULL)
 * @param width nouvelle largeur
 * @param height nouvelle hauteur
 */
    void setViewSize(View* view, float width, float height);

/**
 * @brief getter pour la taille de la vue @see setViewSize
 * 
 * @param view (!= NULL)
 * @return Vector2f la taille de la vue
 */
    Vector2f getViewSize(View* view);

/**
 * @brief setter pour le cadre de vue de la fenêtre 
 * @note le cadre de vue est exprimé en terme de ratio, (0, 0, 1, 1) représente la fenêtre complet
 *  et par exemple (0, 0, 0.5, 1) correspond à la moitié gauche de la fenêtre
 *  (0.5, 0, 0.5, 1) correspond à la moitié droite, etc.
 * @see setViewSize
 * @param view (!=NULL)
 * @param view_port le nouveau cadre de vue considéré
 */
    void setViewport(View* view, FloatRect view_port);
/**
 * @brief setter pour le centre de la vue de la fenêtre
 * @see setViewSize
 * 
 * @param view (!= NULL)
 * @param x coordonnée x du nouveau centre
 * @param y coordonnée y du nouveau centre
 */
    void setCenter(View* view, float x, float y);

/**
 * @brief getter pour le centre de la vue
 * @see setCenter
 * 
 * @param view (!= NULL)
 * @return Vector2f le centre de la vue
 */
    Vector2f getCenter(View* view);

/**
 * @brief bouge la vue (i.e la caméra) de la fenêtre
 * 
 * @param view (!=NULL)
 * @param offsetX quantité de déplacement en X
 * @param offsetY quantité de déplacement en Y
 */
    void moveView(View* view, float offsetX, float offsetY);
/**
 * @brief modifie la taille de la vue de la fenêtre relativement à sa taille courante, 
 * cela à pour effet de 'zoomer' si @a factor > 1, la vue est agrandi (les objets paraissent plus petit)
 * si @a factor < 1, la vue est rapetissi (les objets paraissent plus gros) et @a factor == 1 ne change rien
 * @see setViewSize
 * 
 * @param view (!= NULL)
 * @param factor 
 */
    void zoomView(View* view, float factor);
/**
 * @brief setter pour la rotation de la vue (0 degrés par défaut)
 * 
 * @param view (!= NULL)
 * @param angle (en degrés)
 */
    void setViewRotation(View* view, float angle);




#ifdef __cplusplus
}
#endif

#endif /*VIEW_WRAPPER_H*/