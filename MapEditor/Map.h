#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"
#define MAP_SIZE 50
class Map
{
private:
	MouseTile m_mouseTile;
	sf::Sprite* m_mapSprites;
	
public:
	Map(const MouseTile& mouseTile);
	~Map();

	void Initialize();
	void Load();
	void Update(double deltaTime);
	void Draw(sf::RenderWindow& window);
private:
	void OnGridcCick(int i);
};

