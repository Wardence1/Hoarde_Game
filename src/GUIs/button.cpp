#include "button.h"

Button::Button(std::string string, sf::Color color, point pos, int outlineThickness) {

    button.setSize({width, height});
    text.setString(string);
    text.setFont(PIXEL_F);
    text.setCharacterSize(32);
    text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
    text.setPosition({pos.x, pos.y});

    button.setFillColor(color);
    if (outlineThickness) button.setOutlineColor(sf::Color::White);
    button.setOutlineThickness(outlineThickness);
    button.setSize({text.getLocalBounds().width+20, text.getLocalBounds().height+28});
    button.setOrigin({button.getLocalBounds().width/2, button.getLocalBounds().height/2});
    button.setPosition({pos.x+6, pos.y+14});
}

void Button::draw(sf::RenderWindow& window) {

    window.draw(button);
    window.draw(text);
}

void Button::update(bool selected) {
    
    this->selected = selected;
}
