#ifndef BORDERTILE_H
#define BORDERTILE_H

#include "tile.h"

class BorderTile : public Tile
{
public:
	BorderTile();

	virtual ~BorderTile();

	virtual void update(float deltaTime);

private:
};

#endif