#include "skeleton.h"
#include "../player.h"

Skeleton::Skeleton(point pos) {

    sprite.setTexture(SKELETON_T);
    this->pos = pos;
    sprite.setPosition(pos.x, pos.y);
    sprite.setScale(SCALE, SCALE);

    width = sprite.getTextureRect().width*SCALE;
    height = sprite.getTextureRect().height*SCALE;

    speed = 3;
    damage = 5;
    health = 12;
}

void Skeleton::update(Player& p, EnemyManager& eManager, HitNumManager& nManager, ObjectManager& oMan, ProjManager& pMan) {

    throwTime++;
    if (throwTime >= FPS) {
        throwTime = 0;
        pMan.addP("bone", {pos.x+width, pos.y+(height/2)}, p.pos);
    }

    Enemy::update(p, eManager, nManager, oMan, pMan);
}

