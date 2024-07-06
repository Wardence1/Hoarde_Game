#include "objectManager.h"
#include "../player.h"

void ObjectManager::spawn(std::string type, point pos) {

    if (type == "healing potion" || type == "invincibility potion") {
        Object::objects.push_back(std::make_unique<Potion>(pos, type, false));
    }
    else {
        std::cout << "Invalid object type.\n";
        exit(2);
    }
}

void ObjectManager::update(Player& p) {

    for (int i=0; i<(int)Object::objects.size(); i++) {
        Object::objects[i]->update(p);
        if (Object::objects[i]->gone) {
            Object::objects.erase(i+Object::objects.begin());
        }
    }
}

void ObjectManager::draw(sf::RenderWindow& window) {

    for (auto& object : Object::objects) {
        object->draw(window);
    }
}