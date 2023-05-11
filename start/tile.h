#ifndef TILE_H
#define TILE_H

#include <common/entity.h>

class Tile : public Entity
{
public:
	Tile();

	virtual ~Tile();

	virtual void update(float deltaTime);

private:
};

#endif