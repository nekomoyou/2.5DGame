#pragma once
#include"DxLib.h"

class ItemBase
{
public:
    ItemBase(int model);
    virtual ~ItemBase();
    virtual void Draw();

protected:
};

