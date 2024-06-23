#pragma once
#include "globals.h"
#include <SFML/Graphics.hpp>
#include "textures.h"

class Player {

public:
    Player();
    point pos;
    point velo {0, 0}; // Velocity
    sf::Sprite sprite;
    float speed = 8;

    float width, height;
    bool dead = false;


    void update();
    void draw(sf::RenderWindow&);
};