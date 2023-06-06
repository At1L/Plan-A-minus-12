#include <SFML/Graphics.hpp>  
#include <iostream>
#include "Player.h"
#include "Skeleton.h"
#include "FrameRate.h"
#include "Map.h"
#include "MapLoader.h"
#include <vector>
#include <random>
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

    std::vector<Skeleton> skeletons;
    Player player;
    for (int i = 0; i < 4; i++)
    {
        Skeleton skeleton(100, 0.1f);
        skeletons.push_back(skeleton);
    }
    MapLoader mapLoader;
    //--------------INITIALIZE---------------
    frameRate.Initialize();
    map.Initialize();
    for (int i = 0; i < 4; i++)
    {
        
        skeletons[i].Initialize();
    }
    player.Initialize();  
    //--------------INITIALIZE---------------


    //--------------LOAD---------------
    frameRate.Load();
    map.Load("assets/maps/level1.rmap");
   
    srand(time(0));
    for (int i = 0; i < skeletons.size(); i++)
    {
        float X = (rand() * rand() + rand() + 200) % 1820, Y = (rand() * rand() + rand() + 200) % 980;
        std::cout << X << ' ' << Y << '\n';
        while (abs(X - 100) < 100 && abs(Y - 100) < 100)
        {
            X = (rand() * rand() + rand() + 200) % 1820, Y = (rand() * rand() + rand() + 200) % 980;
        }
        skeletons[i].Load(X, Y);
    }
   
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
        player.Update(deltaTime, mousePosition);
        for (int i = 0; i < skeletons.size(); i++)
        {
            skeletons[i].Update(player.sprite.getPosition(), deltaTime);
            player.UpdateSkeleton(deltaTime, skeletons[i]);
        }
        
        
        //--------------Update---------------
        
        //--------------Draw---------------
        window.clear(sf::Color::Black);  
        map.Draw(window);
        for (int i = 0; i < skeletons.size(); i++)
        {
            skeletons[i].Draw(window);
        }
        player.Draw(window);
        frameRate.Draw(window); 
        window.display();  
        //--------------Draw---------------
        
    }
    return 0;
}