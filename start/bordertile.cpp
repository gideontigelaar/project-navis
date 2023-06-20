#include "bordertile.h"

BorderTile::BorderTile() : Tile()
{
    this->AddSprite("assets/bordertile.tga");

	isWalkable = false;
    isBorderTile = true;
}

BorderTile::~BorderTile()
{
}

void BorderTile::update(float deltaTime)
{
}