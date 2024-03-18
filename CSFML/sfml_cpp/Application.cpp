#include "Application.h"
#include "RenderObject.h"
#include "ViewInterface.h"
#include <iostream>
#include <assert.h>

namespace
{
    /**
     * @brief fonction utilitaire pour convertir un event sfml en un event SFML_EVENTS @see SFMLEvents.h
     * 
     * @param e 
     * @return le SFML_EVENTS équivalent 
     */
    SFML_EVENTS convert_event(const sf::Event& e)
    {
        switch(e.type)
        {
            case sf::Event::MouseButtonPressed:
            switch(e.mouseButton.button)
            {
                case sf::Mouse::Left:
                return SFML_EVENTS::MOUSE_LEFT_Pressed;
                break;
                case sf::Mouse::Right:
                return SFML_EVENTS::MOUSE_RIGHT_Pressed;
                break;
                default:
                break;
            }
            break;
            case sf::Event::MouseButtonReleased:
            switch(e.mouseButton.button)
            {
                case sf::Mouse::Left:
                return SFML_EVENTS::MOUSE_LEFT_Released;
                break;
                case sf::Mouse::Right:
                return SFML_EVENTS::MOUSE_RIGHT_Released;
                break;
                default:
                break;
            }
            break;
            case sf::Event::MouseMoved:
            return SFML_EVENTS::MOUSE_MOVED;
            break;
            case sf::Event::KeyPressed:
            switch(e.key.code)
            {
                case sf::Keyboard::A:
                return SFML_EVENTS::KEY_PRESSED_A;
                break;
                case sf::Keyboard::B:
                return SFML_EVENTS::KEY_PRESSED_B;
                break;
                case sf::Keyboard::C:
                return SFML_EVENTS::KEY_PRESSED_C;
                break;
                case sf::Keyboard::D:
                return SFML_EVENTS::KEY_PRESSED_D;
                break;
                case sf::Keyboard::E:
                return SFML_EVENTS::KEY_PRESSED_E;
                break;
                case sf::Keyboard::F:
                return SFML_EVENTS::KEY_PRESSED_F;
                break;
                case sf::Keyboard::G:
                return SFML_EVENTS::KEY_PRESSED_G;
                break;
                case sf::Keyboard::H:
                return SFML_EVENTS::KEY_PRESSED_H;
                break;
                case sf::Keyboard::I:
                return SFML_EVENTS::KEY_PRESSED_I;
                break;
                case sf::Keyboard::J:
                return SFML_EVENTS::KEY_PRESSED_J;
                break;
                case sf::Keyboard::K:
                return SFML_EVENTS::KEY_PRESSED_K;
                break;
                case sf::Keyboard::L:
                return SFML_EVENTS::KEY_PRESSED_L;
                break;
                case sf::Keyboard::M:
                return SFML_EVENTS::KEY_PRESSED_M;
                break;
                case sf::Keyboard::N:
                return SFML_EVENTS::KEY_PRESSED_N;
                break;
                case sf::Keyboard::O:
                return SFML_EVENTS::KEY_PRESSED_O;
                break;
                case sf::Keyboard::P:
                return SFML_EVENTS::KEY_PRESSED_P;
                break;
                case sf::Keyboard::Q:
                return SFML_EVENTS::KEY_PRESSED_Q;
                break;
                case sf::Keyboard::R:
                return SFML_EVENTS::KEY_PRESSED_R;
                break;
                case sf::Keyboard::S:
                return SFML_EVENTS::KEY_PRESSED_S;
                break;
                case sf::Keyboard::T:
                return SFML_EVENTS::KEY_PRESSED_T;
                break;
                case sf::Keyboard::U:
                return SFML_EVENTS::KEY_PRESSED_U;
                break;
                case sf::Keyboard::V:
                return SFML_EVENTS::KEY_PRESSED_V;
                break;
                case sf::Keyboard::W:
                return SFML_EVENTS::KEY_PRESSED_W;
                break;
                case sf::Keyboard::X:
                return SFML_EVENTS::KEY_PRESSED_X;
                break;
                case sf::Keyboard::Y:
                return SFML_EVENTS::KEY_PRESSED_Y;
                break;
                case sf::Keyboard::Z:
                return SFML_EVENTS::KEY_PRESSED_Z;
                break;
                case sf::Keyboard::Num0:
                return SFML_EVENTS::KEY_PRESSED_0;
                break;
                case sf::Keyboard::Num1:
                return SFML_EVENTS::KEY_PRESSED_1;
                break;
                case sf::Keyboard::Num2:
                return SFML_EVENTS::KEY_PRESSED_2;
                break;
                case sf::Keyboard::Num3:
                return SFML_EVENTS::KEY_PRESSED_3;
                break;
                case sf::Keyboard::Num4:
                return SFML_EVENTS::KEY_PRESSED_4;
                break;
                case sf::Keyboard::Num5:
                return SFML_EVENTS::KEY_PRESSED_5;
                break;
                case sf::Keyboard::Num6:
                return SFML_EVENTS::KEY_PRESSED_6;
                break;
                case sf::Keyboard::Num7:
                return SFML_EVENTS::KEY_PRESSED_7;
                break;
                case sf::Keyboard::Num8:
                return SFML_EVENTS::KEY_PRESSED_8;
                break;
                case sf::Keyboard::Num9:
                return SFML_EVENTS::KEY_PRESSED_9;
                break;
                case sf::Keyboard::Enter:
                return SFML_EVENTS::KEY_PRESSED_Enter;
                break;
                case sf::Keyboard::Escape:
                return SFML_EVENTS::KEY_PRESSED_Esc;
                break;
                case sf::Keyboard::Backspace:
                return SFML_EVENTS::KEY_PRESSED_BackSpace;
                break;
                case sf::Keyboard::Space:
                return SFML_EVENTS::KEY_PRESSED_Space;
                break;
                case sf::Keyboard::Up:
                return SFML_EVENTS::KEY_PRESSED_ARROWUP;
                break;
                case sf::Keyboard::Down:
                return SFML_EVENTS::KEY_PRESSED_ARROWDOWN;
                break;
                case sf::Keyboard::Left:
                return SFML_EVENTS::KEY_PRESSED_ARROWLEFT;
                break;
                case sf::Keyboard::Right:
                return SFML_EVENTS::KEY_PRESSED_ARROWRIGHT;
                break;
                default:
                break;
            }
            break;
            case sf::Event::KeyReleased:
            switch(e.key.code)
            {
                case sf::Keyboard::A:
                return SFML_EVENTS::KEY_RELEASED_A;
                break;
                case sf::Keyboard::B:
                return SFML_EVENTS::KEY_RELEASED_B;
                break;
                case sf::Keyboard::C:
                return SFML_EVENTS::KEY_RELEASED_C;
                break;
                case sf::Keyboard::D:
                return SFML_EVENTS::KEY_RELEASED_D;
                break;
                case sf::Keyboard::E:
                return SFML_EVENTS::KEY_RELEASED_E;
                break;
                case sf::Keyboard::F:
                return SFML_EVENTS::KEY_RELEASED_F;
                break;
                case sf::Keyboard::G:
                return SFML_EVENTS::KEY_RELEASED_G;
                break;
                case sf::Keyboard::H:
                return SFML_EVENTS::KEY_RELEASED_H;
                break;
                case sf::Keyboard::I:
                return SFML_EVENTS::KEY_RELEASED_I;
                break;
                case sf::Keyboard::J:
                return SFML_EVENTS::KEY_RELEASED_J;
                break;
                case sf::Keyboard::K:
                return SFML_EVENTS::KEY_RELEASED_K;
                break;
                case sf::Keyboard::L:
                return SFML_EVENTS::KEY_RELEASED_L;
                break;
                case sf::Keyboard::M:
                return SFML_EVENTS::KEY_RELEASED_M;
                break;
                case sf::Keyboard::N:
                return SFML_EVENTS::KEY_RELEASED_N;
                break;
                case sf::Keyboard::O:
                return SFML_EVENTS::KEY_RELEASED_O;
                break;
                case sf::Keyboard::P:
                return SFML_EVENTS::KEY_RELEASED_P;
                break;
                case sf::Keyboard::Q:
                return SFML_EVENTS::KEY_RELEASED_Q;
                break;
                case sf::Keyboard::R:
                return SFML_EVENTS::KEY_RELEASED_R;
                break;
                case sf::Keyboard::S:
                return SFML_EVENTS::KEY_RELEASED_S;
                break;
                case sf::Keyboard::T:
                return SFML_EVENTS::KEY_RELEASED_T;
                break;
                case sf::Keyboard::U:
                return SFML_EVENTS::KEY_RELEASED_U;
                break;
                case sf::Keyboard::V:
                return SFML_EVENTS::KEY_RELEASED_V;
                break;
                case sf::Keyboard::W:
                return SFML_EVENTS::KEY_RELEASED_W;
                break;
                case sf::Keyboard::X:
                return SFML_EVENTS::KEY_RELEASED_X;
                break;
                case sf::Keyboard::Y:
                return SFML_EVENTS::KEY_RELEASED_Y;
                break;
                case sf::Keyboard::Z:
                return SFML_EVENTS::KEY_RELEASED_Z;
                break;
                case sf::Keyboard::Num0:
                return SFML_EVENTS::KEY_RELEASED_0;
                break;
                case sf::Keyboard::Num1:
                return SFML_EVENTS::KEY_RELEASED_1;
                break;
                case sf::Keyboard::Num2:
                return SFML_EVENTS::KEY_RELEASED_2;
                break;
                case sf::Keyboard::Num3:
                return SFML_EVENTS::KEY_RELEASED_3;
                break;
                case sf::Keyboard::Num4:
                return SFML_EVENTS::KEY_RELEASED_4;
                break;
                case sf::Keyboard::Num5:
                return SFML_EVENTS::KEY_RELEASED_5;
                break;
                case sf::Keyboard::Num6:
                return SFML_EVENTS::KEY_RELEASED_6;
                break;
                case sf::Keyboard::Num7:
                return SFML_EVENTS::KEY_RELEASED_7;
                break;
                case sf::Keyboard::Num8:
                return SFML_EVENTS::KEY_RELEASED_8;
                break;
                case sf::Keyboard::Num9:
                return SFML_EVENTS::KEY_RELEASED_9;
                break;
                case sf::Keyboard::Enter:
                return SFML_EVENTS::KEY_RELEASED_Enter;
                break;
                case sf::Keyboard::Escape:
                return SFML_EVENTS::KEY_RELEASED_Esc;
                break;
                case sf::Keyboard::Backspace:
                return SFML_EVENTS::KEY_RELEASED_BackSpace;
                break;
                case sf::Keyboard::Space:
                return SFML_EVENTS::KEY_RELEASED_Space;
                break;
                case sf::Keyboard::Up:
                return SFML_EVENTS::KEY_RELEASED_ARROWUP;
                break;
                case sf::Keyboard::Down:
                return SFML_EVENTS::KEY_RELEASED_ARROWDOWN;
                break;
                case sf::Keyboard::Left:
                return SFML_EVENTS::KEY_RELEASED_ARROWLEFT;
                break;
                case sf::Keyboard::Right:
                return SFML_EVENTS::KEY_RELEASED_ARROWRIGHT;
                break;
                default:
                break;
            }
            break;
            default:
            break;
        }
        
        //std::cerr<<"file Application.cpp : convert_event(e) : unable to match the event type\n";
        return SFML_EVENTS::Unknown;
    }
    
