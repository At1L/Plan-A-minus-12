#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include "Bullet.h"
#include "Rasengun.h"
class Player
{
private:
	//player
	sf::Texture texture;

	std::vector<Bullet*> bullets; 
	std::vector<Rasengun*> rasenguns;

	sf::Text healthText;
	sf::Font font;
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;
	float playerSpeed;
	int hp;

	//shuriken
	float bulletMaxFireRate;
	float bulletFireRateTimer;

	//rasengun
	float rasengunMaxFireRate;
	float rasengunFireRateTimer; 

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
	void Update(double deltaTime, sf::Vector2f& mousePosition);
	void UpdateSkeleton(double deltaTime, Skeleton*& skeleton);
	void Draw(sf::RenderWindow& window);
};

