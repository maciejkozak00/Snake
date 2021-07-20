//
// Created by macie on 03.05.2020.
//

#include "SnakeSFMLView.h"


SnakeSFMLView::SnakeSFMLView(SnakeMap &map, SnakeCharacter &snake, Settings &settings) : map(map), snake(snake), settings(settings)
{
    walls.resize(map.getWallCount());
    wallTexture.loadFromFile("walltexture.png");

    snakeHeadTexture.loadFromFile("snakehead.png");
    snakeHead.setTexture(&snakeHeadTexture);

    snakeBodyTexture.loadFromFile("snakebody.png");

    foodTexturePaprika.loadFromFile("paprika.png");
    foodTexturePear.loadFromFile("grucha.png");
    foodTexturePeach.loadFromFile("brzoskwinia.png");

    fpsCounter.setFillColor(sf::Color::White);
    fpsCounter.setOutlineThickness(1);
    fpsCounter.setPosition(sf::Vector2f(0, 0));

    font.loadFromFile("Arial.ttf");
    fpsCounter.setFont(font);

    points.setFont(font);
    points.setFillColor(sf::Color::White);
    points.setOutlineThickness(2);
    points.setPosition(100, 0);
    score.setFont(font);
    score.setFillColor(sf::Color::White);
    score.setOutlineThickness(2);
    score.setPosition(200, 0);


}

void SnakeSFMLView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(grass, states);
    target.draw(food, states);
    for(int i = 0; i < map.getWallCount(); i++)
    {
        target.draw(walls.at(i), states);
    }
    target.draw(snakeHead, states);
    for(int i = 0; i < snake.getSnakeLength(); i++)
    {
        target.draw(snakeBody.at(i), states);
    }
    if(settings.getShowFPS())
        target.draw(fpsCounter, states);
    target.draw(points);
    target.draw(score);
}

void SnakeSFMLView::setWalls(sf::RenderWindow &win)
{
    int counter = 0;
    for(int i = 0; i < map.getMapSizeX(); i++)
    {
        for(int j = 0; j < map.getMapSizeY(); j++)
        {
            if(map.isWall(i, j))
            {
                walls.at(counter).setPosition(float(i) * blockSizeX, float(j) * blockSizeY);
                walls.at(counter).setTexture(&wallTexture);
                walls.at(counter).setSize(sf::Vector2f(blockSizeX, blockSizeY));
                counter++;
            }
        }
    }
    ////wiem że nie powinienem tego robić ale pozwala to na optymalizacje (chyba)////
    snakeHead.setSize(sf::Vector2f(blockSizeX, blockSizeY));

    food.setSize(sf::Vector2f(blockSizeX, blockSizeY));


    grass.setSize(sf::Vector2f(win.getSize().x, win.getSize().y));
    grass.setPosition(sf::Vector2f(0, 0));
    grass.setFillColor(sf::Color::Green);
}

void SnakeSFMLView::setBlocksSize(sf::RenderWindow &win)
{
    blockSizeX = win.getSize().x / float(map.getMapSizeX());
    blockSizeY = win.getSize().y / float(map.getMapSizeY());
}

void SnakeSFMLView::setSnakeHead(sf::RenderWindow &win)
{
    for(int i = 0; i < map.getMapSizeX(); i++)
    {
        for(int j = 0; j < map.getMapSizeY(); j++)
        {
            if(map.isSnakeHead(i, j))
            {
                snakeHead.setPosition(float(i) * blockSizeX, float(j) * blockSizeY);
            }
        }
    }
}

void SnakeSFMLView::setSnakeBody(sf::RenderWindow &win)
{
    int counter = 0;
    snakeBody.resize(snake.getSnakeLength());
    for(int i = 0; i < map.getMapSizeX(); i++)
    {
        for(int j = 0; j < map.getMapSizeY(); j++)
        {
            if(map.isSnake(i, j))
            {
                snakeBody.at(counter).setPosition(float(i) * blockSizeX, float(j) * blockSizeY);
                snakeBody.at(counter).setSize(sf::Vector2f(blockSizeX, blockSizeY));
                snakeBody.at(counter).setTexture(&snakeBodyTexture);
                counter++;
            }
        }
    }
}

void SnakeSFMLView::setFood()
{
    for(int i = 0; i < map.getMapSizeX(); i++)
    {
        for(int j = 0; j < map.getMapSizeY(); j++)
        {
            if(map.isFood(i, j))
            {
                food.setPosition(float(i) * blockSizeX, float(j) * blockSizeY);
                setFoodTexture();
            }
        }
    }
}

void SnakeSFMLView::setFoodTexture()
{
    srand(snake.getScore());
    int a = rand() % 3;
    switch(a)
    {
        case 0: //brzoswkinia
        food.setTexture(&foodTexturePeach);
        break;
        case 1: // papryka
        food.setTexture(&foodTexturePaprika);
        break;
        case 2: //grucha
        food.setTexture(&foodTexturePear);
        break;
    }
}

void SnakeSFMLView::countFPS() //wzorowane na https://en.sfml-dev.org/forums/index.php?topic=7018.0
{
    if(settings.getShowFPS())
    {
        double oneFrameTime = clock.restart().asSeconds();
        double FPS = 1.f / oneFrameTime;
        std::string fps = std::to_string(FPS);
        if(FPS < 10)
        {
            fps.resize(3);
        }
        else if(FPS >= 10 && FPS < 100)
        {
            fps.resize(4);
        }
        else if(FPS >= 100 && FPS < 1000)
        {
            fps.resize(5);
        }
        else
        {
            fps.resize(6);
        }


        fpsCounter.setString(fps);
    }
}

void SnakeSFMLView::setPoints()
{
    std::string punkty = std::to_string(snake.getScore());
    points.setString("Score: ");
    score.setString(punkty);
}

void SnakeSFMLView::viewManager(sf::RenderWindow &win)
{
    setSnakeHead(win);
    setSnakeBody(win);
    setFood();
    countFPS();
    setPoints();
}
