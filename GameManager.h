//
// Created by macie on 05.05.2020.
//

#ifndef SNAKE_AN_PN13_253316_GAMEMANAGER_H
#define SNAKE_AN_PN13_253316_GAMEMANAGER_H

#include <SFML/Audio.hpp>

#include "SnakeCharacter.h"
#include "SnakeMap.h"
#include "SnakeControlls.h"
#include "GameOver.h"
#include "MainMenu.h"
#include "Settings.h"
#include "HighScore.h"

#include "SFML/Graphics.hpp"

class GameManager{
    SnakeMap &map;
    SnakeCharacter &snake;
    SnakeControlls &ctrl;
    GameOver &go;
    MainMenu &menu;
    Settings &settings;
    HighScore &hs;

    sf::Clock clock;

    sf::Music music;

    sf::SoundBuffer buffer;
    sf::Sound dmg;
public:
    GameManager(SnakeMap &map, SnakeCharacter &snake, SnakeControlls &ctrl, GameOver &go, MainMenu &menu, Settings &settings, HighScore &hs);
    bool isGameLost();
    bool isGameWon();

    void foodAte();
    void moveSnake(SnakeCharacter &snake, sf::Clock &clock) const;

    void setGameScene(int &scene);

    void playMusic();
    void setVolume();

};


#endif //SNAKE_AN_PN13_253316_GAMEMANAGER_H
