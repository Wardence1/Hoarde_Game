#pragma once
#include "globals.h"
#include <SFML/Graphics.hpp>
#include "textures.h"
#include "hitNumbers.h"
#include "projManager.h"

class EnemyManager;

class Player {

public:
    Player();
    point pos;
    point velo {0, 0}; // Velocity
    sf::Sprite sprite;
    float speed = 8;
    int damage = 5;
    float knockback = 28;
    int health = 25;
    int maxHealth = health;
    unsigned short immunityF = 0; // Immunity frames

    float width, height;
    bool knockBacked = false; // is true when the player is taking knockback

    void update(ProjManager&, HitNumManager&);
    void draw(sf::RenderWindow&);

    void attack(ProjManager&);
    void createSlash(point, int rotation); // creates a slash for the warrior class
    sf::Sprite slash_s;
    int atkTime = 0, atkCool = FPS*10;
    bool attacking = false, sPressed = false; // So you can't hold down the space key.
    int hitDam = 0;

    direction facing;
    direction hitDir;
};