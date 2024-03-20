/**
 * @file ViewInterface.h
 * @author Félicien Fiscus (you@domain.com)
 * @brief interface c++ pour l'objet sf::View
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef VIEW_INTERFACE_H
#define VIEW_INTERFACE_H
#include "SFML_includes.h"

class View : public sf::View
{
public:
    View()
    :sf::View()
    {}
    View(const sf::View& view)
    :sf::View(view)
    {}
    ~View(){}
    //toutes les méthodes sont hérités de sf::View
};


#endif //VIEW_INTERFACE_H