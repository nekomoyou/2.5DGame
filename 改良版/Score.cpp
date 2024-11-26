#include "Score.h"

Score::Score()
    :nowScore(0)
    ,coin(0)
    ,bluejuwel(0)
    ,greenjuwel(0)
    ,key(0)
    ,star(0)
{

}

/// <summary>
/// ������
/// </summary>
void Score::Init()
{
    nowScore = 0;
    coin = 0;
    bluejuwel = 0;
    greenjuwel = 0;
    key = 0;
    star = 0;
}

/// <summary>
/// �X�R�A���_
/// </summary>
/// <param name="flg">�����������̃t���O</param>
/// <param name="Num">���������A�C�e���̔ԍ�</param>
void Score::ScoreAdd(int Num)
{
    if (Num == 4)
    {
        nowScore += 500;
        star++;
    }
    else if (Num == 3)
    {
        nowScore += 300;
        key++;
    }
    else if (Num == 2)
    {
        nowScore += 100;
        greenjuwel++;
    }
    else if (Num == 1)
    {
        nowScore += 50;
        bluejuwel++;
    }
    else
    {
        nowScore += 10;
        coin++;
    }
}

/// <summary>
/// �`��
/// </summary>
void Score::Draw()
{
    DrawFormatString(0, 50, GetColor(255, 255, 255), "Score:%d", nowScore);
    DrawFormatString(0, 980, GetColor(255, 255, 255), "Star:%d,Key:%d,Greenjuwel:%d,Bluejuwel:%d,Coin:%d", star, key, greenjuwel, bluejuwel, coin);
}

Score::~Score()
{

}