#include "DelteTime.h"
#include"DxLib.h"

DelteTime::DelteTime()
    :StartTime(0),mFPS(0),Count(0)
{
    //�����Ȃ�
}

bool DelteTime::Update()
{
    if (Count == 0)//1�t���[���ڂȂ畽�ς��v�Z����
    {
        StartTime = GetNowCount();
    }
    if (Count == N)//60�t���[���ڂȂ畽�ς��v�Z����
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
    int tookTime = GetNowCount() - StartTime;//������������
    int waitTime = Count * 1000 / FPS - tookTime;//�҂ׂ�����
    if (waitTime > 0)
    {
        Sleep(waitTime);//�ҋ@
    }
}

DelteTime::~DelteTime()
{

}