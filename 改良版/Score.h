#pragma once
#include"DxLib.h"

class Score
{
public:
    Score();
    ~Score();

    void Init();
    void Draw();                        //�`��
    void ScoreAdd(int Num);    //�X�R�A���_

private:
    int nowScore;               //���݂̃X�R�A
    int coin;
    int bluejuwel;
    int greenjuwel;
    int key;
    int star;
};

