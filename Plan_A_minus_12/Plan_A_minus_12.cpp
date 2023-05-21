#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Skeleton.h"
#include "FrameRate.h"
int main()
{
    //--------------INITIALIZE---------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    //create window                      width, height, window header
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dungeon master: Deep Dark Fantasy", sf::Style::Default, settings);
    window.setFramerateLimit(120);
    //--------------INITIALIZE---------------
    FrameRate frameRate;
    Skeleton skeleton; 
    Player player; 
    //--------------INITIALIZE---------------
    frameRate.Initialize();
    skeleton.Initialize();
    player.Initialize();  
    //--------------INITIALIZE---------------


    //--------------LOAD---------------
    frameRate.Load();
    skeleton.Load();
    player.Load();
    //--------------LOAD---------------
    sf::Clock clock;
    while(window.isOpen()) 
    {
        sf::Time deltaTimer = clock.restart();
        double deltaTime = deltaTimer.asMicroseconds()/1000.0;
        

        //--------------Update---------------
        sf::Event event; 
        while (window.pollEvent(event)) 
        {
             
            if (event.type == sf::Event::Closed)  
                window.close(); 
        }

        frameRate.Update(deltaTime);
        skeleton.Update(deltaTime);
        player.Update(deltaTime, skeleton);
        //--------------Update---------------
        
        //--------------Draw---------------
        window.clear(sf::Color::Black);  
        skeleton.Draw(window);
        player.Draw(window);
        frameRate.Draw(window); 
        window.display();  
        //--------------Draw---------------
        
    }
    return 0;
}