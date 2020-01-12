#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Tile.h"
#include "Player.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	bool CheckEvent(Player* a_Player);

	void Clear();
	void Clear(sf::Color a_Color);

	void ResetView(Player* a_Player);

	void Draw(sf::Sprite& a_Sprite);
	void Draw(Tile* a_Tile);
	void Draw(Tile* a_Sprite, int a_ArrayCount);
	void Draw(std::list<sf::Sprite>* a_Sprite);
	
	void Display();
	void Close();

	sf::RenderWindow* GetWindow();
	sf::Event GetEvent();

private:
	sf::RenderWindow m_Window;
	sf::Event m_Event;
};

