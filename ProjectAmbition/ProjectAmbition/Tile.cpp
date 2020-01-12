#include "Tile.h"

Tile::Tile() : Object()
{
	type = TileType::Wall;
}

TileType Tile::GetTileType()
{
	return type;
}

void Tile::SetTileType(TileType a_Type)
{
	type = a_Type;
}
