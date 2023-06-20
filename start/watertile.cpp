#include "watertile.h"

WaterTile::WaterTile() : Tile()
{
    this->AddSprite("assets/watertile.tga");

	isWalkable = false;
    isBorderTile = false;
}

WaterTile::~WaterTile()
{
}

void WaterTile::update(float deltaTime)
{
}