#pragma once
#include "Object.h"

enum class CollisionSide {
	TOP,
	RIGHT,
	BOTTOM,
	LEFT,
	NONE
};

enum class ExitDirection {
	TOP,
	RIGHT,
	DOWN,
	LEFT
};

enum class TileType {
	Floor,
	Wall
};

struct CollisionData {
	bool Collision;
	Object* Object;
	CollisionSide CurCollisionSide;

	void Reset() {
		Collision = false;
		Object = nullptr;
		CurCollisionSide = CollisionSide::NONE;
	}
};

struct RoomExit {
	ExitDirection exitDirection;
	int exitPos;
};