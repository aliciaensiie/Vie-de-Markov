/**
 * @file RenderObject.h
 * @author Félicien Fiscus (felicien.fgay@gmail.com)
 * @brief fichier responsable d'un objet pouvant être rendu et bouger à l'écran
 * @version 0.1
 * @date 2022-04-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef RENDER_OBJECT_H
#define RENDER_OBJECT_H

#include "SFML_includes.h"
#include <functional>

class RenderObject : public sf::Drawable, public sf::Transformable
{
protected:
    sf::Sprite fSprite;
    sf::Sound fSoundEffect;
    sf::FloatRect fHitBox;
    bool fCanBeDrawn;

    std::function<void()> fBeforeDrawing;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
/**
 * @brief Construit un nouveau RenderObject qui pourra être passé dans les draw call
 * 
 * @param texture la texture qui sera rendu à l'écran
 * @param texRect paramètre optionnel, pour spécifié quelle partie de la texture on veut rendre à l'écran
 */
    RenderObject(const sf::Texture& texture, sf::IntRect texRect = sf::IntRect());
    
    /**
     * @brief juste là au cas où, ne fait rien pour l'instant
     * 
     */
    virtual ~RenderObject();

/**
 * @brief fonction pour modifier la texture du sprite afficher
 * 
 * @param newTexture la nouvelle texture
 * @param texRect le nouveau rectangle de texture
 */
    virtual void setTexture(const sf::Texture& newTexture, sf::IntRect texRect);

    /**
     * @brief set l'effet sonore, pour le jouer @see playSound();
     * @param soundBuf l'effet sonore en question
     */
    virtual void setSoundEffect(const sf::SoundBuffer& soundBuf);

/**
 * @brief permet de jouer l'effet sonore, @see setSoundEffect
 * 
 */
    virtual void playSound();

/**
 * @brief setter pour la fonction qui sera appelé juste avant le drawcall
 * cette fonction peut être utilisé pour par exemple modifié la vue de la fenêtre juste avant un draw call
 * @param func la fonction en question
 * 
 */
virtual void setBeforeDrawingFunction(const std::function<void()>& func);

/**
 * @brief setter pour le volume de l'effet sonore, @see setSoundEffect
 * 
 * @param volume 
 */
    virtual void setVolume(float volume);

/**
 * @brief getter pour le volume de l'effet sonore, @see setSoundEffect
 * 
 * @return float 
 */
    virtual float getVolume() const;

/**
 * @brief Set la couleur du sprite
 * 
 * @param color 
 */
    virtual void setSpriteColor(sf::Color color);

/**
 * @brief si l'on veut uniquement changer la texture et laisser le rectangle
 * comme étant la taille de la nouvelle texture
 * 
 * @param newTexture 
 */
    virtual void setTexture(const sf::Texture& newTexture);

/**
 * @brief fonction pour changer le rectangle de rendu de la texture
 * 
 * @param newRect la nouvelle zone de rendu rectangulaire
 */
    virtual void setTextureRect(sf::IntRect newRect);


/**
 * @brief getter pour le sprite si l'on veut directement le modifié
 * 
 * @return pointeur vers fSprite
 */
    virtual sf::Sprite* getSprite();

/**
 * @brief setter pour la hitbox du renderObject @see getBoundingBox 
 * 
 * @param la nouvelle hitbox
 */
    virtual void setBoundingBox(const sf::FloatRect& hitbox);

/**
 * @brief getter pour la hitbox du renderObject @see setBoundingBox 
 * 
 * @return la hitbox
 */
    virtual sf::FloatRect getBoundingBox() const;

/**
 * @brief getter pour savoir si cet objet peut être dessiner à l'écran ou pas
 * 
 * @return true il peut
 * @return false il ne peut pas
 */
    bool canItBeDrawn() const;

/**
 * @brief setter pour faire en sorte que l'objet puisse être dessiner ou pas à l'écran
 * 
 * @param flag true -> il peut, false -> il ne peut pas
 */
    void setCanBeDrawn(bool flag);

};


#endif //RENDER_OBJECT_H