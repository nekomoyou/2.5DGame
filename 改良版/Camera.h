#pragma once
#include"DxLib.h"
#include"PlayerBase.h"

class PlayerBase;

class Camera
{
public:
    Camera(const PlayerBase& player);
    ~Camera();

private:
    VECTOR pos;
};

