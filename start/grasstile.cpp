#include "grasstile.h"

GrassTile::GrassTile() : Tile()
{
    this->AddSprite("assets/grasstile.tga");

	isWalkable = true;
    isBorderTile = false;
}

GrassTile::~GrassTile()
{
}

void GrassTile::update(float deltaTime)
{
}