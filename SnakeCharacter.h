//
// Created by macie on 01.05.2020.
//

#ifndef SNAKE_AN_PN13_253316_SNAKECHARACTER_H
#define SNAKE_AN_PN13_253316_SNAKECHARACTER_H

#include <vector>
#include <cstdlib>

enum lastMove {UP, DOWN, RIGHT, LEFT};


struct Snake{
    int snakeX, snakeY;

};


class SnakeCharacter{
    std::vector<Snake> snake;
    lastMove move;

public:
    explicit SnakeCharacter();

    int getSnakeX();
    int getSnakeY();
    int getSnakeLength();
    int getSnakeTailX(int segment);
    int getSnakeTailY(int segment);
    int getScore();

    void startSnake();

    void moveSnakeLeft();
    void moveSnakeRight();
    void moveSnakeDown();
    void moveSnakeUp();
    void snakeFollowHead();

    void extendSnake(int foodX, int foodY);

    lastMove getLastMove();

};


#endif //SNAKE_AN_PN13_253316_SNAKECHARACTER_H
