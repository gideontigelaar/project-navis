#include "player.h"

Player::Player() : Entity()
{
    this->AddSprite("assets/player.tga");
}

Player::~Player()
{
}

void Player::update(float deltaTime)
{
}