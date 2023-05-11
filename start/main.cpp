#include <common/core.h>

#include "gamescene.h"

int main( void )
{
	Core core;
	
	GameScene* scene = new GameScene();

	while(core.IsRunning())
	{
		core.Run(scene);
	}

	delete scene;

	return 0;
}