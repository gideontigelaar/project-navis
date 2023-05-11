#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <common/scene.h>

#include "tile.h"

class GameScene : public Scene
{
public:

	GameScene();

	virtual ~GameScene();

	virtual void update(float deltaTime);

private:

	Tile* kingkong;
};

#endif