//
// Created by macie on 05.05.2020.
//

#ifndef SNAKE_AN_PN13_253316_SNAKECONTROLLS_H
#define SNAKE_AN_PN13_253316_SNAKECONTROLLS_H

#include "SnakeMap.h"
#include "SnakeCharacter.h"
#include "SFML/Graphics.hpp"
#include "GameOver.h"

class SnakeControlls {

    SnakeMap &map;
    SnakeCharacter &snake;
    bool goToMM;
public:
    SnakeControlls(SnakeMap &map, SnakeCharacter &snake);
    void handleEvent(sf::Event &event, sf::Clock &clock);

};


#endif //SNAKE_AN_PN13_253316_SNAKECONTROLLS_H
