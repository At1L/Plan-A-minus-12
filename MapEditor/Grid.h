#pragma once
#include <SFML/Graphics.hpp>

class Grid
{
private:
	sf::RectangleShape* m_hLine;
	sf::RectangleShape* m_vLine;

	sf::Vector2f m_position;
	sf::Vector2i m_scale;
	sf::Vector2i m_totalCells;
	sf::Vector2i m_cellSize;

	sf::Vector2i m_totalLines;

	int m_LineThickness;

	sf::Color m_color; 
public:
	Grid(const sf::Vector2f& position,
		const sf::Vector2f& cellSize,
		const sf::Vector2i& totalCells,
		const sf::Vector2i& scale,
		const sf::Color& color,
		int LineThickness);

	~Grid();

	void Initialize();
	void Load();
	void Update(double deltaTime);
	void Draw(sf::RenderWindow& window); 

	inline const sf::Vector2i& GetTotalCells() const {
		return m_totalCells;
	}
};

