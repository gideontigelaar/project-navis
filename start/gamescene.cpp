#include <fstream>
#include <sstream>
#include <cmath>

#include "gamescene.h"

GameScene::GameScene() : Scene()
{
	for(int y = 0; y < gridHeight; y++)
	{
		std::vector<Tile*> row;
		grid.push_back(row);
		for (int x = 0; x < gridWidth; x++)
		{
			Tile* tile = nullptr;
			grid[y].push_back(tile);

			if (y == 0 || y == gridHeight - 1 || x == 0 || x == gridWidth - 1)
			{
				grid[y][x] = new BorderTile();
			}
		}
	}

	for(int y =  1; y < gridHeight - 1; y++)
	{
		for(int x = 1; x < gridWidth - 1; x++)
		{
			if (y == 1 || y == 6 || y == 11)
			{
			    grid[y][x] = new GrassTile();
			}

			else if (y >= 2 && y <= 5)
			{
			    grid[y][x] = new WaterTile();
			}
			
			else if (y >= 7 && y <= 10)
			{
			    grid[y][x] = new RoadTile();
			}
		}
	}

	for(int y = 0; y < grid.size(); y++)
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

void GameScene::gameOver()
{
	std::cout << "Game Over!" << std::endl;
}

void GameScene::update(float deltaTime)
{
	int newX = round(player->position.x / 64);
	int newY = round(player->position.y / 64);

	if(input()->getKeyDown(KEY_W))
	{
		if(grid[newY - 1][newX]->isWalkable == true)
		{
    		player->position.y = (newY - 1) * 64;
		}
		else if(grid[newY - 1][newX]->isBorderTile == false)
		{
			gameOver();
		}
	}

	if(input()->getKeyDown(KEY_S))
	{
		if(grid[newY + 1][newX]->isWalkable == true)
		{
    		player->position.y = (newY + 1) * 64;
		}
		else if(grid[newY + 1][newX]->isBorderTile == false)
		{
			gameOver();
		}
	}

	if(input()->getKeyDown(KEY_A))
	{
		if(grid[newY][newX - 1]->isWalkable == true)
		{
			player->position.x = (newX - 1) * 64;
		}
		else if(grid[newY][newX - 1]->isBorderTile == false)
		{
			gameOver();
		}
	}

	if(input()->getKeyDown(KEY_D))
	{
		if(grid[newY][newX + 1]->isWalkable == true)
		{
			player->position.x = (newX + 1) * 64;
		}
		else if(grid[newY][newX + 1]->isBorderTile == false)
		{
			gameOver();
		}
	}
}