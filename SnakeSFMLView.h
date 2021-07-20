#ifndef SNAKE_AN_PN13_253316_SNAKESFMLVIEW_H
#define SNAKE_AN_PN13_253316_SNAKESFMLVIEW_H

#include "SFML/Graphics.hpp"
#include "SnakeCharacter.h"
#include "SnakeMap.h"
#include <vector>
#include <string.h>
#include "Settings.h"


class SnakeSFMLView : public sf::Drawable
        {
    SnakeMap &map;
    SnakeCharacter &snake;
    Settings &settings;
    float blockSizeX, blockSizeY;


    ////walls
    std::vector<sf::RectangleShape> walls;
    sf::Texture wallTexture;

    ////snakeHead
    sf::RectangleShape snakeHead;
    sf::Texture snakeHeadTexture;

    ////grass
    sf::RectangleShape grass;
    sf::Texture grassTexture;

    ////snakebody
    std::vector<sf::RectangleShape> snakeBody;
    sf::Texture snakeBodyTexture;

    ////food
    sf::RectangleShape food;
    sf::Texture foodTexturePear;
    sf::Texture foodTexturePeach;
    sf::Texture foodTexturePaprika;

    ////licznik fps
    sf::Text fpsCounter;
    sf::Font font;
    sf::Clock clock;

    ////points
    sf::Text points;
    sf::Text score;



public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    SnakeSFMLView(SnakeMap &map, SnakeCharacter &snake, Settings &settings);
    void setWalls(sf::RenderWindow &win);
    void setBlocksSize(sf::RenderWindow &win);
    void setSnakeHead(sf::RenderWindow &win);
    void setSnakeBody(sf::RenderWindow &win);
    void setFood();
    void setFoodTexture();
    void countFPS();
    void setPoints();
    void viewManager(sf::RenderWindow &win);

};


#endif //SNAKE_AN_PN13_253316_SNAKESFMLVIEW_H
