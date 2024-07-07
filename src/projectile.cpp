#include "projectile.h"
#include "enemies/enemy.h"

Projectile::Projectile(const std::string type, point origin, point going, bool rotate) : type(type), rotate(rotate) {

    rise = going.y - origin.y;
    run = going.x - origin.x;
    pos = origin;

    if (type == "bone") {
        sprite.setTexture(BONE_T);
        speed = 10;
        damage = 2;
    }

    // Normalize it
    float length = std::sqrt((rise*rise) + (run*run));
    rise /= length;
    run /= length;

    rise *= speed;
    run *= speed;

    sprite.scale(SCALE, SCALE);
    sprite.setOrigin((sprite.getLocalBounds().width)/2, (sprite.getLocalBounds().height)/2);
    sprite.setPosition({origin.x, origin.y});
}

void Projectile::update() {

    pos.x += run;
    pos.y += rise;

    if (pos.x > SCREEN_WIDTH || pos.x+width < 0 || pos.y+height < 0 || pos.y > SCREEN_HEIGHT) {
        gone = true;
    }

    if (type == "bone") {
        sprite.rotate(4);
    }

    sprite.setPosition(pos.x, pos.y);
}

void Projectile::draw(sf::RenderWindow& window) {

    window.draw(sprite);
}
