#pragma once
#include"DxLib.h"
#include"PlayerBase.h"

class PlayerBase;

class Camera
{
public:
    Camera(const PlayerBase& player);
    ~Camera();
    void Update();

private:
    bool flg;
    bool lightflg;
    VECTOR pos;
    VECTOR Lightpos;

    int light[2];
    float Range = 2000.0f;
    float Atten0 = 0.0f;
    float Atten1 = 0.0006f;
    float Atten2 = 0.0f;
};

