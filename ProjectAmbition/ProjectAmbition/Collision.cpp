#include "Collision.h"

Collision::Collision(){}
Collision::~Collision(){}

void Collision::CheckCollision(Player& a_Player, std::list<Object*> a_Objects)
{
	std::list<Object*>::iterator it;
	for (it = a_Objects.begin(); it != a_Objects.end(); ++it)
	{
		if (a_Player.GetSprite().getGlobalBounds().intersects((*it)->GetSprite().getGlobalBounds())) {
			a_Player.Collision((*it));
		}
	}
}
