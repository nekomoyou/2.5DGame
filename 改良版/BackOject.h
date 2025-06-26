#pragma once
#include"DxLib.h"

class BackOject
{
public:
    BackOject(const char* modelHandle);
    ~BackOject();

    void Draw();
    void SetPos(const VECTOR set) { pos = set; }

private:
    VECTOR pos;
    int ModelHandle;
};