    sf::Keyboard::Key convert_keypressed_event(const SFML_EVENTS& e)
    {
        switch(e)
        {
                case SFML_EVENTS::KEY_PRESSED_A:
                 return sf::Keyboard::A;
                break;
                case SFML_EVENTS::KEY_PRESSED_B:
                 return sf::Keyboard::B;
                break;
                case SFML_EVENTS::KEY_PRESSED_C:
                 return sf::Keyboard::C;
                break;
                case SFML_EVENTS::KEY_PRESSED_D:
                 return sf::Keyboard::D;
                break;
                case SFML_EVENTS::KEY_PRESSED_E:
                 return sf::Keyboard::E;
                break;
                case SFML_EVENTS::KEY_PRESSED_F:
                 return sf::Keyboard::F;
                break;
                case SFML_EVENTS::KEY_PRESSED_G:
                 return sf::Keyboard::G;
                break;
                case SFML_EVENTS::KEY_PRESSED_H:
                 return sf::Keyboard::H;
                break;
                case SFML_EVENTS::KEY_PRESSED_I:
                 return sf::Keyboard::I;
                break;
                case SFML_EVENTS::KEY_PRESSED_J:
                 return sf::Keyboard::J;
                break;
                case SFML_EVENTS::KEY_PRESSED_K:
                 return sf::Keyboard::K;
                break;
                case SFML_EVENTS::KEY_PRESSED_L:
                 return sf::Keyboard::L;
                break;
                case SFML_EVENTS::KEY_PRESSED_M:
                 return sf::Keyboard::M;
                break;
                case SFML_EVENTS::KEY_PRESSED_N:
                 return sf::Keyboard::N;
                break;
                case SFML_EVENTS::KEY_PRESSED_O:
                 return sf::Keyboard::O;
                break;
                case SFML_EVENTS::KEY_PRESSED_P:
                 return sf::Keyboard::P;
                break;
                case SFML_EVENTS::KEY_PRESSED_Q:
                 return sf::Keyboard::Q;
                break;
                case SFML_EVENTS::KEY_PRESSED_R:
                 return sf::Keyboard::R;
                break;
                case SFML_EVENTS::KEY_PRESSED_S:
                 return sf::Keyboard::S;
                break;
                case SFML_EVENTS::KEY_PRESSED_T:
                 return sf::Keyboard::T;
                break;
                case SFML_EVENTS::KEY_PRESSED_U:
                 return sf::Keyboard::U;
                break;
                case SFML_EVENTS::KEY_PRESSED_V:
                 return sf::Keyboard::V;
                break;
                case SFML_EVENTS::KEY_PRESSED_W:
                 return sf::Keyboard::W;
                break;
                case SFML_EVENTS::KEY_PRESSED_X:
                 return sf::Keyboard::X;
                break;
                case SFML_EVENTS::KEY_PRESSED_Y:
                 return sf::Keyboard::Y;
                break;
                case SFML_EVENTS::KEY_PRESSED_Z:
                 return sf::Keyboard::Z;
                break;
                case SFML_EVENTS::KEY_PRESSED_0:
                 return sf::Keyboard::Num0;
                break;
                case SFML_EVENTS::KEY_PRESSED_1:
                 return sf::Keyboard::Num1;
                break;
                case SFML_EVENTS::KEY_PRESSED_2:
                 return sf::Keyboard::Num2;
                break;
                case SFML_EVENTS::KEY_PRESSED_3:
                 return sf::Keyboard::Num3;
                break;
                case SFML_EVENTS::KEY_PRESSED_4:
                 return sf::Keyboard::Num4;
                break;
                case SFML_EVENTS::KEY_PRESSED_5:
                 return sf::Keyboard::Num5;
                break;
                case SFML_EVENTS::KEY_PRESSED_6:
                 return sf::Keyboard::Num6;
                break;
                case SFML_EVENTS::KEY_PRESSED_7:
                 return sf::Keyboard::Num7;
                break;
                case SFML_EVENTS::KEY_PRESSED_8:
                 return sf::Keyboard::Num8;
                break;
                case SFML_EVENTS::KEY_PRESSED_9:
                 return sf::Keyboard::Num9;
                break;
                case SFML_EVENTS::KEY_PRESSED_Enter:
                 return sf::Keyboard::Enter;
                break;
                case SFML_EVENTS::KEY_PRESSED_Esc:
                 return sf::Keyboard::Escape;
                break;
                case SFML_EVENTS::KEY_PRESSED_BackSpace:
                 return sf::Keyboard::Backspace;
                break;
                case SFML_EVENTS::KEY_PRESSED_Space:
                 return sf::Keyboard::Space;
                break;
                case SFML_EVENTS::KEY_PRESSED_ARROWUP:
                return sf::Keyboard::Up;
                break;
                case SFML_EVENTS::KEY_PRESSED_ARROWDOWN:
                return sf::Keyboard::Down;
                break;
                case SFML_EVENTS::KEY_PRESSED_ARROWLEFT:
                return sf::Keyboard::Left;
                break;
                case SFML_EVENTS::KEY_PRESSED_ARROWRIGHT:
                return sf::Keyboard::Right;
                break;
                default:
                break;
            }
        
        return sf::Keyboard::Unknown;
    }

