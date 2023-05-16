#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
sf::Vector2f NormalaizeVector(sf::Vector2f vector) 
{
    float m = std::sqrt(vector.x* vector.x + vector.y * vector.y);
    sf::Vector2f normalaizedVector;
    normalaizedVector.x = vector.x / m;
    normalaizedVector.y = vector.y / m;
    return normalaizedVector;
}
int main()
{
    //--------------INITIALIZE---------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    //create window                      width, height, window header
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Guns of Bullshit", sf::Style::Default, settings);
    //--------------INITIALIZE---------------
    sf::RectangleShape bullet(sf::Vector2f(50, 25));
    float bulletSpeed = 1.0f;
    //--------------LOAD---------------
    //--------------Skeleton---------------
    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite;
    if (skeletonTexture.loadFromFile("Assets/Skeleton/Textures/skeletonSpritesheet.png"))
    {
        std::cout << "Skeleton Loaded\n";
        skeletonSprite.setTexture(skeletonTexture);

        int XIndex = 1;
        int YIndex = 2;

        skeletonSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        skeletonSprite.setPosition(sf::Vector2f(100, 100));
    }

    //--------------Player---------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    if (playerTexture.loadFromFile("Assets/Player/Textures/FumikoSpritesheet.png")) {
        std::cout << "Hero Loaded\n";
        playerSprite.setTexture(playerTexture);

        int XIndex = 4;
        int YIndex = 2;

        playerSprite.setTextureRect(sf::IntRect(XIndex * 24, YIndex * 32, 24, 32));
        playerSprite.scale(sf::Vector2f(2, 2));
        playerSprite.setPosition(sf::Vector2f(1650, 800));
    }
    else
        std::cout << "ERROR\n";
    //--------------LOAD---------------
    bullet.setPosition(playerSprite.getPosition());
    //--------------- Calculate direction of the bullet ---------------
    sf::Vector2f bulletDirection = skeletonSprite.getPosition() - bullet.getPosition();
    bulletDirection = NormalaizeVector(bulletDirection);
    //--------------- Calculate direction of the bullet ---------------
    //main window loop
    while(window.isOpen()) 
    {
        sf::Event event; 
        //--------------Update---------------
        while (window.pollEvent(event)) 
        {
             
            if (event.type == sf::Event::Closed)  
                window.close(); 
        }

        bullet.setPosition(bullet.getPosition() + bulletDirection*bulletSpeed);


        //Moving up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { 
            //take current position of image
            sf::Vector2f position = playerSprite.getPosition();
            //add pixels to coordinate to move it
            playerSprite.setPosition(position + sf::Vector2f(0, -1));  
        }
        //Moving down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {  
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, 1)); 
        }
        //Moving left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {   
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));  
        }
        //Moving right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(1, 0));
        }
        //--------------Update---------------
        
        //--------------Draw---------------
        window.clear(sf::Color::Black);  
        window.draw(playerSprite);
        window.draw(skeletonSprite);
        window.draw(bullet);
        window.display();  
        //--------------Draw---------------
    }
    return 0;
}