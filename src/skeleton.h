#pragma once
#include "enemy.h"
#include <iostream>
#include "textures.h"
#include "hitNumbers.h"

class Player;

class Skeleton : public Enemy{

public:
    Skeleton(point pos);
    void update(Player&, EnemyManager&, HitNumManager&);
};