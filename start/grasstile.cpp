#include "grasstile.h"

GrassTile::GrassTile() : Tile()
{
    this->AddSprite("assets/tile.tga");
}

GrassTile::~GrassTile()
{
}

void GrassTile::update(float deltaTime)
{
}