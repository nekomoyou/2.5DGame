#pragma once
#include"DxLib.h"
#include"Random.h"

class Player;
class SoundSE;

class Interfere
{
public:
	Interfere();
	~Interfere();

    void Init();
    void Draw(bool flg);
    //void Animtion();
    void Update(bool flg,bool titleflg);
    void Collusion(const VECTOR Ppos);

    bool returnflg() { return Hitflg; }
    bool returnbomb() { return fallflg; }
    bool returnanimflg() { return Saveflg; }

private:
    bool Hitflg;                                //“–‚½‚è”»’è
    int BombImg;                                //
    float Angle;                                //
    VECTOR Bombpos;                             //
    bool fallflg;

    bool Saveflg;

    Random* rand = new Random();                //—”
    SoundSE* soundse;
    int down;

    //“–‚½‚è”»’è
    bool HitCheck(int leftx1, int topy1, int rightx1, int bottomy1, int leftx2, int topy2, int rightx2, int bottomy2);
};

