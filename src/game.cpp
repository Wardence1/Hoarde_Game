#include "game.h"

void Game::start() {
    loadTextures();
    sf::RenderWindow window(sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), TITLE, sf::Style::Close));
    window.setPosition({((int)sf::VideoMode::getDesktopMode().width/2)-(int)SCREEN_WIDTH/2, (int)(sf::VideoMode::getDesktopMode().height/2)-(int)SCREEN_HEIGHT/2});
    window.setFramerateLimit(FPS);

    sf::Event event;
    running = true;
    Player player = Player();
    EnemyManager eManager = EnemyManager();
    ProjManager pManager = ProjManager();
    HitNumManager nManager = HitNumManager();

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
        player.update(pManager, nManager);
        pManager.update();
        eManager.update(player, eManager, nManager);
        nManager.updateM();

        // Draw
        window.clear({45, 45, 45, 0});
        nManager.drawM(window);
        eManager.draw(window);
        pManager.draw(window);
        player.draw(window);
        window.display();
    }
}
