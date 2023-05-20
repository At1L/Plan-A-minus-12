#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Skeleton.h"
int main()
{
    //--------------INITIALIZE---------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    //create window                      width, height, window header
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dungeon master: Deep Dark Fantasy", sf::Style::Default, settings);
    window.setFramerateLimit(240);
    //--------------INITIALIZE---------------
    //--------------LOAD---------------
    //--------------Skeleton---------------
    Skeleton skeleton;
    skeleton.Initialize();
    skeleton.Load();

    //--------------Player---------------
    Player player;
    player.Initialize();
    player.Load();
    //--------------LOAD---------------
    sf::Clock clock;
    while(window.isOpen()) 
    {
        sf::Time deltaTimer = clock.restart();
        float deltaTime = deltaTimer.asMilliseconds();
        std::cout << deltaTime << "\n";
        sf::Event event; 
        //--------------Update---------------
        while (window.pollEvent(event)) 
        {
             
            if (event.type == sf::Event::Closed)  
                window.close(); 
        }

        skeleton.Update(deltaTime);
        player.Update(deltaTime, skeleton);
        //--------------Update---------------
        
        //--------------Draw---------------
        window.clear(sf::Color::Black);  
        skeleton.Draw(window);
        player.Draw(window);
        window.display();  
        //--------------Draw---------------
        
    }
    return 0;
}