#pragma once
#include "Object.h"
#include "structs.cpp"

class Tile : public Object
{
public:
	Tile();

	TileType GetTileType();
	void SetTileType(TileType a_Type);

private:
	TileType type;
};