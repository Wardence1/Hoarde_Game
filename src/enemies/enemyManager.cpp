#include "enemyManager.h"

void EnemyManager::addE(std::string type, point pos, bool side) {

    if (side) { // Spawn on random side of the screen
        switch(rand()%4) {
            case 0: // Top
                pos.x = rand()%(int)SCREEN_WIDTH;
                pos.y = -8*SCALE; // Needs to get the player's height
                break;
            case 1: // Bottom
                pos.x = rand()%(int)SCREEN_WIDTH;
                pos.y = SCREEN_HEIGHT; // Needs to get the player's height
                rand(); // Just to mix up randoms
                break;
            case 2: // Left
                pos.x = -8*SCALE;
                pos.y = rand()%(int)SCREEN_HEIGHT; // Needs to get the player's height
                break;
            case 3: // Right
                pos.x = SCREEN_WIDTH;
                pos.y = rand()%(int)SCREEN_HEIGHT; // Needs to get the player's height
                rand(); // Just to mix up randoms
                break;
        }
    }

    if (type == "skeleton")
        Enemy::enemy_list.push_back(Skeleton(pos));
    else if (type == "goblin")
        Enemy::enemy_list.push_back(Goblin(pos));
    else
        std::cout << "Invalid enemy type.\n";
}

void EnemyManager::update(Player& p, EnemyManager& eManager, HitNumManager& nManager) {
    
    for (unsigned int i=0; i < Enemy::amount; i++) {
        Enemy::enemy_list[i].update(p, eManager, nManager);
        if (Enemy::enemy_list[i].dead) {
            Enemy::enemy_list.erase(i+Enemy::enemy_list.begin());
        }
    }


    // Spawner
    static bool flip = false; 

    if (tTime%(int)(FPS*1.5f) == 0 && flip) {
        addE("skeleton", {0, 0}, true);
        flip = false;
    }
    else if (tTime%(int)(FPS*1.5f) == 0 && !flip) {
        addE("goblin", {0, 0}, true);
        flip = true;
    }

}   

void EnemyManager::draw(sf::RenderWindow& window) {

    for (auto& e : Enemy::enemy_list) {
        e.draw(window);
    }
}
