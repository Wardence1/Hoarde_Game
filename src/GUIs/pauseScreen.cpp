#include "pauseScreen.h"

PauseScreen::PauseScreen() :
resume(Button("Resume", sf::Color(142, 142, 142, 0), {(float)SCREEN_WIDTH/2, (SCREEN_HEIGHT/4)+(130)}, 5)),
settings(Button("Settings", sf::Color(142, 142, 142, 0), {(float)SCREEN_WIDTH/2, (SCREEN_HEIGHT/4)+(260)}, 5)),
title(Button("Return to Title", sf::Color(142, 142, 142, 0), {(float)SCREEN_WIDTH/2, (SCREEN_HEIGHT/4)+(390)}, 5)) {

    // Background
    greyness.setPosition(0, 0);
    greyness.setSize({SCREEN_WIDTH, SCREEN_HEIGHT});
    greyness.setFillColor({95, 95, 95, 125});

    // Pause Text
    paused.setString("Paused");
    paused.setCharacterSize(60);
    paused.setFont(PIXEL_F);
    paused.setOrigin(paused.getLocalBounds().width/2, paused.getLocalBounds().height/2);
    paused.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/6);

    buttons = None;
}

void PauseScreen::update() {

    resume.button.setFillColor(sf::Color(85, 85, 85));
    settings.button.setFillColor(sf::Color(85, 85, 85));
    title.button.setFillColor(sf::Color(85, 85, 85));
    resume.text.setFillColor(sf::Color(255, 255, 255));
    settings.text.setFillColor(sf::Color(255, 255, 255));
    title.text.setFillColor(sf::Color(255, 255, 255));

    // Selecting a button

    // None
    if (buttons == None && downArrow) {
        buttons = Resume;
    } else if (buttons == None && upArrow) {
        buttons = Title;

    // Resume
    } else if (buttons == Resume && downArrow) {
        buttons = Settings;
    } else if (buttons == Resume && upArrow) {
        buttons = Title;
    
    // Settings
    } else if (buttons == Settings && downArrow) {
        buttons = Title;
    } else if (buttons == Settings && upArrow) {
        buttons = Resume;

    // Title
    } else if (buttons == Title && downArrow) {
        buttons = Resume;
    } else if (buttons == Title && upArrow) {
        buttons = Settings;
    }

    // Make the buttons light up
    if (buttons == Resume) {
        resume.button.setFillColor(sf::Color(125, 125, 125));
        resume.text.setFillColor(sf::Color(255, 255, 255));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            game_state = Running;
            buttons = None;
        }
    } else if (buttons == Settings) {
        settings.button.setFillColor(sf::Color(125, 125, 125));
        settings.text.setFillColor(sf::Color(255, 255, 255));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            std::cout << "You can't do that yet.\n"; // TODO * Settings menu
            buttons = None;
        }
    } else if (buttons == Title) {
        title.button.setFillColor(sf::Color(125, 125, 125));
        title.text.setFillColor(sf::Color(255, 255, 255));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            exit(0); // TODO * Title screen
        }
    }
}

void PauseScreen::draw(sf::RenderWindow& window) {

    window.draw(greyness);

    window.draw(paused);
    resume.draw(window);
    settings.draw(window);
    title.draw(window);
}