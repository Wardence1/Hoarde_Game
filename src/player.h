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
    int regenTime = 15; // seconds
    int regenAmount = 3;
    int atkCoolTime = FPS/4;
    int maxHealth = health;

    int defaultMaxHealth = maxHealth;
    int defaultDamage = damage;
    int defaultKnockback = knockback;
    int defaultSpeed = speed;
    int defaultRegenAmount = regenAmount;
    int defaultAtkCoolTime = atkCoolTime;
    int defaultRegenTime = regenTime;

    unsigned short immunityF = 0; // Immunity frames

    float width, height;
    bool knockBacked = false; // is true when the player is taking knockback

    void update(ProjManager&, HitNumManager&);
    void draw(sf::RenderWindow&);

    void attack(ProjManager&);
    void createSlash(point, int rotation); // creates a slash for the warrior class
    sf::Sprite slash_s;
    bool attacking = false;
    int hitDam = 0;

    direction facing;
    direction hitDir;

private:
    int atkTime = 0, atkCool = FPS*10;
};