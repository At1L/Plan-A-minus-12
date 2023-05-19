#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
}

void Skeleton::Load()
{
    if (texture.loadFromFile("Assets/Skeleton/Textures/skeletonSpritesheet.png"))
    {
        std::cout << "Skeleton Loaded\n";
        sprite.setTexture(texture);

        int XIndex = 1;
        int YIndex = 2;

        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        sprite.setPosition(sf::Vector2f(100, 100));
    }
}

void Skeleton::Update()
{
}

void Skeleton::Draw(sf::RenderWindow& window) 
{
    window.draw(sprite); 
}
