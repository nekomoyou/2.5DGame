#include "Player.h"

Player::Player(int sourceModelHandle)
    :PlayerBase(sourceModelHandle)
{
    //ˆ—‚È‚µ
}

Player::~Player()
{
    //ˆ—‚È‚µ
}

void Player::Update()
{
    MV1SetPosition(modelHandle, pos);
}