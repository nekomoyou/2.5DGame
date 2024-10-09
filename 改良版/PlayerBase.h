#pragma once
#include"DxLib.h"

class PlayerBase
{
public:
    PlayerBase(int ModelHandle);
    virtual~PlayerBase();
    virtual void Draw();
    virtual void Update()abstract;

protected:
    int modelHandle;
    VECTOR pos;
};

