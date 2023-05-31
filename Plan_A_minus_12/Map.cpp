#include "Map.h"
#include <iostream>
Map::Map() : totalTitlesX(0), totalTitlesY(0),
             mapWidth(3), mapHeight(2),
             totalTitles(0), tiles(nullptr)
{
} 

Map::~Map()
{
    delete[] mapSprites;
    delete[] tiles;
}

void Map::Initialize()
{
}

void Map::Load(std::string filename)
{
    mapLoader.Load(filename, md);
    mapSprites = new sf::Sprite[md.dataLength];

    if (tileSheetTexture.loadFromFile(md.tilesheet)) {
        totalTitlesX = tileSheetTexture.getSize().x / md.tileWidth;
        totalTitlesY = tileSheetTexture.getSize().y / md.tileHeight;
        std::cout << "Map loaded\n";
        totalTitles = totalTitlesX * totalTitlesY;
        tiles = new Tile[totalTitles];

        for (int y = 0; y < totalTitlesY; y++) 
        {
            for (int x = 0; x < totalTitlesX; x++) 
            {
                int i = x + y * totalTitlesX;

                tiles[i].id = i;     
                tiles[i].position = sf::Vector2i(x * md.tileWidth, y * md.tileHeight);  
            }
        }



        for (size_t y = 0; y < mapHeight; ++y)
        {
            for (size_t x = 0; x < mapWidth; x++)
            {
                int i = x + y * mapWidth;
                
                int index = md.data[i];

                mapSprites[i].setTexture(tileSheetTexture); 

                mapSprites[i].setTextureRect(sf::IntRect(
                    tiles[index].position.x,
                    tiles[index].position.y,
                    md.tileWidth,
                    md.tileHeight));

                mapSprites[i].setScale(sf::Vector2f(5, 5));
                mapSprites[i].setPosition(sf::Vector2f(
                    x * md.tileWidth * mapSprites[i].getScale().x,
                    y * md.tileHeight * mapSprites[i].getScale().y));
            }
        }
    }
    else {
        std::cout << "Map load ERROR\n";
    }
}

void Map::Update(double deltaTime) 
{
}

void Map::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < md.dataLength; i++) {
        window.draw(mapSprites[i]);
    }
}
