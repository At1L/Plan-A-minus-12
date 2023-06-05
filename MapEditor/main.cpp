#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "MouseTile.h"
#include "Map.h"
int main()
{
    //--------------INITIALIZE---------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    //create window                      width, height, window header
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Map editor", sf::Style::Default, settings);
    window.setFramerateLimit(120);
    //--------------INITIALIZE---------------
    Grid grid(
        sf::Vector2f(100, 50),           //position
        sf::Vector2f(16, 16),            //cells size
        sf::Vector2i(10, 5),             // (horizontal cells, vertical cells)
        sf::Vector2i(10, 10),            //Scale
        sf::Color(255, 255, 255, 255),   //Color (red, green, blue, brightness)
        2); 

    MouseTile mouseTile(sf::Vector2i(16, 16),   //cells size
        sf::Vector2f(10, 10),                   //scale
        sf::Vector2f(100, 50));                 //grid position
    Map map(mouseTile);
    //--------------INITIALIZE---------------
    grid.Initialize();
    mouseTile.Initialize();
    map.Initialize();
    //--------------INITIALIZE---------------


    //--------------LOAD---------------
    grid.Load();
    mouseTile.Load();
    //--------------LOAD---------------
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time deltaTimer = clock.restart();
        double deltaTime = deltaTimer.asMicroseconds() / 1000.0;


        //--------------Update---------------
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

        grid.Update(deltaTime);
        mouseTile.Update(deltaTime, mousePosition);
        map.Update(deltaTime, mousePosition);
        //--------------Draw---------------
        window.clear(sf::Color::Black);
        grid.Draw(window);
        mouseTile.Draw(window);
        map.Draw(window);
        window.display();
        //--------------Draw---------------

    }
    return 0;
}