#include <fstream>
#include <sstream>
#include <cmath>

#include "gamescene.h"

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
				// tile->position = Vector2(x * 64, y * 64);
				tile->position = glm::vec3(400.0f, 300.0f, 0.0f);
				this->AddChild(tile);
			}
		}
	}
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
}