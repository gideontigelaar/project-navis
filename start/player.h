#ifndef PLAYER_H
#define PLAYER_H

#include <common/entity.h>

class Player : public Entity
{
public:
	Player();

	virtual ~Player();

	virtual void update(float deltaTime);

private:
};

#endif