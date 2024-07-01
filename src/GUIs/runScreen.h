#pragma once
#include <SFML/Graphics.hpp>
#include "../globals.h"
#include "../textures.h"
#include "../player.h"

class RunScreen {

public:
    RunScreen();
    void update(Player&);
    void draw(sf::RenderWindow&);

private:
    sf::Text kills_t;
    sf::Text health_t;
};