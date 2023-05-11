#include "gamescene.h"

GameScene::GameScene() : Scene()
{
	kingkong = new Tile();
	kingkong->position = glm::vec3(400.0f, 300.0f, 0.0f);
	this->AddChild(kingkong);
}

GameScene::~GameScene()
{
}

void GameScene::update(float deltaTime)
{
	kingkong->position.x += deltaTime * 10; // for now, do it here
}