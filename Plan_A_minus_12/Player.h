#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include "Bullet.h"
class Player
{
private:
	//player
	sf::Texture texture;

	std::vector<Bullet*> bullets; 

	sf::Text healthText;
	sf::Font font;
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;
	float playerSpeed;
	int hp;

	//shuriken
	float bulletMaxFireRate;
	float bulletFireRateTimer;
	float playerSpeed;
	int hp;


	//skeleton
	float skeletonMaxDamadgeRate;
	float skeletonDamageRate;

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

