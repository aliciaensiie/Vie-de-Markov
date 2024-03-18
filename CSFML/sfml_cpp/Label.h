/**
 * @file Label.h
 * @author Félicien Fiscus (felicien.fgay@gmail.com)
 * @brief composant pour afficher du texte sur l'écran à l'aide d'un font à préciser
 * @version 0.1
 * @date 2022-05-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LABEL_H
#define LABEL_H

#include "RenderObject.h"
#include <string>

class Label : public RenderObject
{
    sf::Text fLabelText;

public:
    Label(const sf::Font& font, const std::string& text);
    ~Label(){}

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::FloatRect getBoundingBox() const override;

    void setText(const std::string& new_text);
    std::string getText() const;


    void setCharacterSize(unsigned int charSize);
    unsigned int getCharacterSize() const;

    void setSpriteColor(sf::Color color) override;
};

#endif //LABEL_H