#pragma once
#include "globals.h"
#include <SFML/Graphics.hpp>
#include "textures.h"
#include "projManager.h"

class EnemyManager;

class Player {

public:
    Player(std::string c_class);
    point pos;
    point velo {0, 0}; // Velocity
    sf::Sprite sprite;
    float speed = 8;
    int damage = 1;
    float knockback = 28;

    float width, height;
    bool dead = false;


    void update(EnemyManager&, ProjManager&);
    void draw(sf::RenderWindow&);

    void attack(EnemyManager&, ProjManager&);
    void createSlash(EnemyManager&, point, int rotation); // creates a slash for the warrior class
    sf::Sprite slash_s;
    int atkTime = 0, atkCool = FPS*10;
    bool attacking = false, sPressed = false; // So you can't hold down the space key.

    enum {
        Wizard,
        Warrior,
        Archer
    } character_class;

    enum {
        Up,
        Down,
        Left,
        Right
    } facing;
};