#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include "Bullet.h"
#include "Rasengun.h"
#include "Amaterasu.h"
class Player
{
private:
	//player
	sf::Texture texture;

	std::vector<Bullet*> bullets; 
	std::vector<Rasengun*> rasenguns;
	std::vector<Amaterasu*> amaterasus;
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

	//amaterasu
	float amaterasuMaxFireRate;
	float amaterasuFireRateTimer;

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

