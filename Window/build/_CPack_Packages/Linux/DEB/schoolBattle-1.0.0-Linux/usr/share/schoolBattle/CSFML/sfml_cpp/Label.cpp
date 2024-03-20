#include "Label.h"
#include <string>

Label::Label(const sf::Font& font, const std::string& text)
    :RenderObject(sf::Texture()), fLabelText(text, font)
{
/* 	sf::FloatRect textBounds = fLabelText.getLocalBounds();
	fLabelText.setOrigin(textBounds.left + 0.5f * textBounds.width, textBounds.top + 0.5f * textBounds.height); */
}


void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    fBeforeDrawing();
    if(fCanBeDrawn)
    {
        states.transform *= getTransform();
        target.draw(fLabelText, states);
    }
}

sf::FloatRect Label::getBoundingBox() const
{
    return sf::FloatRect(getPosition().x, getPosition().y, fLabelText.getLocalBounds().width, fLabelText.getLocalBounds().height);
}


std::string Label::getText() const
{
    return fLabelText.getString().toAnsiString();
}


void Label::setText(const std::string& new_text)
{
    fLabelText.setString(new_text);
}


void Label::setCharacterSize(unsigned int charSize)
{
    fLabelText.setCharacterSize(charSize);
}
unsigned int Label::getCharacterSize() const
{
    return fLabelText.getCharacterSize();
}

void Label::setSpriteColor(sf::Color color)
{
    fLabelText.setFillColor(color);
}