    sf::Mouse::Button convert_mouseButtonpressed_event(const SFML_EVENTS& e)
    {
        switch (e)
        {
        case MOUSE_LEFT_Pressed:
            return sf::Mouse::Left;
            break;
        case MOUSE_RIGHT_Pressed:
            return sf::Mouse::Right;
            break;
        default:
            break;
        }

        std::cerr<<"Error, unknown mouse button pressed in "<<__FUNCTION__<<std::endl;
        return sf::Mouse::Button::Middle;
    }

    
}

Application::Application(unsigned int width, unsigned int height, const std::string& winTitle)
    :fWindow(sf::VideoMode(width, height), winTitle, sf::Style::Close), fTextures(), fSounds(), fAppClock(), fInternalClock(), fFrameRateText(),
    fCurrentMusic()
{
}

Application::~Application()
{
    for(int i = 0;i<LayersCount;++i)
    {
        for(RenderObject* obj : fWhatsToBeRendered[i])
        {
            if(obj)
                delete obj;
        }
    }
    for(auto it : fTextures)
    {
        if(it.second)
            delete it.second;
    }
    for(auto it : fSounds)
    {
        if(it.second)
            delete it.second;
    }
    for(auto it : fViews)
    {
        if(it.second)
            delete it.second;
    }
}


