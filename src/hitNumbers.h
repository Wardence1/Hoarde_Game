#pragma once
#include "SFML/Graphics.hpp"
#include "globals.h"
#include "textures.h"
#include <list>
#include <iostream>

// A manager and a regular hit number all in one file

class HitNumber {

public:
    HitNumber(point, int amount, bool crit);
    void update();
    void draw(sf::RenderWindow&);
    bool dead = false;
private:
    point pos;
    int speed = 5;
    int time=255;
    int amount;
    sf::Text num;
};

class HitNumManager {

public:
    void updateM();
    void drawM(sf::RenderWindow& window);
    void addN(point, int amount, bool crit=false);
private:
    std::vector<HitNumber> list;
};