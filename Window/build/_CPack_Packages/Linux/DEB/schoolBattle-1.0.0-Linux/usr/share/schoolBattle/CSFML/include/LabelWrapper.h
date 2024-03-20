/**
 * @file LabelWrapper.h
 * @author Félicien Fiscus (felicien.fgay@gmail.com)
 * @brief wrapper pour l'objet label @see Label.h
 * @version 0.1
 * @date 2022-05-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LABEL_WRAPPER_H
#define LABEL_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif
#include "Utility.h"

/**
 * @brief objet permettant d'afficher du texte sur l'Application. 
 * @note Cette objet dérive
 * de l'objet RenderObject donc les fonctions liés à RenderObject sont aussi valable pour l'objet Label
 * et donc vous pouvez appeler des fonctions prenant en argument un RenderObject* en passant un Label* à la place.
 * @see setPosition
 * @see addNewLabel
 * @see add_Font
 * 
 */
typedef struct Label Label;
typedef struct Application Application;

/**
 * @brief un pointeur de fonction optionel pour set la fonction 
 * appelé juste avant le draw call @see setBeforeDrawingFunction
 * 
 */
//typedef void (*PFunction)(Application*, Label*); //pas besoin pour l'instant

/**
 * @brief création d'un nouveau Label qui sera automatiquement mis
 * dans l'application passé en argument et donc rendu à l'écran.
 * 
 * @param app l'application valide en question (!= NULL)
 * @param fontID l'entier associé à la police d'écriture de manière unique.
 * @see add_Font
 * @param text le texte à afficher (en caractères ascii)
 * @param layer la couche qui définit l'ordre de d'affichage, pour savoir à quel niveau afficher le Label 
 * @see Layers
 * @return pointeur vers le Label créer. Sa libération de mémoire aura lieu
 * lors de la destruction de l'application app.
 */
Label* addNewLabel(Application* app, int fontID, const char* text, int layer);

/**
 * @brief getter pour le rectangle englobant le Label
 * 
 * @param label le label en question
 * @return le plus petit rectangle délimitant le texte du Label 
 * @see getFloatRect
 */
FloatRect getLabelBoundingBox(Label* label);

/**
 * @brief setter pour le texte du Label
 * 
 * @param label (!= NULL)
 * @param new_text le nouveau texte à afficher
 */
void setLabelText(Label* label, const char* new_text);
/**
 * @brief getter pour le texte du Label
 * 
 * @param label (!= NULL)
 * @return le texte du Label
 */
const char* getLabelText(Label* label);
/**
 * @brief setter pour la taille des caractères du texte du Label (par défaut 20)
 * 
 * @param label (!= NULL)
 * @param charSize la nouvelle taille de caractère
 */
void setCharacterSize(Label* label, unsigned int charSize);
/**
 * @brief getter pour la taille actuelle des caractères d'un Label
 * 
 * @param label (!= NULL)
 * @return la taille des caractères du texte du Label
 */
unsigned int getCharacterSize(Label* label);

/**
 * @brief ajoute la chaine de caractère @a textToAdd à la fin du texte du Label
 * @note cette fonction construit une nouvelle string avec le texte du label + textToAdd
 * 
 * @param label (!=NULL)
 * @param textToAdd le texte à ajouter
 */
void appendLabelText(Label* label, const char* textToAdd);


/**
 * @brief getter pour savoir si ce label peut être dessiner à l'écran ou pas
 * 
 * @see setCanLabelBeDrawn
 * @param label (!= NULL)
 * @return 1 il peut, 0 il ne peut pas
 */
    int canLabelBeDrawn(Label* obj);

/**
 * @brief setter pour faire en sorte que le Label puisse être dessiner ou pas à l'écran
 * 
 * @param label (!= NULL)
 * @param flag 1 -> il peut, 0 -> il ne peut pas
 */
    void setCanLabelBeDrawn(Label* label, int flag);



#ifdef __cplusplus
}
#endif

#endif //LABEL_WRAPPER_H