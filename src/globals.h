#pragma once
#include <SFML/Graphics.hpp>
extern const int FPS;
extern const float SCREEN_WIDTH;
extern const float SCREEN_HEIGHT;
extern const char* TITLE;
extern const float SCALE; 
extern int tTime;
extern bool running;
extern unsigned int kills;
extern bool upArrow, downArrow;
extern bool enemyDead;

struct point {
    float x;
    float y;
};

enum direction {
    Up,
    Down,
    Left,
    Right
};

extern enum GAME_STATE {
    Running,
    Dead,
    Paused,
    Menu,
    Upgrading
} game_state;

extern sf::Vector2i mPos; // mouse position
