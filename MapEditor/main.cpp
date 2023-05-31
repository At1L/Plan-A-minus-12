#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //--------------INITIALIZE---------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    //create window                      width, height, window header
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Map editor", sf::Style::Default, settings);
    window.setFramerateLimit(120);
    //--------------INITIALIZE---------------

    //--------------INITIALIZE---------------
    //--------------INITIALIZE---------------


    //--------------LOAD---------------

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

      
        //--------------Update---------------

        //--------------Draw---------------
        window.clear(sf::Color::Black);
        window.display();
        //--------------Draw---------------

    }
    return 0;
}