#pragma once
#include"DxLib.h"

class PlayerBase;
class Time;
class Item;
class DelteTime;
class Camera;
class Score;

class GameManager
{
public:
    GameManager();
    ~GameManager();
    void title();
    void Draw();
    void Game();

private:
    PlayerBase* player[5];
    Item* item[5];
    Time* time;
    DelteTime* deltetime;
    Camera* camera;
    Score* score;

    int ModelHandle;
    VECTOR pos;
};

