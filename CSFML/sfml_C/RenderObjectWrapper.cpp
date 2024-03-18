#include "../include/RenderObjectWrapper.h"
#include "../sfml_cpp/RenderObject.h"
#include "../sfml_cpp/Application.h"
#include <iostream>

extern "C"
{
    
    RenderObject* addNewRenderObject(Application* app, int textureID, FloatRect textureRect, int layer)
    {
        if(layer < 0 || layer >= Layers::LayersCount)
        {
            std::cerr<<__FILE__<<" | "<<__FUNCTION__<<" not valid layer argument: out of range: "<< layer <<std::endl;
            exit(1);
        }
        RenderObject* obj = new RenderObject(*app->getTexture(textureID),
            sf::IntRect(textureRect.left, textureRect.top, textureRect.width, textureRect.height));

        app->add_RenderObject(obj, Layers(layer));

        return obj;
    }

    void setTexture(Application* app, RenderObject* obj, int textureID, FloatRect textureRect, int isRepeating)
    {
        sf::Texture& tex = *app->getTexture(textureID);
        tex.setRepeated(isRepeating);
        obj->setTexture(tex,
            sf::IntRect(textureRect.left, textureRect.top, textureRect.width, textureRect.height));
    }
    
    void setTextureOnly(Application* app, RenderObject* obj, int newTexID, int isRepeating)
    {
        
        sf::Texture& tex = *app->getTexture(newTexID);
        tex.setRepeated(isRepeating);
        obj->setTexture(tex);
    }

    
    void setSoundEffect(Application* app, RenderObject* obj, int soundID)
    {
        obj->setSoundEffect(*app->getSound(soundID));
    }

    
    void playSound(RenderObject* obj)
    {
        obj->playSound();
    }
    
    void setVolume(RenderObject* obj, float volume)
    {
        obj->setVolume(volume);
    }

    float getVolume(RenderObject* obj)
    {
        return obj->getVolume();
    }

    void setBeforeDrawingFunction(Application* app, RenderObject* obj, PFunction func)
    {
        if(!func)
        {
            std::cerr<<__FILE__<<" | "<<__FUNCTION__<<" func null, cannot set a null function"<<std::endl;
            exit(1);
        }
        obj->setBeforeDrawingFunction([app, obj, func](){(*func)(app, obj);});
    }

    void resetBeforeDrawingFunction(Application* app, RenderObject* obj)
    {
        obj->setBeforeDrawingFunction([](){});
    }

    void setRenderObjectOrigin(RenderObject* obj, Vector2f pos)
    {
        obj->setOrigin(pos.x, pos.y);
    }

    void centerRenderObjectOrigin(RenderObject* obj)
    {
        obj->setOrigin(obj->getBoundingBox().width * 0.5f, obj->getBoundingBox().height * 0.5f);
    }

    
    void setTextureRectVect(RenderObject* obj, FloatRect textureRect)
    {
        obj->setTextureRect(sf::IntRect(textureRect.left, textureRect.top, textureRect.width, textureRect.height));
    }

    void setTextureRect(RenderObject* obj, int leftRect, int topRect, int widthRect, int heightRect)
    {
        obj->setTextureRect(sf::IntRect(leftRect, topRect, widthRect, heightRect));
    }
    
    void setPosition(RenderObject* obj, float x, float y)
    {
        obj->setPosition(x, y);
        sf::FloatRect hb = obj->getBoundingBox();
        obj->setBoundingBox(sf::FloatRect(x, y, hb.width, hb.height));
    }
    
    void setPositionVect(RenderObject* obj, Vector2f pos)
    {
        obj->setPosition(pos.x, pos.y);
    }
    
    
    int containsPoint(RenderObject* obj, float x, float y)
    {
        return obj->getBoundingBox().contains(sf::Vector2f(x, y));
    }
    
    void moveVect(RenderObject* obj, Vector2f offset)
    {
        obj->move(offset.x, offset.y);
    }

    void moveVectRef(RenderObject* obj, const Vector2f* offset)
    {
        obj->move(offset->x, offset->y);
    }

    Vector2f get_position(RenderObject* obj)
    {
        return {obj->getPosition().x, obj->getPosition().y};
    }
    
    int intersect(const FloatRect* box1, const FloatRect* box2)
    {
        sf::FloatRect rect1(box1->left, box1->top, box1->width, box1->height);
        sf::FloatRect rect2(box2->left, box2->top, box2->width, box2->height);
        return rect1.intersects(rect2);
    }

    void move(RenderObject* obj, float x, float y)
    {
        obj->move(x, y);
        sf::FloatRect hb = obj->getBoundingBox();
        obj->setBoundingBox(sf::FloatRect(obj->getPosition().x, obj->getPosition().y, hb.width, hb.height));
    }
    
    void setBoundingBox(RenderObject* obj, FloatRect rect)
    {
        obj->setBoundingBox(sf::FloatRect(rect.left, rect.top, rect.width, rect.height));
    }
    
    FloatRect getBoundingBox(RenderObject* obj)
    {
        sf::FloatRect rect = obj->getBoundingBox();
        return {rect.left, rect.top, rect.width, rect.height};
    }

    float getX_position(RenderObject* obj)
    {
        return obj->getPosition().x;
    }

    float getY_position(RenderObject* obj)
    {
        return obj->getPosition().y;
    }

    FloatRect getTextureRect(RenderObject* obj)
    {
        sf::FloatRect rect = sf::FloatRect(obj->getSprite()->getTextureRect());
        return {rect.left, rect.top, rect.width, rect.height};
    }

    
    void setSpriteColor(RenderObject* obj, int r, int g, int b, int alpha)
    {
        obj->setSpriteColor(sf::Color(r, g, b, alpha));
    }


    int canRenderObjectBeDrawn(RenderObject* obj)
    {
        return obj->canItBeDrawn();
    }

    void setCanRenderObjectBeDrawn(RenderObject* obj, int flag)
    {
        obj->setCanBeDrawn(flag);
    }
}