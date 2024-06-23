#include "enemy.h"
#include "player.h"
#include "enemyManager.h"

Enemy::Enemy() {

    Enemy::allCode += 1;
    code = Enemy::allCode;
}

void Enemy::update(Player& p, EnemyManager& eManager) {

    bool left=false, right=false, up=false, down=false;

    point velo {
        0,
        0
    };

    point eCenter {
        pos.x + width/2,
        pos.y + height/2
    };

    point pCenter {
        p.pos.x + p.width/2,
        p.pos.y + p.height/2
    };


    if (abs(eCenter.x - pCenter.x) > threshold)
        if (eCenter.x > pCenter.x) // left
            velo.x -= speed;
        else // right
            velo.x += speed;

    if (abs(eCenter.y - pCenter.y) > threshold)
        if (eCenter.y > pCenter.y) // up
            velo.y -= speed;
        else // down
            velo.y += speed;

    // Collisions with other enemies
    for (auto const l : eManager.enemies)
        for (auto const e : l) {
            if (e.code != code) // You can't collide with yourself
                if (e.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()) && pos.x < e.pos.x) { // hit from right
                    if (velo.x > 0)
                        velo.x = 0;
                }
                else if (e.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()) && pos.x > e.pos.x) { // hit from left
                    if (velo.x < 0)
                        velo.x = 0;
                }

                if (e.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()) && pos.y < e.pos.y) { // hit from bottom
                    if (velo.y > 0)
                        velo.y = 0;
                }
                else if (e.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()) && pos.y > e.pos.y) { // hit from top
                    if (velo.y < 0)
                        velo.y = 0;
                }
            }   


    if (velo.x && velo.y) { // Stops from moving faster diagonally
        pos.x += velo.x/1.4;
        pos.y += velo.y/1.4;
    }
    else {
        pos.x += velo.x;
        pos.y += velo.y;
    }


    sprite.setPosition(pos.x, pos.y);

    if (sprite.getGlobalBounds().intersects(p.sprite.getGlobalBounds())) // Player hit check
        p.dead = true;

}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

std::vector<Enemy> Enemy::enemy_list;
int Enemy::allCode = 0;