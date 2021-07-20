//
// Created by macie on 01.05.2020.
//

#include "SnakeCharacter.h"

SnakeCharacter::SnakeCharacter()
{
    move = DOWN;

}

int SnakeCharacter::getSnakeX() {
    return snake.at(0).snakeX;
}

int SnakeCharacter::getSnakeY()
{
    return snake.at(0).snakeY;
}

int SnakeCharacter::getSnakeTailX(int segment)
{
    return snake.at(segment).snakeX;
}

int SnakeCharacter::getSnakeTailY(int segment)
{
    return snake.at(segment).snakeY;
}

int SnakeCharacter::getSnakeLength() {
    return snake.size();
}


void SnakeCharacter::moveSnakeLeft()
{
    if(getLastMove() != RIGHT)
    {
    snakeFollowHead();
    snake.at(0).snakeX--;
    move = LEFT;
    }
}

void SnakeCharacter::moveSnakeRight()
{
    if(getLastMove() != LEFT)
    {
    snakeFollowHead();
    snake.at(0).snakeX++;
    move = RIGHT;
    }
}

void SnakeCharacter::moveSnakeDown()
{
    if(getLastMove() != UP)
    {
    snakeFollowHead();
    snake.at(0).snakeY++;
    move = DOWN;
    }
}

void SnakeCharacter::moveSnakeUp()
{
    if(getLastMove() != DOWN)
    {
    snakeFollowHead();
    snake.at(0).snakeY--;
    move = UP;
    }
}

lastMove SnakeCharacter::getLastMove()
{
    return move;
}

void SnakeCharacter::snakeFollowHead()
{
    for(int i = getSnakeLength() - 1; i > 0; i--)
    {
        snake.at(i).snakeX = snake.at(i - 1).snakeX;
        snake.at(i).snakeY = snake.at(i - 1).snakeY;
    }

}

void SnakeCharacter::extendSnake(int foodX, int foodY)
{
    snake.resize(snake.size() + 1);
    snake.at(getSnakeLength() - 1).snakeX = foodX;
    snake.at(getSnakeLength() - 1).snakeY = foodY;
}

int SnakeCharacter::getScore()
{
    return getSnakeLength() - 3;
}

void SnakeCharacter::startSnake()
{
    snake.resize(3);
    for(int i = 0, j = 4; i < getSnakeLength(); i++, j--)
    {
        snake.at(i).snakeX = j;
        snake.at(i).snakeY = 5;
    }
    move = DOWN;
}
