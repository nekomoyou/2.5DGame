#pragma once
#include"DxLib.h"
#include"PlayerBase.h"

class Player:public PlayerBase
{
public:
    Player(int sourceModelHandle);
    ~Player();
    void Update()override;
};

