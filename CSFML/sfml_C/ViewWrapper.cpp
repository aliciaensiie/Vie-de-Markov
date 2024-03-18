#include "../include/ViewWrapper.h"
#include "../sfml_cpp/Application.h"
#include "../sfml_cpp/ViewInterface.h"
#include <iostream>


extern "C"
{
    View* createView(Application* app, int id)
    {
        View* view = new View(app->getRenderWindow()->getDefaultView());
        app->addView(view, id);
        return view;
    }

    void setViewSize(View* view, float width, float height)
    { 
        view->setSize(width, height);
    }

    Vector2f getViewSize(View* view)
    {
        return getVect2f(view->getSize().x, view->getSize().y);
    }
    

    void setViewport(View* view, FloatRect view_port)
    {
        view->setViewport(sf::FloatRect(view_port.left, view_port.top, view_port.width, view_port.height));
    }

    void setCenter(View* view, float x, float y)
    {
        view->setCenter(x, y);
    }

    Vector2f getCenter(View* view)
    {
        return getVect2f(view->getCenter().x, view->getCenter().y);
    }

    void moveView(View* view, float offsetX, float offsetY)
    {
        view->move(offsetX, offsetY);
    }

    void zoomView(View* view, float factor)
    {
        view->zoom(factor);
    }

    void setViewRotation(View* view, float angle)
    {
        view->setRotation(angle);
    }
}