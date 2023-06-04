#pragma once
#include <SFML/Graphics.hpp>
class Skeleton
{
private:
	sf::Texture texture;
	sf::Vector2f direction;
	sf::Text healthText;
	sf::Font font;

public:
	sf::Sprite sprite;
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

	int health;

public:
	Skeleton();
	~Skeleton();

	void ChangeHealth(int hp);
	void Initialize();
	void Load();
	void Update(const sf::Vector2f& position, const sf::Vector2f& target, double deltaTime);
	void Draw(sf::RenderWindow& window);

};

