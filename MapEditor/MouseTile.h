#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"

class MouseTile
{
private:
	const Grid& m_grid;
	sf::Texture m_tileSheet;
	sf::Sprite m_tile;

	sf::Vector2f m_tilePosition;
	sf::Vector2i m_tileGridPosition;
	sf::Vector2f m_offset;
	sf::Vector2i m_tileSize;
	sf::Vector2f m_tileScale;

	bool m_isMouseOnGrid;
public:
	MouseTile(const Grid& grid, const sf::Vector2i& tileSize,
		const sf::Vector2f& tileScale,
		const sf::Vector2f& offset);
	~MouseTile();

	void Initialize();
	void Load();
	void Update(double deltaTime,const sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);

	bool IsMouseClickedOnTile(sf::Vector2f& tilePosition,
		sf::Vector2i& gridPosition, const sf::Vector2f& mousePosition) const;

	//inline const sf::Texture& GetTileSheetTexture() const{
	//	return m_tileSheet;
	//}
	inline const sf::Sprite& GetSprite() const {
		return m_tile;
	}
};

