#include "deadScreen.h"

DeadScreen::DeadScreen() :
    respawn_B(Button("Respawn", {142, 142, 142, 0}, {(float)(SCREEN_WIDTH/2), (SCREEN_HEIGHT/4)+130}, 5)),
    exit_B(Button("Return to Title", {142, 142, 142, 0}, {(float)(SCREEN_WIDTH/2), (SCREEN_HEIGHT/4)+260}, 5)) {
    
    redness.setFillColor({255, 0, 0, 125});
    redness.setPosition(0,0);
    redness.setSize({SCREEN_WIDTH, SCREEN_HEIGHT});
    buttons = None;

    youDied.setString("You Died");
    youDied.setFont(PIXEL_F);
    youDied.setCharacterSize(60);
    youDied.setOrigin(youDied.getLocalBounds().width/2, youDied.getLocalBounds().height/2);
    youDied.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/6);
}

void DeadScreen::update(Player& p, HitNumManager& nMan) {

    exit_B.button.setFillColor(sf::Color(85, 85, 85));
    respawn_B.button.setFillColor(sf::Color(85, 85, 85));
    exit_B.text.setFillColor(sf::Color(225, 225, 225));
    respawn_B.text.setFillColor(sf::Color(225, 225, 225));

    if (buttons == None && downArrow) {
        buttons = Exit;
    } else if (buttons == None && upArrow) {
        buttons = Respawn;
    }

    if ((buttons == Respawn && upArrow) || (buttons == Respawn && downArrow)) {
        buttons = Exit;
    } else if ((buttons == Exit && upArrow) || (buttons == Exit && downArrow)) {
        buttons = Respawn;
    }

    if (buttons == Respawn) {
        respawn_B.button.setFillColor(sf::Color(125, 125, 125));
        respawn_B.text.setFillColor(sf::Color(255, 255, 255));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            game_state = Running;
            // Reset everything
            p.defaultMaxHealth = p.health = p.maxHealth;
            Enemy::enemy_list.clear();
            Enemy::amount = 0;
            nMan.list.clear();
            tTime = 0;
            p.immunityF = 1;
            p.speed = p.defaultSpeed;
            p.knockback = p.defaultKnockback;
            p.damage = p.defaultDamage;
            kills = 0;
            p.pos.x = (SCREEN_WIDTH/2)-(p.width/2);
            p.pos.y = (SCREEN_HEIGHT/2)-(p.height/2);
            p.velo.x = 0;
            p.velo.y = 0;

            buttons = None;
        } 
    }
    else if (buttons == Exit){
        exit_B.button.setFillColor(sf::Color(125, 125, 125));
        exit_B.text.setFillColor(sf::Color(255, 255, 255));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            running = false;
            // TODO * Exit back to menu
        } 
    }
}

void DeadScreen::draw(sf::RenderWindow& window) {

    window.draw(redness);

    respawn_B.draw(window);
    exit_B.draw(window);
    window.draw(youDied);
}