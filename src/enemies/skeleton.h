#pragma once
#include "enemy.h"
#include <iostream>


class Player;

class Skeleton : public Enemy{

public:
    Skeleton(point pos);
    void update(Player&, EnemyManager&, HitNumManager&);
};