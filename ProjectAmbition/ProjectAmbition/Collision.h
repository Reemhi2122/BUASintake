#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <List>
#include "Object.h"
#include "Player.h"
#include "Tile.h"

class Collision
{
public:
	Collision();
	~Collision();
	void CheckCollision(Player& a_Player, std::list<Object*> a_Objects);
	void CheckCollision(Player& a_Player, std::list<Tile*> a_Objects);
	void CheckCollision(Player& a_Player, Tile* a_Objects);

private:
	 
};

