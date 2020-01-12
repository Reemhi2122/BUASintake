#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Renderer.h"
#include "Collision.h"
#include "Player.h"
#include "RecordPlayer.h"
#include "Record.h"
#include "Map.h"

class GameManager
{
public:
	GameManager();
	~GameManager();
	void Start();
	void Update();
	void CheckCollision();
	void Draw();

private:
	Renderer m_Renderer;
	Collision m_Collision;
	Map m_Map;

	Player m_Player;
	RecordPlayer m_RecordPlayer;
	Record m_Record;

	std::list<Object*> m_CollidableObjects;
};

