#pragma once
#include <SFML/Graphics.hpp>
extern const int FPS;
extern const float SCREEN_WIDTH;
extern const float SCREEN_HEIGHT;
extern const char* TITLE;
extern const float SCALE; 
extern int tTime;

struct point {
    float x;
    float y;
};

extern sf::Vector2i mPos; // mouse position
