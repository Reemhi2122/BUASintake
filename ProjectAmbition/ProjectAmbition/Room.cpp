#include "Room.h"

Room::Room() {};

//Constructor that makes the room
Room::Room(sf::Vector2f a_Size, sf::Vector2f a_Pos, RoomExit* a_Exits, int a_ExitsInt)
{
	m_Size = a_Size;
	m_Pos = a_Pos;
	m_RoomExits = a_Exits;
	m_Exits = a_ExitsInt;

	m_FloorTile.loadFromFile("Images/Floortile.png");
	m_WallTile.loadFromFile("Images/Walltile.png");
	m_CornerWallTile.loadFromFile("Images/Cornerwalltile.png");
}

//Create the room with tiles
void Room::CreateRoom(Tile* a_MapGrid, int a_MapGridSize)
{
	//Used variables to create the room
	int divider = 2;
	m_startPos = sf::Vector2f((25 - (int)(m_Size.x / divider)) + m_Pos.x, (25 - (int)(m_Size.y / divider)) + m_Pos.y);

	//Create the tiles
	for (int x = m_startPos.x; x < m_startPos.x + m_Size.x; x++)
	{
		for (int y = m_startPos.y; y < m_startPos.y + m_Size.y; y++)
		{
			Tile curSprite;
			int startDrawPos = ((a_MapGridSize * 64) / 2);

			curSprite.GetSprite().setPosition(sf::Vector2f((x * TILESIZE) - startDrawPos, (y * TILESIZE) - startDrawPos));
			curSprite.GetSprite().setOrigin(32,32);

			CalculateTexture(x, y, &curSprite);

			a_MapGrid[x + y * 50] = curSprite;
		}
	}

	for (int i = 0; i < m_Exits; i++)
	{
		int pos = 4;
		switch (m_RoomExits[i].exitDirection)
		{
			case ExitDirection::TOP:
			{
				int newYPos = m_startPos.x + m_RoomExits[i].exitPos;
				pos = m_startPos.y + newYPos * 50;
				break;
			}
			case ExitDirection::RIGHT:
			{
				int newXPos = m_startPos.y + (m_Size.y - 1);
				int newYPos = m_startPos.x + (m_Size.x - 1);
				pos = (newXPos - m_RoomExits[i].exitPos) + newYPos * 50;
				break;
			}
			case ExitDirection::DOWN:
			{
				int newXPos = m_startPos.y + (m_Size.y - 1);
				int newYPos = m_startPos.x + (m_Size.x - 1);
				pos = newXPos + (newYPos - m_RoomExits[i].exitPos) * 50;
				std::cout << pos << std::endl;
				break;
			}
			case ExitDirection::LEFT:
			{
				int newXPos = m_startPos.y + m_RoomExits->exitPos;
				pos = newXPos + m_startPos.x * 50;
				break;
			}
			default:
			{
				break;
			}
		}

		a_MapGrid[pos].SetTileType(TileType::Floor);
		a_MapGrid[pos].GetSprite().setTexture(m_FloorTile);
		a_MapGrid[pos].GetSprite().setRotation(0);
	}
}

void Room::CalculateTexture(int a_I, int a_Y, Tile* a_Tile)
{
	sf::Sprite* tempSprite = &a_Tile->GetSprite();

	if (a_I == m_startPos.x && a_Y == m_startPos.y) {
		tempSprite->setTexture(m_CornerWallTile);
		tempSprite->rotate(180);
		a_Tile->SetTileType(TileType::Wall);
		return;
	}
	if (a_I == m_startPos.x && a_Y == m_startPos.y + m_Size.y - 1) {
		tempSprite->setTexture(m_CornerWallTile);
		tempSprite->rotate(90);
		a_Tile->SetTileType(TileType::Wall);
		return;
	}
	if (a_I == m_startPos.x + m_Size.x - 1 && a_Y == m_startPos.y) {
		tempSprite->setTexture(m_CornerWallTile);
		tempSprite->rotate(270);
		a_Tile->SetTileType(TileType::Wall);
		return;
	}
	if (a_I == m_startPos.x + m_Size.x - 1 && a_Y == m_startPos.y + m_Size.y - 1) {
		tempSprite->setTexture(m_CornerWallTile);
		a_Tile->SetTileType(TileType::Wall);
		return;
	}

	if (a_I == m_startPos.x || a_I == m_startPos.x + m_Size.x - 1) {
		tempSprite->setTexture(m_WallTile);
		a_Tile->SetTileType(TileType::Wall);
	}
	else if (a_Y == m_startPos.y || a_Y == m_startPos.y + m_Size.y - 1) {
		tempSprite->setTexture(m_WallTile);
		tempSprite->rotate(90);
		a_Tile->SetTileType(TileType::Wall);
	}
	else {
		tempSprite->setTexture(m_FloorTile);
		a_Tile->SetTileType(TileType::Floor);
	}
}

//Returns the tiles from the room
std::list<sf::Sprite>* Room::GetTiles()
{
	return &m_Tiles;
}
