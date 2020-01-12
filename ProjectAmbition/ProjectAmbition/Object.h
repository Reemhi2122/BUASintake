#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Object
{
public:
	Object();
	Object(std::string a_FileLocation, sf::Vector2f a_Scale, sf::Vector2f a_SetPosition, bool a_Interactable);
	~Object();
	bool IsInteractable();
	sf::Sprite& GetSprite();


protected:
	sf::Sprite m_Sprite;
	sf::Texture m_Texture;
	bool m_Interactable;
};

