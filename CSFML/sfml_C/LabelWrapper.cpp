#include "../include/LabelWrapper.h"
#include "../sfml_cpp/Label.h"
#include "../sfml_cpp/Application.h"
#include <iostream>
#include <string>

extern "C"
{

Label* addNewLabel(Application* app, int fontID, const char* text, int layer)
{

    if(layer <= -1 || layer >= Layers::LayersCount)
    {
        std::cerr<<"error in "<<__FILE__<<" : "<<__FUNCTION__<< "argument 'layer' out of range "<< layer << std::endl;
        exit(1);
    }
    Label* label = new Label(*app->getFont(fontID), std::string(text));
    app->add_RenderObject(label, Layers(layer));
    
    return label;
}

const char* getLabelText(Label* label)
{
    return label->getText().c_str();
}

FloatRect getLabelBoundingBox(Label* label)
{
    sf::FloatRect box = label->getBoundingBox();
    return getFloatRect(box.left, box.top, box.width, box.height);
}

void setLabelText(Label* label, const char* new_text)
{
    label->setText(std::string(new_text));
}

void appendLabelText(Label* label, const char* textToAdd)
{
    label->setText(label->getText() + std::string(textToAdd));
}

void setCharacterSize(Label* label, unsigned int charSize)
{
    label->setCharacterSize(charSize);
}
unsigned int getCharacterSize(Label* label)
{
    return label->getCharacterSize();
}

int canLabelBeDrawn(Label* label)
{
    return label->canItBeDrawn();
}

void setCanLabelBeDrawn(Label* label, int flag)
{
    label->setCanBeDrawn(flag);
}
}