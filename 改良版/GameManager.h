#pragma once
#include"DxLib.h"

class PlayerBase;
class Time;
class Item;
class DelteTime;
class Camera;
class Score;
class Animtion;
class ItemTimer;
class BackObject;
class Interfere;
class BackGround;

class GameManager
{
public:
    GameManager();
    ~GameManager();
    void title();
    void Draw();
    void Game();
    void Reset();

private:
    PlayerBase* player[1];          //
    Item* item[6];                  //
    Time* time;                     //
    DelteTime* deltetime;           //
    Camera* camera;                 //
    Score* score;                   //
    Animtion* anim;                 //
    ItemTimer* itemtimer;           //
    BackObject* backobject;         //
    Interfere* interfere;           //
    BackGround* background;
};

