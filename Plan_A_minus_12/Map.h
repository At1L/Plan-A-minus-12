#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "MapData.h"
#include "MapLoader.h"
class Map
{
private:
	sf::Texture tileSheetTexture;

	Tile* tiles;  

	MapLoader mapLoader;
	MapData md;

	int totalTitles;

	int totalTitlesX;
	int totalTitlesY;


	int mapWidth;
	int mapHeight;

	sf::Sprite* mapSprites;
public:
	Map();
	~Map();
	void Initialize();
	void Load(std::string filename);
	void Update(double deltaTime); 
	void Draw(sf::RenderWindow& window);
};

