#include "Score.h"
#include"Sound.h"

Score::Score(/*const char* filename*/)
    :nowScore(0)
{
    soundse = new SoundSE();
    img = LoadGraph("img/X.png");
    Init();
}

/// <summary>
/// 初期化
/// </summary>
void Score::Init()
{
    nowScore = 0;
    for (int i = 0; i < 5; i++)
    {
        ItemCount[i] = 0;
    }
}

/// <summary>
/// スコア加点
/// </summary>
/// <param name="flg">当たったかのフラグ</param>
/// <param name="Num">当たったアイテムの番号</param>
void Score::ScoreAdd(int Num/*,bool flg*/)
{
    /*if(!flg)*/
    switch (Num)
    {
    case coin:
        ItemCount[coin]++;
        soundse->PlaySE(SoundSE::coin);
        break;

    case bluejuwel:
        ItemCount[bluejuwel]++;
        soundse->PlaySE(SoundSE::blue);
        break;

    case greenjuwel:
        ItemCount[greenjuwel]++;
        soundse->PlaySE(SoundSE::green);
        break;

    case key:
        ItemCount[key]++;
        soundse->PlaySE(SoundSE::key);
        break;

    case star:
        ItemCount[star]++;
        soundse->PlaySE(SoundSE::star);
        break;
    }
    /*else
    {
        int num = rand->RandNum(4);
        ItemCount[num]--;
    }*/
    nowScore = 500 * ItemCount[4] + 300 * ItemCount[3] + 100 * ItemCount[2] + 50 * ItemCount[1] + 10 * ItemCount[0];
}

/// <summary>
/// 描画
/// </summary>
void Score::Draw()
{
    SetFontSize(80);
    DrawFormatString(0, 0, GetColor(255, 255, 255), "Score:%d", nowScore);
    SetFontSize(50);
    for (int i = 0; i < 5; i++)
    {
        DrawExtendGraph(100 + 370 * i, 990, 150 + 370 * i, 1030, img, true);
        DrawFormatString(150 + 370 * i, 980, GetColor(34, 139, 34), "%d", ItemCount[i]);
    }
}

Score::~Score()
{
    DeleteGraph(img);
}