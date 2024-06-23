#pragma once
#include "skeleton.h"
#include "player.h"
#include <vector>

class EnemyManager {

public:
    void update(Player&, EnemyManager&);
    void draw(sf::RenderWindow&);
    void addE(std::string, point);
    std::vector<std::vector<Enemy>> enemies;    
};