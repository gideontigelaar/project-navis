#include <fstream>
#include <sstream>
#include <cmath>

#include "gamescene.h"

// #include "external/glfw-3.3/src/internal.h"
// #include "external/glfw-3.3/src/internal.h"

GameScene::GameScene() : Scene()
{
	for (int y = 0; y < gridHeight; y++)
	{
		std::vector<Tile*> row;
		grid.push_back(row);
		for (int x = 0; x < gridWidth; x++)
		{
			Tile* tile = nullptr;
			grid[y].push_back(tile);

			if (y == 0 || y == gridHeight - 1 || x == 0 || x == gridWidth - 1)
			{
				grid[y][x] = new GrassTile();
			}
		}
	}

	for (int y = 0; y < grid.size(); y++)
	{
		for (int x = 0; x < grid[y].size(); x++)
		{
			Tile* tile = grid[y][x];
			
			if (tile != nullptr)
			{
				tile->position = glm::vec3(x * 64, y * 64, 0);

				this->AddChild(tile);
			}
		}
	}

	player = new Player();
	player->position = glm::vec3(64, 64, 0);
	this->AddChild(player);
}

GameScene::~GameScene()
{
	for(int y = 0; y < grid.size(); y++)
	{
		for(int x = 0; x < grid[y].size(); x++)
		{
			delete grid[y][x];
			grid[y][x] = nullptr;
		}
	}

	grid.clear();
}

void GameScene::update(float deltaTime)
{
	int newX = round(player->position.x / 64);
	int newY = round(player->position.y / 64);

	if(input()->getKeyDown(KEY_W) && grid[newY - 1][newX] == nullptr)
	{
    	player->position.y = (newY - 1) * 64;
	}

	if(input()->getKeyDown(KEY_S) && grid[newY + 1][newX] == nullptr)
	{
    	player->position.y = (newY + 1) * 64;
	}

	if(input()->getKeyDown(KEY_A) && grid[newY][newX - 1] == nullptr)
	{
    	player->position.x = (newX - 1) * 64;
	}

	if(input()->getKeyDown(KEY_D) && grid[newY][newX + 1] == nullptr)
	{
    	player->position.x = (newX + 1) * 64;
	}
}