bool Application::is_running() const
{
    return fWindow.isOpen();
}

sf::Time Application::getElapsedTime()
{
    return fAppClock.restart();
}

void Application::renderFPS(bool flag, int fontID)
{
    fDisplayFPS = flag;
    
    fFrameRateText.setFont(*getFont(fontID));
    fFrameRateText.setCharacterSize(10U);
}


unsigned int Application::getWindowWIDTH() const
{
    return fWindow.getSize().x;
}
unsigned int Application::getWindowHEIGHT() const
{
    return fWindow.getSize().y;
}



sf::Vector2i Application::getMousePosition(bool relative)
{
    return (relative) ? sf::Mouse::getPosition(fWindow) : sf::Mouse::getPosition();
}    


void Application::openMusicFile(const std::string& fileName)
{
    fCurrentMusic.stop();
    if(!fCurrentMusic.openFromFile(fileName))
    {
        std::cerr<<__FILE__<<" | "<<__FUNCTION__ << ": failed to open music file "<<fileName<<std::endl;
        exit(1);
    }

    fCurrentMusic.setLoop(true);

}

void Application::playCurrentMusic()
{
    fCurrentMusic.play();
}

void Application::pauseCurrentMusic()
{
    fCurrentMusic.pause();
}

void Application::stopCurrentMusic()
{
    fCurrentMusic.stop();
}


