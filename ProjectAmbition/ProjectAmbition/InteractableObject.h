#pragma once
#include "Object.h"
#include "Player.h"

class InteractableObject : public Object
{
public:
	InteractableObject();
	InteractableObject(std::string a_FileLocation, sf::Vector2f a_Scale, sf::Vector2f a_Position, bool a_Interactable);
	~InteractableObject();

	
	virtual void Interact(Player* a_Player);

private:
};

