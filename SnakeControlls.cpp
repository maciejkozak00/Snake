//
// Created by macie on 05.05.2020.
//

#include "SnakeControlls.h"

SnakeControlls::SnakeControlls(SnakeMap &map, SnakeCharacter &snake) :map(map), snake(snake)
{
    goToMM = false;
}

void SnakeControlls::handleEvent(sf::Event &event, sf::Clock &clock)
{
    if(event.type == sf::Event::KeyReleased)
    {
        if(event.key.code == sf::Keyboard::W)
        {
            snake.moveSnakeUp();
            if(snake.getLastMove() != DOWN)
                clock.restart();
        }
        if(event.key.code == sf::Keyboard::S)
        {
            snake.moveSnakeDown();
            if(snake.getLastMove() != UP)
                clock.restart();
        }
        if(event.key.code == sf::Keyboard::A)
        {
            snake.moveSnakeLeft();
            if(snake.getLastMove() != RIGHT)
                clock.restart();
        }
        if(event.key.code == sf::Keyboard::D)
        {
            snake.moveSnakeRight();
            if(snake.getLastMove() != LEFT)
                clock.restart();
        }
    }
}



