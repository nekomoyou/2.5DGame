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
class Light;
class SoundSE;

class GameManager
{
public:
    GameManager();
    ~GameManager();
    void Draw();
    void Game();
    void Reset();

    int RetrunScore();

    void SetGameflg(bool flg) { titleflg = flg; }
    bool finishGame() { return Gameflg; };
    void finishUI();
    void resultback();
    void ResetScore();

private:
    PlayerBase* player[1];          //
    Item* item[10];                  //
    Time* time;                     //
    //DelteTime* deltetime;           //
    Camera* camera;                 //
    Score* score;                   //
    Animtion* anim;                 //
    ItemTimer* itemtimer;           //
    BackObject* backobject;         //
    Interfere* interfere;           //
    BackGround* background;         //
    Light* light;                   //
    SoundSE* soundse;                   //

    bool playflg;
    bool Gameflg;
    int finishImg;
    struct finish
    {
        int x, y;
        float angle;
        float rate;
    };
    finish fin;

    bool titleflg;
};

