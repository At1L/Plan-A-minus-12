#include "Player.h"
#include <iostream>
#include "Math.h"

Player::Player() :
    bulletSpeed(0.5f), playerSpeed(0.5f)
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
        sprite.setPosition(sf::Vector2f(1650, 800));

        sprite.scale(sf::Vector2f(2, 2));
        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else
        std::cout << "ERROR\n";
}

void Player::Update(float deltaTime, Skeleton& skeleton)
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
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);
    }

    boundingRectangle.setPosition(sprite.getPosition());

    if (Math::DidRectCollide(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds()))
    {
        std::cout << "Collision" << "\n";
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite); 
    window.draw(boundingRectangle);
    for (size_t i = 0; i < bullets.size(); ++i) 
        window.draw(bullets[i]); 
}