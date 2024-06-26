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

    for (int i=0; i < Skeleton::amount; i++) { // Do this for every enemy 
        Skeleton::enemy_list[i].update(p, eManager, nManager);
        if (Skeleton::enemy_list[i].dead) {
            Enemy::enemy_list.erase(i+Enemy::enemy_list.begin());
        }
    }

    enemies.clear(); // TODO * this is really inefficient. It would be better for everything to go through each enemy's list instead of enemies.
    enemies.push_back(Skeleton::enemy_list);

    // Spawner

    static bool flip = false; 

    if (tTime%(FPS/2) == 0 && flip) {
        addE("skeleton", {65, 20});
        flip = false;
    }
    else if (tTime%(FPS/2) == 0 && !flip) {
        addE("skeleton", {SCREEN_WIDTH-65, SCREEN_HEIGHT-65});
        flip = true;
    }

}   

void EnemyManager::draw(sf::RenderWindow& window) {

    for (auto e : Skeleton::enemy_list) {
        e.draw(window);
    }
}