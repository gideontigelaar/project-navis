#ifndef ROADTILE_H
#define ROADTILE_H

#include "tile.h"

class RoadTile : public Tile
{
public:
	RoadTile();

	virtual ~RoadTile();

	virtual void update(float deltaTime);

private:
};

#endif