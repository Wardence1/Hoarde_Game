#pragma once
#include "enemy.h"

class Goblin : public Enemy {
    
public:
    Goblin(point pos);
    void update(Player&, EnemyManager&, HitNumManager&);
};