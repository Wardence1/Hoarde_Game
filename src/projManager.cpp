#include "projManager.h"

void ProjManager::update() {

    for (int i=0; i<(int)projectiles.size(); i++) {
        projectiles[i].update();
        if (projectiles[i].gone) {
            projectiles.erase(i+projectiles.begin());
        }
    }
}

void ProjManager::draw(sf::RenderWindow& window) {

    for (auto& p : projectiles) {
        p.draw(window);
    }
}

void ProjManager::addP(const std::string type, const point going, const point origin) {

    projectiles.push_back(Projectile(type, going, origin));
}
