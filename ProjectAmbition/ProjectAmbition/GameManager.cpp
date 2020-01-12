#include "GameManager.h"

GameManager::GameManager() {}

GameManager::~GameManager(){}

void GameManager::Start()
{
	do {
		m_Renderer.ResetView(&m_Player);
		Update();
	} while (!m_Renderer.CheckEvent(&m_Player));

	m_Renderer.Close();
}

void GameManager::Update() {
	CheckCollision();
	m_Player.Rotate(m_Renderer.GetWindow());
	Draw();
}

void GameManager::CheckCollision() {
	m_CollidableObjects.clear();
	m_CollidableObjects.push_back(&m_Record);
	m_CollidableObjects.push_back(&m_RecordPlayer);

	std::list<Tile*> wallList = m_Map.GetWalls();
	std::list<Tile*>::iterator it;

	for (it = wallList.begin(); it != wallList.end(); ++it)
	{
		m_CollidableObjects.push_back(*it);	
	}

	m_Collision.CheckCollision(m_Player, m_CollidableObjects);

}

void GameManager::Draw() {	
	m_Renderer.Clear(sf::Color::Black);
	m_Renderer.Draw(m_Map.GetMapGrid(), m_Map.GetMapSize());
	m_Renderer.Draw(m_Player.GetSprite());
	m_Renderer.Draw(m_RecordPlayer.GetSprite());
	m_Renderer.Draw(m_Record.GetSprite());

	m_Renderer.Display();
}
