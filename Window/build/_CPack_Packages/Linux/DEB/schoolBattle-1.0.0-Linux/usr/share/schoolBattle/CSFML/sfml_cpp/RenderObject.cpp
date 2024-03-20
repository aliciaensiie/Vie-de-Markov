#include "RenderObject.h"
#include <iostream>

RenderObject::RenderObject(const sf::Texture& texture, sf::IntRect texRect)
    :fSprite(texture), fHitBox(fSprite.getGlobalBounds()), fSoundEffect(), fBeforeDrawing([](){}), fCanBeDrawn(true)
{
    if(texRect != sf::IntRect())
    {
        fSprite.setTextureRect(texRect);
        fHitBox = fSprite.getGlobalBounds();
    }
}

RenderObject::~RenderObject()
{
}

void RenderObject::setTexture(const sf::Texture& newTexture)
{
    fSprite.setTexture(newTexture, true);
}

void RenderObject::setBoundingBox(const sf::FloatRect& hitbox)
{
    fHitBox = hitbox;
}

sf::FloatRect RenderObject::getBoundingBox() const
{
    return fHitBox;
}

sf::Sprite* RenderObject::getSprite()
{
    return &fSprite;
}    

void RenderObject::playSound()
{
    fSoundEffect.play();
}

void RenderObject::setVolume(float volume)
{
    fSoundEffect.setVolume(volume);
}


void RenderObject::setBeforeDrawingFunction(const std::function<void()>& func)
{

    fBeforeDrawing = func;
}

float RenderObject::getVolume() const
{
    return fSoundEffect.getVolume();
}

void RenderObject::setSoundEffect(const sf::SoundBuffer& soundBuf)
{
    fSoundEffect.setBuffer(soundBuf);
}

void RenderObject::setSpriteColor(sf::Color color)
{
    fSprite.setColor(color);
}

void RenderObject::setTexture(const sf::Texture& newTexture, sf::IntRect texRect)
{
    fSprite.setTexture(newTexture, true);
    fSprite.setTextureRect(texRect);
}


void RenderObject::setTextureRect(sf::IntRect newRect)
{
    fSprite.setTextureRect(newRect);
}


void RenderObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    fBeforeDrawing();
    if(fCanBeDrawn)
    {
        states.transform *= getTransform();

        target.draw(fSprite, states);
    }
}


bool RenderObject::canItBeDrawn() const
{
    return fCanBeDrawn;
}

void RenderObject::setCanBeDrawn(bool flag)
{
    fCanBeDrawn = flag;
}