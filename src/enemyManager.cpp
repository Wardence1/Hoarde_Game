#include "enemyManager.h"

void EnemyManager::addE(std::string type, point pos) {

    if (type == "skeleton")
        Skeleton::enemy_list.push_back(Skeleton(pos));
    else
        std::cout << "Invalid enemy type.\n";

    enemies.clear();
    // push back all enemy lists here.
    enemies.push_back(Skeleton::enemy_list);
}

void EnemyManager::update(Player& p, EnemyManager& eManager, HitNumManager& nManager) {

    for (auto& l : enemies) {
        for (auto& e : l) {
            e.update(p, eManager, nManager);
        }
    }

    // Spawner
    if (tTime == FPS*0.5)
        for (float i=1; i <= 2; i++)
            addE("skeleton", {i*400, i*120});
}   

void EnemyManager::draw(sf::RenderWindow& window) {

    for (auto l : enemies) {
        for (auto e : l) {
            e.draw(window);
        }
    }
}