#include "Button.h"

namespace GUI {
	Button::Button(const sf::Vector2f& position,
		const sf::Vector2f& scale): m_position(position), m_scale(scale)
	{
	}
	Button::~Button()
	{
	}
	void Button::Initialize()
	{
		
	}
	void Button::Load()
	{
		m_texture.loadFromFile("assets/gui/button.png");
		m_sprite = sf::Sprite(m_texture);
		m_sprite.setPosition(m_position);
		m_sprite.setScale(m_scale);
	}
	void Button::Update(double deltaTime, const sf::Vector2f& mousePosition)
	{
	}
	void Button::Draw(sf::RenderWindow& window)
	{
		window.draw(m_sprite);
	}
}
