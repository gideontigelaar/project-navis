#include "watertile.h"

WaterTile::WaterTile() : Tile()
{
    this->AddSprite("assets/tile.tga");
}

WaterTile::~WaterTile()
{
}

void WaterTile::update(float deltaTime)
{
}