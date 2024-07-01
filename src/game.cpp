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
    RunScreen rScreen = RunScreen();
    DeadScreen dScreen = DeadScreen();
    PauseScreen pScreen = PauseScreen();

    while (running) {
        // set randoms seed based on gametime
        tTime++;
        mPos = sf::Mouse::getPosition();

        while (window.pollEvent(event)) {
            if (event.type == event.Closed) {
                window.close();
                running = false;
                break;
            }
            if (event.type == event.KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape && game_state == Running) {
                    game_state = Paused;
                }
                else if (event.key.code == sf::Keyboard::Escape && game_state == Paused) {
                    game_state = Running;
                    pScreen.buttons = pScreen.None;
                }
                
                if (event.key.code == sf::Keyboard::Up)
                    upArrow = true;

                if (event.key.code == sf::Keyboard::Down)
                    downArrow = true;
            }
        }


        // Update
        if (game_state == Running) {
            player.update(pManager, nManager);
            pManager.update();
            eManager.update(player, eManager, nManager);
            nManager.updateM();
            rScreen.update(player);
        } else if (game_state == Dead) {
            dScreen.update(player, nManager);
        } else if (game_state == Paused) {
            pScreen.update();
        }
        upArrow=false;
        downArrow=false;

        // Draw
        window.clear({45, 45, 45, 0});
        rScreen.draw(window);
        nManager.drawM(window);
        eManager.draw(window);
        pManager.draw(window);
        player.draw(window);

        if (game_state == Dead) {
            dScreen.draw(window);
        } else if (game_state == Paused) {
            pScreen.draw(window);
        }
        
        window.display();
    }
}
