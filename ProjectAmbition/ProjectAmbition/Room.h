#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Tile.h"
#include "Structs.cpp"

class Room
{
public:
	Room();
	Room(sf::Vector2f a_Size, sf::Vector2f a_Pos, RoomExit* exit, int a_Exits);
	
	void CreateRoom(Tile* a_MapGrid, int a_MapGridSize);
	void CalculateTexture(int a_I, int a_Y, Tile* a_Sprite);

	std::list<sf::Sprite>* GetTiles();

private:
	sf::Vector2f m_Size;
	sf::Vector2f m_Pos;
	sf::Vector2f m_startPos;
	int m_Exits;

	RoomExit* m_RoomExits;

	sf::Texture m_FloorTile;
	sf::Texture m_WallTile;
	sf::Texture m_CornerWallTile;

	std::list<sf::Sprite> m_Tiles;

	const int TILESIZE = 64;
};

