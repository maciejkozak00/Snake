#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow &win) : win(win)
{
    hs.resize(10);
    hsText.resize(10);


    startPressed = false;

    font.loadFromFile("Arial.ttf");
    buttonText.setFont(font);
    text.setFont(font);

    easyText.setFont(font);
    mediumText.setFont(font);
    hardText.setFont(font);
    settingsText.setFont(font);

    dif = HARD;
    goToSettings = false;
}

void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(playButton, states);
    target.draw(buttonText, states);
    target.draw(text, states);
    target.draw(easyButton, states);
    target.draw(mediumButton, states);
    target.draw(hardButton, states);
    target.draw(easyText, states);
    target.draw(mediumText, states);
    target.draw(hardText, states);
    target.draw(settingsButton, states);
    target.draw(settingsText, states);
    for(int i = 0; i < 10; i++)
    {
        target.draw(hsText.at(i), states);
    }
}

void MainMenu::setMMScreen()
{
    text.setCharacterSize(100);
    text.setPosition(win.getSize().x / 2 - 200, win .getSize().y / 8);
    text.setOutlineColor(sf::Color::Black);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(5);
    text.setString("SNAKEv");


    playButton.setSize(sf::Vector2f(200, 100));
    playButton.setFillColor(sf::Color::Blue);
    playButton.setPosition(win.getSize().x / 2 - 150, win.getSize().y / 2 - 50);
    playButton.setOutlineThickness(5);
    playButton.setOutlineColor(sf::Color::Black);

    buttonText.setCharacterSize(50);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setOutlineColor(sf::Color::Black);
    buttonText.setOutlineColor(sf::Color::Black);
    buttonText.setOutlineThickness(3);
    buttonText.setString("PLAY");
    buttonText.setPosition(win.getSize().x / 2 - 130, win.getSize().y / 2 - 40);

    easyButton.setSize(sf::Vector2f(100, 50));
    easyButton.setFillColor(sf::Color::White);
    easyButton.setPosition(win.getSize().x / 2 - 50, win.getSize().y / 4 + 300);
    easyButton.setOutlineThickness(5);
    easyText.setPosition(sf::Vector2f(win.getSize().x / 2 - 50 + 10, win.getSize().y / 4 + 300 + 10));
    easyText.setString("EASY");
    easyText.setOutlineThickness(1);
    easyText.setOutlineColor(sf::Color::Black);
    if(dif == EASY)
    {
        easyButton.setOutlineColor(sf::Color::Magenta);
        mediumButton.setOutlineColor(sf::Color::White);
        hardButton.setOutlineColor(sf::Color::White);
    }

    mediumButton.setSize(sf::Vector2f(100, 50));
    mediumButton.setFillColor(sf::Color::White);
    mediumButton.setPosition(win.getSize().x / 2 - 50, win.getSize().y / 4 + 370);
    mediumButton.setOutlineThickness(5);
    mediumText.setPosition(sf::Vector2f(win.getSize().x / 2 - 50, win.getSize().y / 4 + 370 + 10));
    mediumText.setString("MEDIUM");
    mediumText.setOutlineThickness(1);
    mediumText.setOutlineColor(sf::Color::Black);
    mediumText.setCharacterSize(25);
    if(dif == MEDIUM)
    {
        easyButton.setOutlineColor(sf::Color::White);
        mediumButton.setOutlineColor(sf::Color::Magenta);
        hardButton.setOutlineColor(sf::Color::White);
    }

    hardButton.setSize(sf::Vector2f(100, 50));
    hardButton.setFillColor(sf::Color::White);
    hardButton.setPosition(win.getSize().x / 2 - 50, win.getSize().y / 4 + 440);
    hardButton.setOutlineThickness(5);
    hardText.setPosition(sf::Vector2f(win.getSize().x / 2 - 50 + 10, win.getSize().y / 4 + 440 + 10));
    hardText.setString("HARD");
    hardText.setOutlineThickness(1);
    hardText.setOutlineColor(sf::Color::Black);
    if(dif == HARD)
    {
        easyButton.setOutlineColor(sf::Color::White);
        mediumButton.setOutlineColor(sf::Color::White);
        hardButton.setOutlineColor(sf::Color::Magenta);
    }

    //settings
    settingsButton.setSize(sf::Vector2f(100, 50));
    settingsButton.setFillColor(sf::Color::White);
    settingsButton.setPosition(sf::Vector2f(win.getSize().x / 2 - 200, win.getSize().y / 4 + 300 + 10));
    settingsButton.setOutlineThickness(5);
    settingsText.setPosition(sf::Vector2f(win.getSize().x / 2 - 200 + 10, win.getSize().y / 4 + 300 + 10 + 10));
    settingsText.setString("Settings");
    settingsText.setOutlineThickness(1);
    settingsText.setOutlineColor(sf::Color::Black);
    settingsText.setCharacterSize(20);

}


