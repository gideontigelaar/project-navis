#include "roadtile.h"

RoadTile::RoadTile() : Tile()
{
    this->AddSprite("assets/roadtile.tga");
    
	isWalkable = true;
    isBorderTile = false;
}

RoadTile::~RoadTile()
{
}

void RoadTile::update(float deltaTime)
{
}