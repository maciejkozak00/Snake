#include "SnakeMap.h"

SnakeMap::SnakeMap(SnakeCharacter &snake) : snake(snake)
{
    mapSizeX = 30;
    mapSizeY = 30;

    snake_eating = false;

    food.resize(1);

    srand(time(NULL));

    setFood();

    buffer.loadFromFile("eating.wav");
    eating.setBuffer(buffer);

}

int SnakeMap::getMapSizeX() const
{
    return mapSizeX;
}

int SnakeMap::getMapSizeY() const
{
    return mapSizeY;
}

int SnakeMap::getFoodX() const
{
    return food.at(0).foodX;
}

int SnakeMap::getFoodY() const
{
    return food.at(0).foodY;
}

bool SnakeMap::isWall(int x, int y)  const
{
    return x == 0 || x == getMapSizeY() - 1 || y == 0 || y == getMapSizeY() - 1;
}

bool SnakeMap::isSnake(int x, int y) const
{
    for(int i = 1; i < snake.getSnakeLength(); i++)
    {
        if(x == snake.getSnakeTailX(i) && y == snake.getSnakeTailY(i))
        {
            return true;
        }
    }
    return false;
}

bool SnakeMap::isSnakeHead(int x, int y) const
{
    return x == snake.getSnakeX() && y == snake.getSnakeY();
}



void SnakeMap::debugDisplay()
{
    for(int i = 0; i < getMapSizeY(); i++)
    {
        for(int j = 0; j < getMapSizeX(); j++)
        {
            if(isWall(j, i))
            {
                std::cout << "[W]";
            }
            else if(isSnake(j, i) || isSnakeHead(j, i))
            {
                std::cout << "[S]";
            }
            else if(isFood(j, i))
            {
                std::cout << "[F]";
            }
            else
            {
                std::cout << "[G]";
            }
        }
        std::cout << std::endl;
    }
}


bool SnakeMap::isFood(int x, int y) const
{
    return x == food.at(0).foodX && y == food.at(0).foodY;
}

void SnakeMap::setFood()
{
    int a = rand() % getMapSizeX();
    int b = rand() % getMapSizeY();

    if(!isWall(a, b) && !isSnake(a, b) && !isSnakeHead(a, b))
    {
        food.at(0).foodX = a;
        food.at(0).foodY = b;
    }
    else
    {
        setFood();
    }
}

void SnakeMap::foodCollected()
{
    if(isSnake(getFoodX(), getFoodY()))
    {
        snake_eating = true;
    }
    foodAte();

}

void::SnakeMap::foodAte()
{
    if(!isSnake(getFoodX(), getFoodY()) && snake_eating)
    {
        snake.extendSnake(getFoodX(), getFoodY());
        snake_eating = false;
        setFood();
    }
}

bool SnakeMap::hitWall() const
{
    return isWall(snake.getSnakeX(), snake.getSnakeY());
}

bool SnakeMap::snakeSuicide() const
{
    return isSnake(snake.getSnakeX(), snake.getSnakeY());
}

int SnakeMap::getWallCount() const
{
    int licznik = 0;
    for(int i = 0; i < getMapSizeX(); i++)
    {
        for(int j = 0; j < getMapSizeY(); j++)
        {
            if(isWall(i, j))
            {
                licznik++;
            }
        }
    }
    return licznik;
}

int SnakeMap::getPoints() {
    return snake.getScore();
}
