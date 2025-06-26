#pragma once
#include"DxLib.h"

class BackObject
{
public:
    BackObject();
    ~BackObject();

    void Draw();
    void SetObj();
    //void SetPos(const VECTOR set) { pos = set; }

private:
    VECTOR pos;
    static const int ObjNum = 7;
    const float band = 220.0f;
    int ModelHandle[ObjNum];
    int Sky;
    int Night;

    VECTOR lightpos;
    int Lightmodel[4];
    int Star;
    int One;
};

