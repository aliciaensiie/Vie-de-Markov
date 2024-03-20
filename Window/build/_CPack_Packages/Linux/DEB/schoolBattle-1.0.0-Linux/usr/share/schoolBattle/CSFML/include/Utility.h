/**
 * @file Utility.h
 * @author Félicien Fiscus (felicien.fgay@gmail.com)
 * @brief header pour tout ce qui relève des fonctions et structure utiles
 * mais qui sont très générale comme le Vector2f ou FloatRect
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef UTILITY_H
#define UTILITY_H
#include "math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief petite structure utilitaire pour gérer les rectangles délimitant et les rectangles de texture
 * @a left et @a top sont respectivement les coordonnées x et y du rectangle en haut à gauche
 */
typedef struct FloatRect
{
    float left;
    float top;
    float width;
    float height;
} FloatRect;

/**
 * @brief moyen rapide de convertir 4 float en un FloatRect
 * 
 * @param left coordonnée X à gauche 
 * @param top coordonnée Y en haut
 * @param width largeur
 * @param height hauteur
 * @return FloatRect  == {left, top, width, height}
 */
FloatRect getFloatRect(float left, float top, float width, float height);

/**
 * @brief petite structure utilitaire pour gérer une paire de coordonnées
 * 
 */
typedef struct Vector2f
{
    float x, y;
} Vector2f;

/**
 * @brief moyen rapide de convertir deux coordonnées en un Vector2f
 * 
 * @return Vector2f == {x, y}
 */
Vector2f getVect2f(float x, float y);
/**
 * @brief retourne la longueur au sens de la norme euclidienne du vecteur
 * 
 * @return sqrt(x^2 + y^2)
 */
float length(Vector2f v);

/*opérations sur Vector2f*/
/**
 * @brief multiplie un scalaire au vecteur et renvoie le résultat
 * 
 * @param scalar le scalaire
 * @param v le vecteur
 * @return Vector2f 
 */
Vector2f times(float scalar, Vector2f v);
/**
 * @brief multiplie un scalaire au vecteur et modifie sa valeur en conséquence
 * 
 * @param scalar le scalaire
 * @param v (!=NULL)
 */
void timesAndModify(float scalar, Vector2f* v);
/**
 * @brief ajoute deux vecteur au sens de l'ajout des coordonnées
 * 
 * @param a 
 * @param b 
 * @return Vector2f le résultat
 */
Vector2f add(Vector2f a, Vector2f b);
/**
 * @brief ajout de vecteurs au sens des coordonnées et stocke le résultat dans le premier vecteur
 * 
 * @param a (!=NULL)
 * @param b  
 */
void addAndModify(Vector2f* a, Vector2f b);
/**
 * @brief soustrait le deuxieme vecteur au premier au sens des coordonnées
 * 
 * @param a 
 * @param b 
 * @return Vector2f le résultat
 */
Vector2f sub(Vector2f a, Vector2f b);
/**
 * @brief soustrait le deuxieme vecteur au premier au sens des coordonnées 
 * et stocke le résultat dans le premier vecteur
 * @param a
 * @param b
 */
void subAndModify(Vector2f* a, Vector2f b);

/*************************/

#ifdef __cplusplus
}
#endif 

#endif /*UTILITY_H*/