//
// Created by macie on 07.05.2020.
//

#ifndef SNAKE_AN_PN13_253316_GAMEOVER_H
#define SNAKE_AN_PN13_253316_GAMEOVER_H

#include "SFML/Graphics.hpp"
#include "SnakeMap.h"
#include <SFML/Audio.hpp>


class GameOver : public sf::Drawable
{
    SnakeMap &map;


    sf::RenderWindow &win;
    sf::RectangleShape background;
    sf::Text text;
    sf::Font font;
    sf::RectangleShape button;
    sf::Text buttonText;


    bool gameOverButton;
public:
    GameOver(sf::RenderWindow &win, SnakeMap &map);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void setGOScreen();
    void buttonPressed(sf::Event &event);
    bool getGOButton();

    bool gameWon();
    bool gameLost();

    void setGOButton();
};


#endif //SNAKE_AN_PN13_253316_GAMEOVER_H
