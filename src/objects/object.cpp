#include "object.h"
#include "../player.h"


void Object::draw(sf::RenderWindow& window) {

    window.draw(sprite);
}

std::vector<std::unique_ptr<Object>> Object::objects; 