#pragma once
#include "Room.h"
#include <list>
#include <iostream>
#include <SFML/Graphics.hpp>

class Map
{

public:
	Map();
	void CreateMap();
	void CreateRooms();

	std::list<Room> GetRooms();
	std::list<Tile*> GetWalls();
	Tile* GetMapGrid();
	int GetMapSize();

private:
	static const int MAPGRIDCOUNT = 50;
	std::list<Room> m_Rooms;
	std::list<Tile*> m_Walls;
	Tile* m_MapGrid;
};

