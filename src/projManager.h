#pragma once
#include "projectile.h"
#include <vector>
#include "globals.h"

class ProjManager {

public:
    std::vector<Projectile> projectiles;
    void update();
    void draw(sf::RenderWindow&);
    void addP(const std::string type, const point origin, const point going);        
};