void MainMenu::buttonPressed(sf::Event &event)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            if(event.mouseButton.x >= win.getSize().x / 2 - 50 && event.mouseButton.x <= win.getSize().x / 2 - 50 + 200
            && event.mouseButton.y >= win.getSize().y / 4 + 300 && event.mouseButton.y <= win.getSize().y / 4 + 300 + 50)
            {
                dif = EASY;
            }
            if(event.mouseButton.x >= win.getSize().x / 2 - 50 && event.mouseButton.x <= win.getSize().x / 2 - 50 + 100
               && event.mouseButton.y >= win.getSize().y / 4 + 370 && event.mouseButton.y <= win.getSize().y / 4 + 370 + 50)
            {
                dif = MEDIUM;
            }
            if(event.mouseButton.x >= win.getSize().x / 2 - 50 && event.mouseButton.x <= win.getSize().x / 2 - 50 + 100
               && event.mouseButton.y >= win.getSize().y / 4 + 440 && event.mouseButton.y <= win.getSize().y / 4 + 440 + 50)
            {
                dif = HARD;
            }
            if(event.mouseButton.x >= settingsButton.getPosition().x && event.mouseButton.x <= settingsButton.getPosition().x + settingsButton.getSize().x
            && event.mouseButton.y >= settingsButton.getPosition().y && event.mouseButton.y <= settingsButton.getPosition().y + settingsButton.getSize().y)
            {
                goToSettings = true;
            }
        }
    }
}

bool MainMenu::getStartPressed()
{
    return startPressed;
}

void MainMenu::setStartPressed()
{
    startPressed = false;
}

void MainMenu::setDifficulty(sf::Event &event)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            if(event.mouseButton.x >= win.getSize().x / 2 - 150 && event.mouseButton.x <= win.getSize().x / 2 - 150 + 200
               && event.mouseButton.y >= win.getSize().y / 2 - 50 && event.mouseButton.y <= win.getSize().y / 2 - 50 + 100)
            {
                startPressed = true;
            }
        }
    }
}

Difficulty MainMenu::getDif() {
    return dif;
}

bool MainMenu::getGoToSettings() {
    return goToSettings;
}

void MainMenu::setGoToSettings() {
    goToSettings = false;

}

void MainMenu::getHS()
{
    std::string bab;
    file.open("HighScore.dat", std::ios::in);
    if(!file.good())
    {
        abort();
    }
    for(int i = 0; i < 10; i++)
    {
        std::getline(file, bab);
        hs.at(i) = atoi(bab.c_str());
    }
    file.close();
}

void MainMenu::setHS()
{
    getHS();
    for(int i = 0; i < 10; i++)
    {
        hsText.at(i).setFont(font);
        hsText.at(i).setCharacterSize(20);
        hsText.at(i).setPosition(sf::Vector2f(win.getSize().x * 0.8, 20 * i));
        hsText.at(i).setFillColor(sf::Color::White);
        hsText.at(i).setOutlineColor(sf::Color::Black);
        hsText.at(i).setOutlineThickness(1);
        hsText.at(i).setString(std::to_string(hs.at(i)));
    }
}
