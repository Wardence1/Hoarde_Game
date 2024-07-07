#pragma once
#include "globals.h"
#include <SFML/Graphics.hpp>
#include "textures.h"
#include <math.h>

class Enemy;

class Projectile {

public:
    Projectile(const std::string type, point origin, point going, bool rotate=false);
    point pos;
    float rise, run;
    float width, height;
    int speed, damage;
    sf::Sprite sprite;
    std::string type;
    bool rotate;
    bool gone = false;

    void update();
    void draw(sf::RenderWindow&);
};