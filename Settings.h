
#ifndef SNAKE_AN_PN13_253316_SETTINGS_H
#define SNAKE_AN_PN13_253316_SETTINGS_H

#include "SFML/Graphics.hpp"
#include <vector>



class Settings : public sf::Drawable
        {
    sf::Font font;
    sf::RenderWindow &win;

    sf::RectangleShape fpsButton;
    sf::Text fpsText;

    sf::RectangleShape backToMenuButton;
    sf::Text btmbT;
    bool backToMenu;

    bool fpsPressed;

    sf::RectangleShape main;

    sf::RectangleShape volUp;
    sf::RectangleShape volDown;
    sf::Text currentVolume;
    int vol;



public:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    Settings(sf::RenderWindow &win);
    void setScreen();
    void isButtonPressed(sf::Event &event);

    bool getShowFPS();

    bool getBackToMenu();
    void setBackToMenu();

    int getVol();

};


#endif //SNAKE_AN_PN13_253316_SETTINGS_H
