#include "button.h"

Button::Button(std::string string, sf::Color color, point pos, float width, float height, int outlineThickness) {

    button.setSize({width, height});
    text.setString(string);
    text.setFont(PIXEL_F);

    button.setFillColor(color);
    if (outlineThickness) button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(outlineThickness);
    button.setPosition({pos.x, pos.y});

    text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
    text.setPosition({pos.x+(width/2), pos.y+(height/3)});
}

void Button::draw(sf::RenderWindow& window) {

    window.draw(button);
    window.draw(text);
}

void Button::update(bool selected) {
    this->selected = selected;
}
