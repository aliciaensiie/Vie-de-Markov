#include "../include/ApplicationWrapper.h"
#include "../sfml_cpp/Application.h"
#include "../sfml_cpp/RenderObject.h"
#include "../sfml_cpp/ViewInterface.h"
#include <iostream>

extern "C"
{
    Application* getNewApplication(unsigned int winWIDTH, unsigned int winHEIGHT, const char* win_title)
    {
        Application* app = new Application(winWIDTH, winHEIGHT, std::string(win_title));
        return app;
    }
    
    void free_Application(Application* app)
    {
        delete app;
    }
    
    void closeApplication(Application* app)
    {
        app->close();
    }

    int is_running(Application* app)
    {
        return int(app->is_running());
    }

    
    unsigned int getWindowWIDTH(Application* app)
    {
        return app->getWindowWIDTH();
    }
    unsigned int getWindowHEIGHT(Application* app)
    {
        return app->getWindowHEIGHT();
    }
    
    float getElapsedTime(Application* app)
    {
        return app->getElapsedTime().asSeconds();
    }

    float getMousePositionX(Application* app)
    {
        return app->getRenderWindow()->mapPixelToCoords(app->getMousePosition(true)).x;
    }
    float getMousePositionY(Application* app)
    {
        return app->getRenderWindow()->mapPixelToCoords(app->getMousePosition(true)).y;
    }

    Vector2f getMousePosition(Application* app, View* reference_view)
    {
        sf::Vector2f pos = app->getRenderWindow()->mapPixelToCoords(sf::Mouse::getPosition(*app->getRenderWindow()), *reference_view);
        return getVect2f(pos.x, pos.y);
    }

    float getAbsoluteMousePositionX(Application* app)
    {
        return app->getMousePosition(true).x;
    }

    float getAbsoluteMousePositionY(Application* app)
    {
        return app->getMousePosition(true).y;
    }

    void openMusicFile(Application* app, const char* fileName)
    {
        app->openMusicFile("Resources/Music/" + std::string(fileName));
    }

    void playCurrentMusic(Application* app)
    {
        app->playCurrentMusic();
    }

    void pauseCurrentMusic(Application* app)
    {
        app->pauseCurrentMusic();
    }

    void stopCurrentMusic(Application* app)
    {
        app->stopCurrentMusic();
    }


    void setView(Application* app, int viewID)
    {
        app->getRenderWindow()->setView(*app->getView(viewID));
    }


    View* getView(Application* app, int id)
    {
        return app->getView(id);
    }

    void renderFPS(Application* app, int flag, int fontID)
    {
        app->renderFPS(flag, fontID);
    }

    void setMusicVolume(Application* app, float volume)
    {
        app->setMusicVolume(volume);
    }

    float getMusicVolume(Application* app)
    {
        return app->getMusicVolume();
    }
    
    int isOutsideWindow(Application* app, RenderObject* obj, Vector2f* dir)
    {
        sf::FloatRect r = obj->getBoundingBox();
        sf::FloatRect w(0.f, 0.f, app->getWindowWIDTH(), app->getWindowHEIGHT());
        int result = 0;
        if(r.left <= w.left)
        {
            dir->x = -1.f;
            result = 1;
        }
        if(r.top <= w.top)
        {
            dir->y = -1.f;
            result = 1;
        }
        if(r.left + r.width >= w.left + w.width)
        {
            dir->x = 1.f;
            result = 1;
        }
        if(r.top + r.height >= w.top + w.height)
        {
            dir->y = 1.f;
            result = 1;
        }

        return result;
    }

    void render(Application* app)
    {
        app->render();
    }


    int isAnEventHappening(Application* app, SFML_EVENTS* event)
    {
        return int(app->isAnEventHappening(event));
    }


    int isKeyPressedRightNow(Application* app, SFML_EVENTS key)
    {
        return app->isKeyPressedRightNow(key);
    }

    int isMousePressedRightNow(Application* app, SFML_EVENTS mouse_button)
    {
        return app->isMousePressedRightNow(mouse_button);
    }


    void add_Texture(Application* app, const char* fileName, int id)
    {
        app->add_Texture(std::string(fileName), id);
    }
    
    void add_Sound(Application* app, const char* fileName, int id)
    {
        app->add_Sound(std::string(fileName), id);
    }

    void add_Font(Application* app, const char* fileName, int id)
    {

        app->add_Font(std::string(fileName), id);
    }
    
    
    int changeRenderObjectLayer(Application* app, RenderObject* obj, int new_layer)
    {
        if(new_layer <= -1 || new_layer >= Layers::LayersCount)
        {
            std::cerr<<"error in "<<__FILE__<<" : "<<__FUNCTION__<< "argument 'id' out of range "<< new_layer << std::endl;
            exit(1);
        }
        return app->changeRenderObjectLayer(obj, Layers(new_layer));
    }


    void removeRenderObject(Application* app, RenderObject* obj_to_remove)
    {
        if(!obj_to_remove)
        {
            std::cerr<<__FILE__<< " : " << __FUNCTION__ << " cannot remove a NULL object"<<std::endl;
        }
        else
        {
            RenderObject* obj = app->removeRenderObject(obj_to_remove);
            if(obj)
            {
                delete obj;
            }
            else
            {
                std::cerr<<__FILE__<< " : " << __FUNCTION__ << " object not found"<<std::endl;
            }
        }
    }



}