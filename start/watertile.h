#ifndef WATERTILE_H
#define WATERTILE_H

#include "tile.h"

class WaterTile : public Tile
{
public:
	WaterTile();

	virtual ~WaterTile();

	virtual void update(float deltaTime);

private:
};

#endif