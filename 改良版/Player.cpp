#include "Player.h"

Player::Player(int sourceModelHandle)
    :PlayerBase(sourceModelHandle)
{
    //�����Ȃ�
}

Player::~Player()
{
    //�����Ȃ�
}

void Player::Update()
{
    MV1SetPosition(modelHandle, pos);
}