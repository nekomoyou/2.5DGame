#pragma once
#include"DxLib.h"
#include"PlayerBase.h"

class Player:public PlayerBase
{
public:
    Player(const char *path);
    virtual ~Player();
    //void Update()override;
};

