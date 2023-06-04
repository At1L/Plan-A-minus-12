#include <SFML/Graphics.hpp>  
#include <iostream>
#include "Player.h"
#include "Skeleton.h"
#include "FrameRate.h"
#include "Map.h"
#include "MapLoader.h"
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
    Map map;
    Skeleton skeleton; 
    Player player; 

    MapLoader mapLoader;
    //--------------INITIALIZE---------------
    frameRate.Initialize();
    map.Initialize();
    skeleton.Initialize();
    player.Initialize();  
    //--------------INITIALIZE---------------


    //--------------LOAD---------------
    frameRate.Load();
    map.Load("assets/maps/level1.rmap");
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
        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window)); 

        frameRate.Update(deltaTime);
        map.Update(deltaTime);
        skeleton.Update(skeleton.sprite.getPosition(), player.sprite.getPosition(), deltaTime);
        player.Update(deltaTime, skeleton, mousePosition);
        if (skeleton.health <= 0)
        {
            skeleton.Load();
        }
        //--------------Update---------------
        
        //--------------Draw---------------
        window.clear(sf::Color::Black);  
        map.Draw(window);
        skeleton.Draw(window);
        player.Draw(window);
        frameRate.Draw(window); 
        window.display();  
        //--------------Draw---------------
        
    }
    return 0;
}