//
// Created by macie on 07.05.2020.
//

#ifndef SNAKE_AN_PN13_253316_MAINMENU_H
#define SNAKE_AN_PN13_253316_MAINMENU_H

#include "SFML/Graphics.hpp"
#include "fstream"

enum Difficulty {EASY, MEDIUM, HARD};

class MainMenu :public sf::Drawable
{
    bool startPressed;
    sf::RenderWindow &win;

    sf::RectangleShape playButton;
    sf::Text buttonText;
    sf::Font font;
    sf::Text text;

    //easy
    sf::RectangleShape easyButton;
    sf::Text easyText;

    //medium
    sf::RectangleShape mediumButton;
    sf::Text mediumText;

    //hard
    sf::RectangleShape hardButton;
    sf::Text hardText;

    //settings
    sf::RectangleShape settingsButton;
    sf::Text settingsText;
    bool goToSettings;

    std::vector<int> hs;
    std::fstream file;

    Difficulty dif;

    std::vector<sf::Text> hsText;



public:
    explicit MainMenu(sf::RenderWindow &win);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void setMMScreen();
    void buttonPressed(sf::Event &event);

    bool getStartPressed();
    void setStartPressed();

    bool getGoToSettings();
    void setGoToSettings();

    void setDifficulty(sf::Event &event);

    void getHS();
    void setHS();

    Difficulty getDif();
};


#endif //SNAKE_AN_PN13_253316_MAINMENU_H