View* Application::getView(int id)
{
    
    auto found = fViews.find(id);
    assert(found != fViews.end());

    return (*found).second;
}

void Application::addView(View* view, int id)
{

    auto inserted = fViews.insert(std::make_pair(id, view));
    if(!inserted.second)
    {
        std::cerr<<__FILE__<<" | "<<__FUNCTION__ <<" :  inserted false"<<std::endl;
        exit(2);
    }
}

void Application::setMusicVolume(float volume)
{
    fCurrentMusic.setVolume(volume);
}

float Application::getMusicVolume() const
{
    return fCurrentMusic.getVolume();
}


sf::RenderWindow* Application::getRenderWindow()
{
    return &fWindow;
}

void Application::render()
{
    fWindow.clear();
    fWindow.setView(fWindow.getDefaultView()); 
    
    for(int i = 0; i < LayersCount; ++i)
    {
        for(RenderObject* obj : fWhatsToBeRendered[i])
        {
            fWindow.draw(*obj);
        }
    }



    /*optional, comment if you don't want it*/
    if(fDisplayFPS)
    {
        fWindow.setView(fWindow.getDefaultView()); 
        fDeltaTime = fInternalClock.restart();
        fFpsAccu += fDeltaTime;
        if(fFpsAccu >= fFpsDelay)
        {
            fFpsAccu = sf::Time::Zero;
            unsigned int fps = 1.f / fDeltaTime.asSeconds();
            fFrameRateText.setString(std::to_string(fps) + " fps\n" + std::to_string(fDeltaTime.asMicroseconds()) + "us/frame");
        }
        fWindow.draw(fFrameRateText);
    }
    /******************************/
    fWindow.display();
}


void Application::close()
{
    fWindow.close();
}

bool Application::isAnEventHappening(SFML_EVENTS* event)
{
    sf::Event e;
    if(fWindow.pollEvent(e))
    {
        if(e.type == sf::Event::Closed) //this event is the only one to be handled by the application itself
        {
            fWindow.close();
            return false;
        }

        *event = convert_event(e);
        return true;
    }

    return false;
}

bool Application::isKeyPressedRightNow(SFML_EVENTS key)
{
    if(key >= KEY_PRESSED_A && key <= KEY_PRESSED_COUNT)
    {
        return sf::Keyboard::isKeyPressed(convert_keypressed_event(key));
    }

    std::cerr<<"wrong key given to "<<__FUNCTION__<<std::endl;
    return false;
}

