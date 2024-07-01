#pragma once
#include "SFML/Graphics.hpp"
#include "../globals.h"
#include "../textures.h"

class Button {

public:
    Button(std::string string, sf::Color, point pos, int outlineThickness=0);
    void update(bool selected);
    void draw(sf::RenderWindow&);
    sf::Text text;
    float width, height;
    bool selected;
    sf::RectangleShape button;
};