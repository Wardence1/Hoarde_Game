#include "enemy.h"
#include "player.h"
#include "enemyManager.h"

Enemy::Enemy() {

    Enemy::allCode += 1;
    code = Enemy::allCode;
    Enemy::amount++;
}

void Enemy::update(Player& p, EnemyManager& eManager, HitNumManager& nManager) {

    sprite.setColor(sf::Color::White);

    bool left=false, right=false, up=false, down=false;

    // TODO This gets out of sinc after being hit with knockback
    if (velo.x != 0)
        velo.x > 0 ? velo.x -= speed : velo.x += speed;
    if (velo.y != 0)
        velo.y > 0 ? velo.y -= speed : velo.y += speed;

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

    if (hitDam > 0) {
        sprite.setColor(sf::Color::Red);
        health -= hitDam;
        nManager.addN({pos.x, pos.y-5}, hitDam, crit);
        crit=false;
        // Knockback
        switch (p.facing) {
            case p.Up:
                velo.y = -p.knockback;
                break;
            case p.Down:
                velo.y = p.knockback;
                break;
            case p.Left:
                velo.x = -p.knockback;
                break;
            case p.Right:
                velo.x = p.knockback;
                break;        
        }

        hitDam = 0;
    }

    if (health <= 0 && !dead) { // death checks
        Enemy::amount--;
        dead = true;
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
unsigned int Enemy::amount = 0;