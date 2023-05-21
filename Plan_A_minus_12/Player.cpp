#include "Player.h"
#include <iostream>
#include "Math.h"

Player::Player() :
    playerSpeed(0.5f),
    maxFireRate(250.0f), fireRateTimer(0)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(24, 32);  
}

void Player::Load()
{
    if (texture.loadFromFile("Assets/Player/Textures/FumikoSpritesheet.png")) {
        std::cout << "Hero Loaded\n"; 
        sprite.setTexture(texture); 

        int XIndex = 4;
        int YIndex = 2;

        sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
        sprite.setPosition(sf::Vector2f(100, 100));

        sprite.scale(sf::Vector2f(2, 2));
        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else
        std::cout << "ERROR\n";
}

void Player::Update(float deltaTime, Skeleton& skeleton, sf::Vector2f& mousePosition)
{
    //Moving up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        //take current position of image
        sf::Vector2f position = sprite.getPosition();
        //add pixels to coordinate to move it
        sprite.setPosition(position + sf::Vector2f(0, -1) * playerSpeed * deltaTime);
    }
    //Moving down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(0, 1) * playerSpeed * deltaTime);
    }
    //Moving left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(-1, 0) * playerSpeed * deltaTime);
    }
    //Moving right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(1, 0) * playerSpeed * deltaTime);
    }
    //--------------------------BULLET--------------------------
    fireRateTimer += deltaTime;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate)
    {
        bullets.push_back(Bullet());
        int i = bullets.size() - 1;
        bullets[i].Initialize(sprite.getPosition(), mousePosition, 0.5f);
        fireRateTimer = 0;
    }
    for (size_t i = 0; i < bullets.size(); ++i)
    {
        //sf::Vector2f bulletDirection = mousePosition - bullets[i].getPosition(); 
        //bulletDirection = Math::NormalaizeVector(bulletDirection);
        //bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);
        
        bullets[i].Update(deltaTime);
        if (skeleton.health > 0) {
            if (Math::DidRectCollide(bullets[i].GetGlobalBounds(), skeleton.sprite.getGlobalBounds())) 
            {
                skeleton.ChangeHealth(-10); 
                bullets.erase(bullets.begin() + i); 
                std::cout << "Collision" << "\n";
            }
        }
    }

    boundingRectangle.setPosition(sprite.getPosition());
    //--------------------------BULLET--------------------------
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite); 
    window.draw(boundingRectangle);
    for (size_t i = 0; i < bullets.size(); ++i) 
        bullets[i].Draw(window); 
}