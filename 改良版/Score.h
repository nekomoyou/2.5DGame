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
    void Draw();               //�`��
    void ScoreAdd(int Num/*,bool flg*/);    //�X�R�A���_
    int ReturnScore() { return nowScore; }

private:
    int nowScore;               //���݂̃X�R�A
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

