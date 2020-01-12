#include "Creature.h"

Creature::Creature()
{

}

Creature::Creature(std::string a_FileLocation, sf::Vector2f a_Scale, sf::Vector2f a_Position, bool a_Interactable) :
	Object(a_FileLocation, a_Scale, a_Position, a_Interactable)
{

}

Creature::~Creature()
{

}