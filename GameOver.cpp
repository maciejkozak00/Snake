//
// Created by macie on 07.05.2020.
//

#include "GameOver.h"

GameOver::GameOver(sf::RenderWindow &win, SnakeMap &map) : map(map), win(win)
{
    gameOverButton = false;

    background.setPosition(0, 0);
    background.setSize(sf::Vector2f(4500, 2300));
    background.setFillColor(sf::Color(30, 25, 40));


    font.loadFromFile("Arial.ttf");

    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(4);
    text.setOutlineColor(sf::Color::Black);
    text.setPosition(300, 100);
    text.setCharacterSize(100);

    buttonText.setFont(font);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setOutlineColor(sf::Color::Black);
    buttonText.setString("Main Menu");
    buttonText.setPosition(350, 370);

   button.setPosition(270, 350);
   button.setOutlineThickness(5);
   button.setOutlineColor(sf::Color::Black);
   button.setFillColor(sf::Color::White);
   button.setSize(sf::Vector2f(300, 100));

}

void GameOver::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(background, states);
    target.draw(button, states);
    target.draw(text, states);
    target.draw(buttonText, states);
}

void GameOver::setGOScreen()
{
//    if(gameWon())
//    {
//        button.setFillColor(sf::Color::Green);
//        text.setString("WIN");
//    }
    if(gameLost())
    {
        button.setFillColor(sf::Color::Red);
        text.setString("LOSS");
    }
}


void GameOver::buttonPressed(sf::Event &event)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            if(event.mouseButton.x >= 270 && event.mouseButton.x <= 570 && event.mouseButton.y >=350 && event.mouseButton.y <= 450)
            {
                gameOverButton = true;
            }
        }
    }
}

bool GameOver::getGOButton()
{
    return gameOverButton;
}

void GameOver::setGOButton()
{
    gameOverButton = false;
}

bool GameOver::gameWon()
{
    return map.getPoints() >= 15;
}

bool GameOver::gameLost() {
    return map.snakeSuicide() || map.hitWall();
}


