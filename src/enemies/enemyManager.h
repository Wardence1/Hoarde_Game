#pragma once
#include "skeleton.h"
#include "goblin.h"
#include "../player.h"
#include <vector>
#include "../hitNumbers.h"

class EnemyManager {

public:
    void update(Player&, EnemyManager&, HitNumManager&);
    void draw(sf::RenderWindow&);
    void addE(std::string, point, bool side = false); 
};