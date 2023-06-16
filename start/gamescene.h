#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <common/scene.h>

#include "grasstile.h"
#include "tile.h"
#include "player.h"

class GameScene : public Scene
{
public:
	GameScene();

	virtual ~GameScene();

	virtual void update(float deltaTime);

    const int gridWidth = 17;
    const int gridHeight = 13;

	std::vector<std::vector<Tile*>> grid;

	Player* player;

private:
};

#endif