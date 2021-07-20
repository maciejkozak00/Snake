//
// Created by macie on 10.05.2020.
//

#include "HighScore.h"
#include <iostream>

HighScore::HighScore(SnakeCharacter &snake, GameOver &go) : snake(snake), go(go)
{
    edited = false;
    std::string bab;
    score.resize(10);

    if(!highscore.good())
    {
        exit(0);
    }
    highscore.open("HighScore.dat", std::ios::in);
    for(int i = 0; i < 10; i++)
    {
        std::getline(highscore, bab);
        score.at(i) = atoi(bab.c_str());
    }
    highscore.close();
}

void HighScore::manageFile()
{
    if(!edited && !go.getGOButton())
    {
        highscore.open("HighScore.dat", std::ios::out);
        score.push_back(snake.getScore());
        std::sort(score.begin(), score.end());
        for(int i = score.size() - 1, j = 0; j < 10; i--, j++)
        {
            highscore << score.at(i) << std::endl;
        }
        highscore.close();
        edited = true;
    }
}

void HighScore::setEdited()
{
    edited = false;
}

