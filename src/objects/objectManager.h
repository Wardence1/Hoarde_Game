#pragma once
#include <vector>
#include "../globals.h"
#include "object.h"
#include "potion.h"

class Player;

class ObjectManager {

public:
    void spawn(std::string type, point pos);
    void update(Player&);
    void draw(sf::RenderWindow&);
};