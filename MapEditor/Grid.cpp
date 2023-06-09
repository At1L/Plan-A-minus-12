#include "Grid.h"

Grid::Grid(
			const sf::Vector2f& position, 
			const sf::Vector2f& cellSize,
			const sf::Vector2i& totalCells,
			const sf::Vector2i& scale,
			const sf::Color& color,
			int LineThickness) :  
			m_scale(scale), m_totalCells(totalCells), m_cellSize(cellSize),
			m_LineThickness(LineThickness), m_position(position), m_color(color)
{
	m_totalLines = totalCells + sf::Vector2i(1, 1);
	m_hLine = new sf::RectangleShape[m_totalLines.y];
	m_vLine = new sf::RectangleShape[m_totalLines.x];
}

Grid::~Grid()
{
	delete[] m_hLine;
	delete[] m_vLine;
}

void Grid::Initialize()
{ 
	m_size = sf::Vector2f(m_totalCells.x * m_cellSize.x * m_scale.x,
		m_totalCells.y * m_cellSize.y * m_scale.y);


	for (size_t i = 0; i < m_totalLines.y; ++i)
	{
		m_hLine[i].setSize(sf::Vector2f(m_size.x + m_LineThickness, m_LineThickness));
		m_hLine[i].setPosition(m_position + sf::Vector2f(0, i * m_cellSize.y * m_scale.x));
		m_hLine[i].setFillColor(m_color);
	}

	for (size_t i = 0; i < m_totalLines.x; ++i)
	{
		m_vLine[i].setSize(sf::Vector2f(m_LineThickness, m_size.y));
		m_vLine[i].setPosition(m_position + sf::Vector2f(i * m_cellSize.x * m_scale.y, 0));
		m_vLine[i].setFillColor(m_color);
	}
	/*hLine.setSize(sf::Vector2f(horizontalLineLength, LineThickness));
	hLine.setPosition(position); 

	vLine.setSize(sf::Vector2f(LineThickness, verticalLineLength));
	vLine.setPosition(position); */
}

void Grid::Load()
{
}

void Grid::Update(double deltaTime)
{
}

void Grid::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < m_totalLines.y; ++i)
	{
		window.draw(m_hLine[i]);
	}
	for (size_t i = 0; i < m_totalLines.x; ++i)
	{
		window.draw(m_vLine[i]);
	}
	/*window.draw(hLine);
	window.draw(vLine);*/
}
