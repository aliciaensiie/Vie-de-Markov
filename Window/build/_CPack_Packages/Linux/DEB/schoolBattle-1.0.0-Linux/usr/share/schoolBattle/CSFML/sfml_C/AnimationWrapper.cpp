#include "../include/AnimationWrapper.h"
#include "../sfml_cpp/Animation.h"
#include "../sfml_cpp/Application.h"
#include "../sfml_cpp/RenderObject.h"
#include <iostream>

extern "C"
{


    Animation* createAnimation(Application* app, int texID)
    {
        Animation* anim = new Animation(*app->getTexture(texID));
        return anim;
    }

    Animation* initAnimation(Application* app, int texID, int X_start, int Y_start, int spriteReadingDir)
    {
        Animation* anim = new Animation(*app->getTexture(texID), sf::Vector2i(X_start, Y_start), spriteReadingDir);

        return anim;
    }
    
    void free_animation(Animation* anim)
    {
        delete anim;
    }

	void setAnimStartPoint(Animation* anim, Vector2f newStartPoint)
    {
        anim->setStartPoint(sf::Vector2i(newStartPoint.x, newStartPoint.y));
    }
    
	void setAnimTexture(Application* app, Animation* anim, int texID)
    {
        anim->setTexture(*app->getTexture(texID));
    }
    
	void setAnimReadingDirection(Animation* anim, int dir)
    {
        anim->setReadingDirection(dir);
    }
    
	void setAnimFrameSize(Animation* anim, Vector2f framesize)
    {
        anim->setFrameSize(sf::Vector2i(framesize.x, framesize.y));
    }
    
	void setAnimDuration(Animation* anim, float newTime)
    {
        anim->setDuration(sf::seconds(newTime));
    }
    
	void setAnimNumFrames(Animation* anim, unsigned int Num)
    {
        anim->setNumFrames(Num);
    }
    
	Vector2f getAnimStartPoint(Animation* anim)
    {
        sf::Vector2i ret = anim->getStartPoint();
        return {(float)ret.x, (float)ret.y};
    }
    
	int getAnimReadingDirection(Animation* anim)
    {
        return anim->getReadingDirection();
    }
    
	Vector2f getAnimFrameSize(Animation* anim)
    {
        sf::Vector2i ret = anim->getFrameSize();
        return {(float)ret.x, (float)ret.y};
    }
    
	float getAnimDuration(Animation* anim)
    {
        return anim->getDuration().asSeconds();
    }
    
	unsigned int getAnimNumFrames(Animation* anim)
    {
        return anim->getNumFrames();
    }
    
	unsigned int getAnimCurrentFrame(Animation* anim)
    {
        return anim->getCurrentFrame();
    }
    
	void stopAnim(Animation* anim)
    {
        anim->stop();
    }
    
	void startAnim(Animation* anim)
    {
        anim->start();
    }
    
	void RepeatAnim(Animation* anim, int flag)
    {
        anim->Repeat(flag);
    }
    
	int isAnimRepeating(Animation* anim)
    {
        return anim->isRepeating();
    }
    
	int isAnimFinished(Animation* anim)
    {
        return anim->isFinished();
    }
    
	void RestartAnim(Animation* anim)
    {
        anim->Restart();
    }
    
	void updateAnim(Animation* anim, float dt, RenderObject* obj)
    {
        anim->update(sf::seconds(dt), *obj->getSprite());
    }
    
	void setupAnim(Animation* anim, Vector2f frameSize, float duration, unsigned int numFrames, int repeatFlag)
    {
        anim->setFrameSize(sf::Vector2i(frameSize.x, frameSize.y));
        anim->setDuration(sf::seconds(duration));
        anim->setNumFrames(numFrames);
        anim->Repeat(repeatFlag);
        anim->Restart();
    }
}