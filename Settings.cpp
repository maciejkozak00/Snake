//
// Created by macie on 11.05.2020.
//

#include <iostream>
#include "Settings.h"


Settings::Settings(sf::RenderWindow &win) : win(win)
{
    font.loadFromFile("Arial.ttf");
    btmbT.setFont(font);
    fpsText.setFont(font);
    fpsPressed = false;
    backToMenu = false;

    volUp.setFillColor(sf::Color::White);
    volUp.setSize(sf::Vector2f(20, 20));
    volUp.setPosition(sf::Vector2f(win.getSize().x * 0.8, win.getSize().y * 0.4 + 75));

    volDown.setFillColor(sf::Color::White);
    volDown.setSize(sf::Vector2f(20, 20));
    volDown.setPosition(sf::Vector2f(win.getSize().x * 0.8 + 100, win.getSize().y * 0.4 + 75));

    vol = 10;

    currentVolume.setFont(font);
    currentVolume.setPosition(sf::Vector2f(win.getSize().x * 0.2, win.getSize().y * 0.4 + 75));
    currentVolume.setFillColor(sf::Color::White);
    currentVolume.setOutlineThickness(2);
    currentVolume.setOutlineColor(sf::Color::Black);

}

void Settings::draw(sf::RenderTarget &target, sf::RenderStates states)  const
{
    target.draw(main, states);
    target.draw(fpsButton, states);
    target.draw(fpsText, states);
    target.draw(backToMenuButton, states);
    target.draw(btmbT, states);
    target.draw(volUp, states);
    target.draw(volDown, states);
    target.draw(currentVolume, states);
}

void Settings::setScreen()
{
    fpsButton.setPosition(sf::Vector2f(win.getSize().x * 0.8, win.getSize().y * 0.4));
    fpsButton.setSize(sf::Vector2f(50, 50));
    fpsButton.setFillColor(sf::Color::White);
    fpsButton.setOutlineColor(sf::Color::Black);
    fpsButton.setOutlineThickness(2);
    fpsText.setPosition(sf::Vector2f(win.getSize().x * 0.2, win.getSize().y * 0.4));
    fpsText.setFillColor(sf::Color::White);
    fpsText.setOutlineThickness(1);
    fpsText.setOutlineColor(sf::Color::Black);
    fpsText.setString("Show FPS");
    if(getShowFPS())
    {
        fpsButton.setFillColor(sf::Color::Green);
    }
    else if(!getShowFPS())
    {
        fpsButton.setFillColor(sf::Color::Red);
    }

    main.setPosition(sf::Vector2f(win.getSize().x * 0.3, win.getSize().y * 0.1));
    main.setSize(sf::Vector2f(win.getSize().x * 0.3, win.getSize().y * 0.2));
    main.setFillColor(sf::Color::White);

    backToMenuButton.setPosition(sf::Vector2f(0, win.getSize().y - backToMenuButton.getSize().y));
    backToMenuButton.setSize(sf::Vector2f(50, 50));
    backToMenuButton.setFillColor(sf::Color::White);
    backToMenuButton.setOutlineColor(sf::Color::Black);
    backToMenuButton.setOutlineThickness(2);
    btmbT.setPosition(sf::Vector2f(10, win.getSize().y - backToMenuButton.getSize().y - 10));
    btmbT.setFillColor(sf::Color::White);
    btmbT.setOutlineThickness(1);
    btmbT.setOutlineColor(sf::Color::Black);
    btmbT.setString("<");
    btmbT.setCharacterSize(50);
    currentVolume.setString(std::to_string(vol));
}


void Settings::isButtonPressed(sf::Event  &event)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            if(event.mouseButton.x >= fpsButton.getPosition().x && event.mouseButton.x <= fpsButton.getPosition().x + fpsButton.getSize().x
            && event.mouseButton.y  >= fpsButton.getPosition().y && event.mouseButton.y <= fpsButton.getPosition().y + fpsButton.getSize().y)
            {
                if(!fpsPressed)
                     fpsPressed = true;
                else if(fpsPressed)
                    fpsPressed = false;
            }
            if(event.mouseButton.x >= backToMenuButton.getPosition().x && event.mouseButton.x <= backToMenuButton.getPosition().x + backToMenuButton.getSize().x
               && event.mouseButton.y  >= backToMenuButton.getPosition().y && event.mouseButton.y <= backToMenuButton.getPosition().y + backToMenuButton.getSize().y)
            {
                if(!backToMenu)
                    backToMenu = true;
                else if(backToMenu)
                    backToMenu = false;
            }
            if(event.mouseButton.x >= volUp.getPosition().x && event.mouseButton.x <= volUp.getPosition().x + volUp.getSize().x
               && event.mouseButton.y  >= volUp.getPosition().y && event.mouseButton.y <= volUp.getPosition().y + volUp.getSize().y && vol < 100)
            {
                vol +=10;
            }
            if(event.mouseButton.x >= volDown.getPosition().x && event.mouseButton.x <= volDown.getPosition().x + volDown.getSize().x
               && event.mouseButton.y  >= volDown.getPosition().y && event.mouseButton.y <= volDown.getPosition().y + volDown.getSize().y
               && vol >= 10)
            {
                vol -= 10;
            }
        }
    }
}

bool Settings::getShowFPS()
{
    return fpsPressed;
}

bool Settings::getBackToMenu() {
    return backToMenu;
}

void Settings::setBackToMenu()
{
    backToMenu = false;
}

int Settings::getVol() {
    return vol;
}

