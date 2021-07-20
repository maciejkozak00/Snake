#include "SnakeSFMLView.h"
#include "SnakeMap.h"
#include "SnakeCharacter.h"
#include "SFML/Graphics.hpp"
#include "SnakeControlls.h"
#include "GameManager.h"
#include "GameOver.h"
#include "MainMenu.h"
#include "HighScore.h"
#include "Settings.h"

int main() {
    sf::RenderWindow win (sf::VideoMode(900, 900), "Glizda", sf::Style::Close);
    Settings settings(win);

    SnakeCharacter snake;
    snake.startSnake();

    SnakeMap map (snake);

    SnakeSFMLView view (map, snake, settings);


    SnakeControlls ctrl (map, snake);

    GameOver go(win, map);
    HighScore hs(snake, go);

    MainMenu menu(win);

    GameManager man(map, snake, ctrl, go, menu, settings, hs);

    view.setBlocksSize(win);
    view.setWalls(win);

    ////in game time
    sf::Clock clock;
    clock.restart().asMilliseconds();
    ////

    int scene = 0; //managing game

    while(win.isOpen())
    {
        man.setVolume();
        win.clear(sf::Color(30, 30, 50));
        sf::Event event{};
        while(win.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                win.close();
            }
            switch (scene)
            {
                case 0: //main menu
                menu.buttonPressed(event);
                menu.setDifficulty(event);
                    break;
                case 1: //game
                    ctrl.handleEvent(event, clock);
                    break;
                case 2://game finished
                    go.buttonPressed(event);
                    break;
                case 3: //settings
                settings.isButtonPressed(event);
                break;
                default: abort();
            }
        }

        switch(scene)
        {
            case 0: //main menu
            menu.setMMScreen();
            menu.setHS();
            win.draw(menu);
            break;
            case 1: //game
                man.foodAte();
                view.viewManager(win);
                man.moveSnake(snake, clock);
                win.draw(view);
            break;
            case 2: //game finished
                go.setGOScreen();
                win.draw(go);
                hs.manageFile();
            break;
            case 3: //settings
            settings.setScreen();
            win.draw(settings);
            break;
            default: abort();
        }
        man.setGameScene(scene);
        win.display();
    }
    return 0;
}

