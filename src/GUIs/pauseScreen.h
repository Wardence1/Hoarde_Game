#pragma once
#include <SFML/Graphics.hpp>
#include "../textures.h"
#include "../globals.h"
#include "button.h"
#include <iostream>

class PauseScreen {

public:
    PauseScreen();
    void update();
    void draw(sf::RenderWindow&);

    enum {
        None,
        Resume,
        Settings,
        Title
    } buttons;

private:
    sf::Text paused;
    sf::RectangleShape greyness; // translucent greyness
    Button resume, settings, title;
};