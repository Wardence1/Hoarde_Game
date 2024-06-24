#include "game.h"

void Game::start() {
    loadTextures();
    sf::RenderWindow window(sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), TITLE, sf::Style::Close));
    window.setPosition({((int)sf::VideoMode::getDesktopMode().width/2)-(int)SCREEN_WIDTH/2, (int)(sf::VideoMode::getDesktopMode().height/2)-(int)SCREEN_HEIGHT/2});
    window.setFramerateLimit(FPS);

    sf::Event event;
    running = true;
    Player player = Player("warrior");
    EnemyManager eManager = EnemyManager();
    ProjManager pManager = ProjManager();

    while (running) {
        tTime++;
        mPos = sf::Mouse::getPosition();

        while (window.pollEvent(event)) {
            if (event.type == event.Closed) {
                window.close();
                running = false;
                break;
            }
        }

        // Update
        player.update(eManager, pManager);
        pManager.update();
        eManager.update(player, eManager);

        // Draw
        window.clear({125, 125, 125, 0});
        eManager.draw(window);
        pManager.draw(window);
        player.draw(window);
        window.display();
    }
}