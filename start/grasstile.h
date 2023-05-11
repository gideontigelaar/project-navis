#ifndef GRASSTILE_H
#define GRASSTILE_H

#include "tile.h"

class GrassTile : public Tile
{
public:
	GrassTile();

	virtual ~GrassTile();

	virtual void update(float deltaTime);

private:
};

#endif