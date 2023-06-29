#ifndef CAR_H
#define CAR_H

#include "tile.h"

class Car : public Tile
{
public:
	Car();

	virtual ~Car();

	virtual void update(float deltaTime);

private:
};

#endif