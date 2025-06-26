#pragma once
#include"DxLib.h"
#include"Random.h"

class SoundSE;

class Score
{
public:
    Score(/*const char* filename*/);
    ~Score();

    void Init();
    void Draw();               //描画
    void ScoreAdd(int Num/*,bool flg*/);    //スコア加点
    int ReturnScore() { return nowScore; }

private:
    int nowScore;               //現在のスコア
    Random* rand = new Random();

    enum Item
    {
         coin,
         bluejuwel,
         greenjuwel,
         key,
         star
    };

    int ItemCount[5];
    int img;
    SoundSE* soundse;
};

