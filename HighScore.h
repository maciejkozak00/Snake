//
// Created by macie on 10.05.2020.
//

#ifndef SNAKE_AN_PN13_253316_HIGHSCORE_H
#define SNAKE_AN_PN13_253316_HIGHSCORE_H

#include "SFML/Graphics.hpp"
#include <fstream>
#include "SnakeCharacter.h"
#include "vector"
#include "cstdlib"
#include "GameOver.h"

class HighScore {
    std::fstream highscore;
    SnakeCharacter &snake;
    GameOver &go;
    std::vector<int> score;
    bool edited;

public:
    HighScore(SnakeCharacter &snake, GameOver &go);
    void manageFile();
    void setEdited();

};


#endif //SNAKE_AN_PN13_253316_HIGHSCORE_H
