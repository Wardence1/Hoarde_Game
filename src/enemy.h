#pragma once
#include "globals.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "hitNumbers.h"

class Player;
class EnemyManager;

class Enemy {

public:
    Enemy();
    point pos;
    sf::Sprite sprite;
    static std::vector<Enemy> enemy_list;
    int width, height;
    float speed = 5.5;
    int hitDam = 0;
    const float threshold = speed+1;

    static int allCode; // Every enemy will have they're own num;
    int code;
    int health = 10;


    virtual void update(Player&, EnemyManager&, HitNumManager&);
    virtual void draw(sf::RenderWindow&);

    point velo {
        0,
        0
    };
};


