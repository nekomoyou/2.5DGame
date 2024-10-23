#pragma once
#include"DxLib.h"

class Score
{
public:
    Score();
    ~Score();

    void Draw();
    void ScoreAdd(bool flg);

private:
    int nowScore;

};

