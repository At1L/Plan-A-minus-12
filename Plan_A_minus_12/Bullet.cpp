#include "Bullet.h"
#include "Math.h"
Bullet::Bullet() : speed(0)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize(const sf::Vector2f& position, const sf::Vector2f& target, float BulletSpeed)
{
	speed = BulletSpeed; 
	rectangleShape.setSize(sf::Vector2f(50, 25));
	rectangleShape.setPosition(position);
	direction = Math::NormalaizeVector(target - position); 
}

void Bullet::Load()
{
}

void Bullet::Update(double deltaTime)
{
	rectangleShape.setPosition(rectangleShape.getPosition() + direction * speed * (float)deltaTime); 
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(rectangleShape);
}
