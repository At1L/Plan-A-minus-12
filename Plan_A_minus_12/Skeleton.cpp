#include "Skeleton.h"
#include "Math.h"
#include <iostream>

Skeleton::Skeleton() : health(100)
{
}

Skeleton::~Skeleton()
{
}

void Skeleton::ChangeHealth(int hp)
{
    health += hp;
    healthText.setString(std::to_string(health)); 
}

void Skeleton::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}

void Skeleton::Load()
{
    if (font.loadFromFile("Assets/Fonts/arial.ttf")) {
        std::cout << "Font loaded\n";
        healthText.setFont(font);
        healthText.setString(std::to_string(health)); 
    } 
    else {
        std::cout << "Font load ERROR\n";
    }
    if (texture.loadFromFile("Assets/Skeleton/Textures/skeletonSpritesheet.png"))
    {
        std::cout << "Skeleton Loaded\n";
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(800, 400));

        int XIndex = 1;
        int YIndex = 2;

        sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
        sprite.scale(sf::Vector2f(1, 1));

        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
}

void Skeleton::Update(const sf::Vector2f& position, const sf::Vector2f& target, double deltaTime)
{
    if (health > 0) {
        direction = Math::NormalaizeVector(target - position);
        boundingRectangle.setPosition(sprite.getPosition() + direction * (float)0.1 * (float)deltaTime);
        sprite.setPosition(sprite.getPosition() + direction * (float)0.1 * (float)deltaTime);
        healthText.setPosition(sprite.getPosition() + direction * (float)0.1 * (float)deltaTime);
    }
}

void Skeleton::Draw(sf::RenderWindow& window) 
{
    if (health > 0) {
        window.draw(sprite); 
        window.draw(boundingRectangle);
        window.draw(healthText);

    }
    
}
