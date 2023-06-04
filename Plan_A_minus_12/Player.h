#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include "Bullet.h"
class Player
{
private:
	sf::Texture texture;

	std::vector<Bullet> bullets; 

	sf::Text healthText;

	sf::Font font;

	float maxFireRate;
	float fireRateTimer;
	float playerSpeed;
	int hp;

	sf::RectangleShape boundingRectangle;
	sf::Vector2i size; 

public:
	sf::Sprite sprite; 

public:
	Player();
	~Player();
	void Initialize(); 
	void Load();
	void Update(double deltaTime, Skeleton& skeleton, sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);
};

