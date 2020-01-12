#include "Renderer.h"

Renderer::Renderer() {
	m_Window.create(sf::VideoMode(800, 600), "Ambition Project");
	m_Event = sf::Event();
}

Renderer::~Renderer() {}

bool Renderer::CheckEvent(Player* a_Player)
{
	while (m_Window.pollEvent(m_Event))
	{
		if (m_Event.type == sf::Event::Closed)
			return true;

		if (m_Event.type == sf::Event::KeyPressed) {
			a_Player->Input(m_Event);
		}
	}
	return false;
}

void Renderer::Clear(){
	m_Window.clear();
}

void Renderer::Clear(sf::Color a_Color)
{
	m_Window.clear(a_Color);
}

void Renderer::ResetView(Player* a_Player)
{
	sf::View view;
	//view.setSize(800, 600);
	view.setSize(2400, 1800);
	view.setCenter(a_Player->GetSprite().getPosition());
	m_Window.setView(view);
}

void Renderer::Draw(sf::Sprite& a_Sprite)
{
	m_Window.draw(a_Sprite);
}

void Renderer::Draw(Tile* a_Tile)
{
	m_Window.draw(a_Tile->GetSprite());
}

void Renderer::Draw(Tile* a_SpriteArray, int a_ArrayCount)
{
	int size = a_ArrayCount * a_ArrayCount;
	for (int i = 0; i < size; i++)
	{
		m_Window.draw(a_SpriteArray[i].GetSprite());
	}
}

void Renderer::Draw(std::list<sf::Sprite>* a_Sprite)
{
	std::list<sf::Sprite>::iterator it;
	for (it = a_Sprite->begin(); it != a_Sprite->end(); ++it)
	{
		sf::Sprite sprite = (*it);
		m_Window.draw(sprite);
	}
}

void Renderer::Display()
{
	m_Window.display();
}

void Renderer::Close()
{
	m_Window.close();
}

sf::RenderWindow* Renderer::GetWindow()
{
	return &m_Window;
}

sf::Event Renderer::GetEvent()
{
	return m_Event;
}