bool Application::isMousePressedRightNow(SFML_EVENTS mouse_button)
{
    if(mouse_button != MOUSE_LEFT_Pressed && mouse_button != MOUSE_RIGHT_Pressed)
    {
        std::cerr<<"wrong mouse_button given to "<<__FUNCTION__<<std::endl;
        return false;
    }

    return sf::Mouse::isButtonPressed(convert_mouseButtonpressed_event(mouse_button));
}

void Application::add_Texture(const std::string& fileName, int id)
{
    sf::Texture* newTex = new sf::Texture();
    bool check = newTex->loadFromFile(fileName);
    if(!check)
    {
        std::cerr<<__FILE__<<" | "<<__FUNCTION__ <<" :  checked false"<<std::endl;
        exit(1);
    }

    auto inserted = fTextures.insert(std::make_pair(id, newTex));
    if(!inserted.second)
    {
        std::cerr<<__FILE__<<" | "<<__FUNCTION__ <<" :  inserted false"<<std::endl;
        exit(2);
    }
}


void Application::add_Sound(const std::string& fileName, int id)
{
    sf::SoundBuffer* newSound = new sf::SoundBuffer();
    bool check = newSound->loadFromFile(fileName);
    if(!check)
    {
        std::cerr<<__FILE__<<" | "<<__FUNCTION__ <<" :  checked false"<<std::endl;
        exit(1);
    }
    auto inserted = fSounds.insert(std::make_pair(id, newSound));
    if(!inserted.second)
    {
        std::cerr<<__FILE__<<" | "<<__FUNCTION__ <<" :  inserted false"<<std::endl;
        exit(2);
    }
}

void Application::add_Font(const std::string& fileName, int id)
{
    sf::Font* newFont = new sf::Font();
    bool check = newFont->loadFromFile(fileName);
    if(!check)
    {
        std::cerr<<__FILE__<<" | "<<__FUNCTION__ <<" :  checked false"<<std::endl;
        exit(1);
    }

    auto inserted = fFonts.insert(std::make_pair(id, newFont));
    if(!inserted.second)
    {
        std::cerr<<__FILE__<<" | "<<__FUNCTION__ <<" :  inserted false"<<std::endl;
        exit(2);
    }
}


sf::Texture* Application::getTexture(int id)
{
    auto found = fTextures.find(id);
    assert(found != fTextures.end());

    return (*found).second;
}

sf::SoundBuffer const* Application::getSound(int id)
{
    auto found = fSounds.find(id);
    assert(found != fSounds.end());

    return (*found).second;
}

sf::Font const* Application::getFont(int id)
{
    auto found = fFonts.find(id);
    assert(found != fFonts.end());

    return (*found).second;
}

void Application::add_RenderObject(RenderObject* obj, Layers layer)
{
    if(!obj)
    {
        std::cerr<<__FILE__ << " | " << __FUNCTION__<<": nullpointer argument\n";
        return;
    }

    fWhatsToBeRendered[layer].push_back(obj);
}

RenderObject* Application::removeRenderObject(RenderObject* obj_to_remove)
{
    for(int i = 0;i<LayersCount;++i)
    {
        auto found = std::find(fWhatsToBeRendered[i].begin(), fWhatsToBeRendered[i].end(), obj_to_remove);
        if(found != fWhatsToBeRendered[i].end())
        {
            RenderObject* buff = *(found);
            fWhatsToBeRendered[i].erase(found);
            return buff;
        }
    }

    return nullptr;
}

bool Application::changeRenderObjectLayer(RenderObject* obj, Layers new_layer)
{
    if(!obj)
    {
        std::cerr<<__FILE__ << " | " << __FUNCTION__<<": nullpointer argument\n";
        return false;
    }

    for(int i =0;i<LayersCount;++i)
    {
        auto found = std::find(fWhatsToBeRendered[i].begin(), fWhatsToBeRendered[i].end(), obj);
        if(found != fWhatsToBeRendered[i].end())
        {
            if(i == new_layer)
            {
                std::cerr<<__FILE__ << " | " << __FUNCTION__<<": hello there same layer\n";  
                return true;
            }
            fWhatsToBeRendered[new_layer].push_back(*found);
            fWhatsToBeRendered[i].erase(found);
            return true;
        }
    }

    return false;
}






















