//
// Created by macie on 01.05.2020.
//

#ifndef SNAKE_AN_PN13_253316_SNAKEMAP_H
#define SNAKE_AN_PN13_253316_SNAKEMAP_H

#include "SnakeCharacter.h"
#include <time.h>
#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>

struct Food
{
    int foodX, foodY;
};

class SnakeMap
{
    int mapSizeX, mapSizeY;
    SnakeCharacter &snake;
    std::vector<Food> food;
    bool snake_eating;

    sf::SoundBuffer buffer;
    sf::Sound eating;


public:
    explicit SnakeMap(SnakeCharacter &snake);

    int getMapSizeX() const;
    int getMapSizeY() const;
    int getFoodX() const;
    int getFoodY() const;
    int getWallCount() const;

    bool isWall(int x, int y) const;
    bool isFood(int x, int y) const;
    bool isSnake(int x, int y) const;
    bool isSnakeHead(int x, int y) const;
    bool hitWall() const;
    bool snakeSuicide() const;

    void foodCollected();
    void foodAte();
    void setFood();
    void debugDisplay();

    int getPoints();
};


#endif //SNAKE_AN_PN13_253316_SNAKEMAP_H
