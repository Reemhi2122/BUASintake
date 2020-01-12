#include "Object.h"

Object::Object()
{

}

Object::Object(std::string a_FileLocation, sf::Vector2f a_Scale , sf::Vector2f a_Position, bool a_Interactable){
	m_Sprite = sf::Sprite();
	m_Texture.loadFromFile(a_FileLocation);
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setScale(a_Scale);
	m_Sprite.setPosition(a_Position);
	m_Sprite.setOrigin(32, 32);

	m_Interactable = a_Interactable;
}

Object::~Object(){}

bool Object::IsInteractable()
{
	return m_Interactable;
}

sf::Sprite& Object::GetSprite()
{
	return m_Sprite;
}
