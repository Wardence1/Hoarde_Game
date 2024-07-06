#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../globals.h"
#include "../hitNumbers.h"
#include <iostream>

class Player;

class Object {

public:
    Object(point pos, bool held=false) : pos(pos), held(held) {}
    virtual void update(Player&) {};
    virtual void draw(sf::RenderWindow&);
    virtual void heldUpdate(Player&, HitNumManager&) {};
    bool gone = false;
    point pos;
    bool held;
    sf::Sprite sprite;
    static std::vector<std::unique_ptr<Object>> objects;
};