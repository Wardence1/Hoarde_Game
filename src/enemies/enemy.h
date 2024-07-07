#pragma once
#include "../globals.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "../hitNumbers.h"
#include "../objects/objectManager.h"
#include "../projManager.h"

class Player;
class EnemyManager;

class Enemy {

public:
    Enemy();
    point pos;
    sf::Sprite sprite;
    static std::vector<std::unique_ptr<Enemy>> enemy_list;
    int width, height;
    float speed = 5.5;
    int hitDam = 0;
    float threshold = speed+1;
    unsigned int damage = 3; 
    int health = 10;

    static int allCode; // Every enemy will have they're own num;
    int code;
    static unsigned int amount;
    bool dead = false;
    bool crit = false;

    virtual void update(Player&, EnemyManager&, HitNumManager&, ObjectManager&, ProjManager&);
    virtual void draw(sf::RenderWindow&);

    point velo {
        0,
        0
    };

    direction facing;
};


