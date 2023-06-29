#include "car.h"

Car::Car() : Tile()
{
    this->AddSprite("assets/car.tga");
}

Car::~Car()
{
}

void Car::update(float deltaTime)
{
}