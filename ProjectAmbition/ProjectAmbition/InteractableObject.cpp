#include "InteractableObject.h"

InteractableObject::InteractableObject() 
{

}

InteractableObject::InteractableObject(std::string a_FileLocation, sf::Vector2f a_Scale, sf::Vector2f a_Position, bool a_Interactable) :
	Object(a_FileLocation, a_Scale, a_Position, a_Interactable)
{}

InteractableObject::~InteractableObject()
{
}

void InteractableObject::Interact(Player* a_Player)
{
	std::cout << "Interacted with object: " << typeid(this).name() << std::endl;
}
