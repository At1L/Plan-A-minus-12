#include "MouseTile.h"

MouseTile::MouseTile(const sf::Vector2i& tileSize,
	const sf::Vector2f& tileScale, 
	const sf::Vector2f& offset)
	: m_tileSize(tileSize), m_tileScale(tileScale), m_offset(offset), m_isMouseOnGrid(false)
{
}

MouseTile::~MouseTile()
{
}

void MouseTile::Initialize()
{
}

void MouseTile::Load()
{
	m_tileSheet.loadFromFile("assets/world/prison/tilesheet.png");
	m_tile.setTexture(m_tileSheet);
	m_tile.setTextureRect(sf::IntRect(11 * m_tileSize.x, 0, m_tileSize.x, m_tileSize.y));
	m_tile.setScale(m_tileScale);
}

void MouseTile::Update(double deltaTime, sf::Vector2f mousePosition)
{
	int gridIndexX = (mousePosition.x - m_offset.x)/(m_tileSize.x * m_tile.getScale().x);
	int x = gridIndexX * (m_tileSize.x * m_tileScale.x) + m_offset.x;

	int gridIndexY = (mousePosition.y - m_offset.y) / (m_tileSize.y * m_tileScale.y);
	int y = gridIndexY * m_tileSize.y * m_tileScale.y + m_offset.y;


	m_tile.setPosition(sf::Vector2f(x, y));

}

void MouseTile::Draw(sf::RenderWindow& window)
{
	window.draw(m_tile);
}

bool MouseTile::IsMouseClickedOnGrid(sf::Vector2f& tilePosition, const sf::Vector2f& mousePosition)
{
	bool itsOnGrid = true;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && itsOnGrid)
	{
		int gridIndexX = (mousePosition.x - m_offset.x) / (m_tileSize.x * m_tile.getScale().x);
		int x = gridIndexX * (m_tileSize.x * m_tileScale.x) + m_offset.x;

		int gridIndexY = (mousePosition.y - m_offset.y) / (m_tileSize.y * m_tileScale.y);
		int y = gridIndexY * m_tileSize.y * m_tileScale.y + m_offset.y;
		tilePosition = sf::Vector2f(x,y);
		return true;
	}
	return false;
}
