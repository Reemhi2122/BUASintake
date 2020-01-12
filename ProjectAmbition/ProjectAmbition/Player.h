#pragma once
#include <iostream>
#include <typeinfo>
#include "Creature.h"


class Player : public Creature
{
public:
	Player();
	~Player();
	void Collision(Object* m_CollisionObject);
	void Collision(sf::Sprite* m_CollisionObject);
	void BlockCollision();
	void Input(sf::Event a_Event);
	void Rotate(sf::RenderWindow* a_RenderWindow);
	void ResetCollision();

private:

};