#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include "Bullet.h"
#include "Boss_1.h"
#include "Boss_2.h"

#include "Rasengun.h"
#include "Amaterasu.h"
#include "Fireball.h"
class Player
{
private:
	//player
	sf::Texture texture;

	std::vector<Bullet*> bullets; 
	std::vector<Rasengun*> rasenguns;
	std::vector<Amaterasu*> amaterasus;
	std::vector<Fireball*> fireball;
	sf::Text healthText;
	sf::Font font;
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;
	float playerSpeed;
	int hp;

	//fireball

	//shuriken
	float bulletMaxFireRate;
	float bulletFireRateTimer;

	//rasengun
	float rasengunMaxFireRate;
	float rasengunFireRateTimer; 

	//amaterasu
	float amaterasuMaxFireRate;
	float amaterasuFireRateTimer;

	//fireball
	float fireballMaxFireRate;
	float fireballFireRateTimer; 

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
	void Update_Boss_1(double deltaTime, Boss_1& boss_1);
	void Update_Boss_2(double deltaTime, Boss_2& boss_2);
	void Draw(sf::RenderWindow& window);
};

