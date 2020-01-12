#pragma once
#include "Object.h"
#include "Structs.cpp"

class Creature : public Object
{
public:
	Creature();
	Creature(std::string a_FileLocation, sf::Vector2f a_Scale, sf::Vector2f a_Position, bool a_Interactable);
	~Creature();

protected:
	CollisionData m_CollisionData;
};

