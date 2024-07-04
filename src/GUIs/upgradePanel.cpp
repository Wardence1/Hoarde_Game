#include "upgradePanel.h"

UpgradePanel::UpgradePanel(point pos, std::string type) {

    this->type = type;

    bigBox.setSize({SCREEN_WIDTH/2, SCREEN_HEIGHT/7});
    bigBox.setOutlineThickness(5);
    bigBox.setFillColor(sf::Color(85, 85, 85));
    bigBox.setOrigin(bigBox.getLocalBounds().width/2, bigBox.getLocalBounds().height/2);
    bigBox.setPosition(pos.x, pos.y);

    title.setFont(PIXEL_F);
    title.setCharacterSize(32);
    description.setFont(PIXEL_F);
    description.setCharacterSize(24);

    /*
    Three types weapon, self, building.
    The first two are self explanitory and the building is something you can place down to slow down / damage enemies.
    */
    randWep = rand()%3;
    randSelf = rand()%2;
    randBuilding = rand()%2;

    // Titles
    if (type == "weapon") {
        switch (randWep) {
            case 0:
                title.setString("Sharpened Blade");
                description.setString("Increases Damage by 1.");
                break;
            case 1:
                title.setString("Stiff Blade");
                description.setString("Increases Knockback.");
                break;
            case 2:
                title.setString("Swift Blade");
                description.setString("Decreases Swing Time.");
                break;
            case 3:
                title.setString("Bigger Blade");
                description.setString("Makes your sword bigger by 20%.");
                break;
            default:
                std::cout << "Random upgrade error.\n";
                exit(1);
                break;
        }
    }
    else if (type == "self") {
        switch (randSelf) {
            case 0:
                title.setString("Aglet");
                description.setString("You go faster by a bit.");
                break;
            case 1:
                title.setString("Blood Herbs");
                description.setString("Decreases regen time.");
                break;
            default:
                std::cout << "Random upgrade error.\n";
                exit(1);
                break;
        }
    }
    else if (type == "building") {
        switch (randBuilding) {
            case 0:
                title.setString("Not a thing yet.");
                description.setString("You can't do this yet.");
                break;
            case 1:
                title.setString("Not a thing yet.");
                description.setString("You can't do this yet.");
                break;
            default:
                std::cout << "Random upgrade error.\n";
                exit(1);
                break;
        }
    }
    else {
        std::cout << "Invalid upgrade type: " << type << "\n";
        exit(1);
    }

    title.setOrigin(title.getLocalBounds().width/2, title.getLocalBounds().height/2);
    description.setOrigin(description.getLocalBounds().width/2, description.getLocalBounds().height/2);
    title.setPosition(pos.x, pos.y-((bigBox.getSize().y/2)-5));
    description.setPosition(pos.x, pos.y+title.getLocalBounds().height-5);
}

void UpgradePanel::update(bool selected) {

    if (selected) {
        bigBox.setFillColor(sf::Color(125, 125, 125));
    } else {
        bigBox.setFillColor(sf::Color(85, 85, 85));
    }
}

void UpgradePanel::pressed(Player& p) {

    if (type == "weapon") {
        switch (randWep) {
            case 0: // Sharpened Blade * Damage + 1
                p.damage += 1;
                break;
            case 1: // Stiff Blade * Knockback + 5
                p.knockback += 5;
                break;
            case 2: // Swift Blade * atkCoolTime - 2
                if (p.atkCoolTime > 2) p.atkCoolTime -= 2;
                break;
            case 3: // Bigger Blade * Blade size increased
                std::cout << "Not programmed yet.\n";
                break;
            default:
                std::cout << "Random upgrade error.\n";
                exit(1);
                break;
        }
    }
    else if (type == "self") {
        switch (randSelf) {
            case 0: // Aglet * Speed +1
                p.speed++;
                break;
            case 1: // Blood herbs * health regen time - 1
                if (p.regenTime > 1) p.regenTime -= 1;
                break;
            default:
                std::cout << "Random upgrade error.\n";
                exit(1);
                break;
        }
    }
    else if (type == "building") {
        switch (randBuilding) {
            case 0:
                std::cout << "Not a thing yet.\n";
                break;
            case 1:
                std::cout << "Not a thing yet.\n";
                break;
            default:
                std::cout << "Random upgrade error.\n";
                exit(1);
                break;
        }
    }
    else {
        std::cout << "Invalid upgrade type: " << type << "\n";
        exit(1);
    }
}

void UpgradePanel::draw(sf::RenderWindow& window) {

    window.draw(bigBox);
    window.draw(title);
    window.draw(description);
}