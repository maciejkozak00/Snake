//
// Created by macie on 05.05.2020.
//

#include "GameManager.h"

GameManager::GameManager(SnakeMap &map, SnakeCharacter &snake, SnakeControlls &ctrl, GameOver &go, MainMenu &menu, Settings &settings, HighScore &hs) : map(map),
snake(snake), ctrl(ctrl), go(go), menu(menu), settings(settings), hs(hs)
{
    music.openFromFile("terraria.wav");
    music.play();
    music.setLoop(true);

    buffer.loadFromFile("dmg.wav");
    dmg.setBuffer(buffer);
}

bool GameManager::isGameLost()
{
    return map.snakeSuicide() || map.hitWall();
}

void GameManager::foodAte()
{
    map.foodCollected();
}

void GameManager::moveSnake(SnakeCharacter &snake, sf::Clock &clock) const
{
    sf::Time time = clock.getElapsedTime();
    double a = time.asMilliseconds();
    if((menu.getDif() == HARD && a >= 100) || (menu.getDif() == MEDIUM && a >= 300) || (menu.getDif() == EASY && a >= 500))
    {
        if(snake.getLastMove() == DOWN)
        {
            snake.moveSnakeDown();
            clock.restart();
        }
        else if(snake.getLastMove() == UP)
        {
            snake.moveSnakeUp();
            clock.restart();
        }
        else if(snake.getLastMove() == LEFT)
        {
            snake.moveSnakeLeft();
            clock.restart();
        }
        else if(snake.getLastMove() == RIGHT)
        {
            snake.moveSnakeRight();
            clock.restart();
        }
    }
}

void GameManager::setGameScene(int &scene)
{
    if(isGameLost() && scene == 1)
    {
        scene = 2;
        dmg.play();
    }
    else if(go.getGOButton() && scene == 2)
    {
        scene = 0;
        go.setGOButton();
        hs.setEdited();
    }
    else if(menu.getStartPressed() && scene == 0)
    {
        scene = 1;
        menu.setStartPressed();
        snake.startSnake();
    }
    else if(menu.getGoToSettings() && scene == 0)
    {
        scene = 3;
        menu.setGoToSettings();
    }
    else if(settings.getBackToMenu())
    {
        scene = 0;
        settings.setBackToMenu();
    }

}

bool GameManager::isGameWon()
{
    return snake.getScore() >= 15;
}

void GameManager::playMusic()
{
}

void GameManager::setVolume() {
    music.setVolume(settings.getVol());

}




