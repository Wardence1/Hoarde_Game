#include "globals.h"

const int FPS = 60;
const float SCREEN_WIDTH = 1200;
const float SCREEN_HEIGHT = SCREEN_WIDTH/(16.0f/9.0f); // 16:9 ratio
const char* TITLE = "Hoard Game";
const float SCALE = 6;
int tTime = 0; // Total time gone by
sf::Vector2i mPos = {0, 0};

