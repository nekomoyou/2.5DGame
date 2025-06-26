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
    
};

