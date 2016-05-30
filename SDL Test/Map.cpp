#include "Map.h"
#include "Math.h"


Map::Map() {
	// A default field.
	walls.emplace_back(WallBlock(0, 5, 0x00CCDDFF));
	walls.emplace_back(WallBlock(2, 5, 0xDDAA11FF));
	walls.emplace_back(WallBlock(-1, 5, 0x00CC00FF));
	walls.emplace_back(WallBlock(-1, 6, 0xFFDDFFFF));
}


Map::~Map() {
}

Uint32 Map::GetBlockColor(Math::Vector2 v) {
	for (WallBlock &wb : walls) {
		if (v.x >= wb.GetX() && v.x - 1 < wb.GetX() && v.y >= wb.GetY() && v.y - 1 < wb.GetY()) {
			return wb.GetColor();
		}
	}
	return NULL;
}

bool Map::InWall(Math::Vector2 v) {
	if (GetBlockColor(v) == NULL) {
		return false;
	} else {
		return true;
	}
}