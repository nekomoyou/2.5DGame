#pragma once
#include"DxLib.h"

class Score
{
public:
    Score();
    ~Score();

    void Init();
    void Draw();                        //描画
    void ScoreAdd(int Num);    //スコア加点

private:
    int nowScore;               //現在のスコア
    int coin;
    int bluejuwel;
    int greenjuwel;
    int key;
    int star;
};

