#include "DelteTime.h"
#include"DxLib.h"

DelteTime::DelteTime()
    :StartTime(0),mFPS(0),Count(0)
{
    //処理なし
}

bool DelteTime::Update()
{
    if (Count == 0)//1フレーム目なら平均を計算する
    {
        StartTime = GetNowCount();
    }
    if (Count == N)//60フレーム目なら平均を計算する
    {
        int t = GetNowCount();
        mFPS = 1000.f / ((t - StartTime) / (float)N);
        StartTime = t;
    }
    Count++;
    return true;
}

void DelteTime::Draw()
{
    DrawFormatString(0, 0, GetColor(255, 255, 255), "FPS:%f", mFPS);
}

void DelteTime::Wait()
{
    int tookTime = GetNowCount() - StartTime;//かかった時間
    int waitTime = Count * 1000 / FPS - tookTime;//待つべき時間
    if (waitTime > 0)
    {
        Sleep(waitTime);//待機
    }
}

DelteTime::~DelteTime()
{

}