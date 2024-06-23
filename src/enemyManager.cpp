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

void EnemyManager::update(Player& p, EnemyManager& eManager) {

    for (auto& l : enemies) {
        for (auto& e : l) {
            e.update(p, eManager);
        }
    }
}   

void EnemyManager::draw(sf::RenderWindow& window) {

    for (auto l : enemies) {
        for (auto e : l) {
            e.draw(window);
        }
    }
}