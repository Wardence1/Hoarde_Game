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

    float width, height;
    bool dead = false;


    void update(EnemyManager&, ProjManager&);
    void draw(sf::RenderWindow&);
    void attackTime(EnemyManager&, ProjManager&); // When the player attacks

    enum {
        Wizard,
        Warrior,
        Archer
    } character_class;

    struct {
        bool up;
        bool down;
        bool left;
        bool right;
    } facing;
};