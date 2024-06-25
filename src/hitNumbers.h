#pragma once
#include "SFML/Graphics.hpp"
#include "globals.h"
#include "textures.h"
#include <vector>
#include <iostream>

// A manager and a regular hit number all in one file

class HitNumber {

public:
    HitNumber(point, int amount);
    void update();
    void draw(sf::RenderWindow&);
private:
    point pos;
    int speed = 2;
    unsigned char time=0;
    sf::Text num;
};

class HitNumManager {

public:
    void updateM();
    void drawM(sf::RenderWindow& window);
    void addN(point, int amount);
private:
    std::vector<HitNumber> list;
};