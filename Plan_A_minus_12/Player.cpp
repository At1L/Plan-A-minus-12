#include "Player.h"
#include <iostream>
#include "Math.h"

void Player::Initialize()
{
}

void Player::Load()
{
    if (texture.loadFromFile("Assets/Player/Textures/FumikoSpritesheet.png")) {
        std::cout << "Hero Loaded\n"; 
        sprite.setTexture(texture); 

        int XIndex = 4;
        int YIndex = 2;

        sprite.setTextureRect(sf::IntRect(XIndex * 24, YIndex * 32, 24, 32));
        sprite.scale(sf::Vector2f(2, 2));
        sprite.setPosition(sf::Vector2f(1650, 800));
    }
    else
        std::cout << "ERROR\n";
}

void Player::Update(Skeleton& skeleton) 
{
    //Moving up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        //take current position of image
        sf::Vector2f position = sprite.getPosition();
        //add pixels to coordinate to move it
        sprite.setPosition(position + sf::Vector2f(0, -1));
    }
    //Moving down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(0, 1));
    }
    //Moving left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(-1, 0));
    }
    //Moving right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(1, 0));
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));

        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());
    }
    for (size_t i = 0; i < bullets.size(); ++i)
    {
        sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = Math::NormalaizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite); 
    for (size_t i = 0; i < bullets.size(); ++i) 
        window.draw(bullets[i]); 
}