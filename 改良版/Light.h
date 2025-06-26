#pragma once
#include"DxLib.h"

class Time;

class Light
{
public:
    Light();
    ~Light();

    void Init();
    void Update(bool flg);

private:
    VECTOR Lightpos;
    VECTOR Lightpos2;

    bool lightflg;
    int light[2];

    int Count;

    float Range = 2000.0f;
    float Atten0 = 0.0f;
    float Atten1 = 0.00001f;
    float Atten2 = 0.0f;
};

