#include "projManager.h"

void ProjManager::update() {

    for (auto& p : projectiles) {
        p.update();
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
