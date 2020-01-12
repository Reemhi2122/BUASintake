#include "Map.h"

Map::Map()
{
	m_MapGrid = new Tile[MAPGRIDCOUNT * MAPGRIDCOUNT];
	CreateMap();
}

void Map::CreateMap()
{
	CreateRooms();

	std::list<Room>::iterator it;
	for (it = m_Rooms.begin(); it != m_Rooms.end(); ++it)
	{
		it->CreateRoom(m_MapGrid, MAPGRIDCOUNT);
	}

	for (int i = 0; i < MAPGRIDCOUNT * MAPGRIDCOUNT; i++)
	{
		if (m_MapGrid[i].GetTileType() == TileType::Wall) {
			m_Walls.push_back(&m_MapGrid[i]);
		}
	}
}

void Map::CreateRooms() {

	RoomExit* tempExits = new RoomExit[1];
	tempExits[0].exitDirection = ExitDirection::RIGHT;
	tempExits[0].exitPos = 6;
	//tempExits[1].exitDirection = ExitDirection::LEFT;
	//tempExits[1].exitPos = 6;
	//tempExits[2].exitDirection = ExitDirection::RIGHT;
	//tempExits[2].exitPos = 6;
	//tempExits[3].exitDirection = ExitDirection::DOWN;
	//tempExits[3].exitPos = 6;

	RoomExit* tempExits2 = new RoomExit[1];
	tempExits2[0].exitDirection = ExitDirection::LEFT;
	tempExits2[0].exitPos = 6;

	RoomExit* tempExits3 = new RoomExit[1];
	tempExits3[0].exitDirection = ExitDirection::RIGHT;
	tempExits3[0].exitPos = 6;

	RoomExit* tempExits4 = new RoomExit[1];
	tempExits4[0].exitDirection = ExitDirection::TOP;
	tempExits4[0].exitPos = 7;

	RoomExit* tempExits5 = new RoomExit[1];
	tempExits5[0].exitDirection = ExitDirection::RIGHT;
	tempExits5[0].exitPos = 19;

	//m_Rooms.push_back(Room(sf::Vector2f(13, 13), sf::Vector2f(0,0), tempExits, 4));
	//m_Rooms.push_back(Room(sf::Vector2f(13, 13), sf::Vector2f(12,0), tempExits2, 1));
	//m_Rooms.push_back(Room(sf::Vector2f(13, 13), sf::Vector2f(-12,0), tempExits3, 1));
	//m_Rooms.push_back(Room(sf::Vector2f(39, 13), sf::Vector2f(0, -12), tempExits4, 1));
	//m_Rooms.push_back(Room(sf::Vector2f(39, 13), sf::Vector2f(0, 12), tempExits5, 1));

	m_Rooms.push_back(Room(sf::Vector2f(13, 13), sf::Vector2f(0, 0), tempExits, 4));
	m_Rooms.push_back(Room(sf::Vector2f(13, 13), sf::Vector2f(14, 0), tempExits2, 1));
	m_Rooms.push_back(Room(sf::Vector2f(13, 13), sf::Vector2f(-14, 0), tempExits3, 1));
	m_Rooms.push_back(Room(sf::Vector2f(39, 13), sf::Vector2f(0, -14), tempExits4, 1));
	m_Rooms.push_back(Room(sf::Vector2f(39, 13), sf::Vector2f(0, 14), tempExits5, 1));
}

std::list<Room> Map::GetRooms()
{
	return m_Rooms;
}

std::list<Tile*> Map::GetWalls()
{
	return m_Walls;
}

Tile* Map::GetMapGrid()
{
	return m_MapGrid;
}

int Map::GetMapSize()
{
	return MAPGRIDCOUNT;
}
