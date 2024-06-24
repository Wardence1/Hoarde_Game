#pragma once
#include "globals.h"
#include <SFML/Graphics.hpp>
#include "textures.h"

class Enemy;

class Projectile {

public:
    Projectile(const std::string type, point origin, point going);
    point pos;
    float rise, run;
    float width, height;
    sf::Sprite sprite;

    void update();
    void draw(sf::RenderWindow&);
};