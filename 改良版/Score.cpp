#include "Score.h"

Score::Score()
    :nowScore(0)
{

}

void Score::ScoreAdd(bool flg)
{

}

void Score::Draw()
{
    DrawFormatString(0, 50, GetColor(255, 255, 255), "Score:%d", nowScore);
}

Score::~Score()
{

}