#include "Time.h"

Time::Time()
    :Countdown(CountTime),NowTime(0),time(0),StartCount(StartTime)
{
    time = NowTime = GetNowCount();
}

/// <summary>
/// ������
/// </summary>
void Time::Init()
{
	time = NowTime = GetNowCount();
	Countdown = CountTime;
	StartCount = StartTime;
}

/// <summary>
/// �J�E���g�_�E��
/// </summary>
void Time::Count()
{
	NowTime = GetNowCount();
	if (NowTime - time > 1000)
	{
		//�v��������݂ɃZ�b�g
		time = NowTime;
		StartCount--;
		if (StartCount < 0)
		{
			Countdown--;
		}

		if (Countdown < 0)
		{
			Countdown = 0;
		}
	}
}

/// <summary>
/// �`��
/// </summary>
void Time::Draw()
{
	if (StartCount >= 0)
	{
		DrawFormatString(500, 500, GetColor(255, 255, 255), "%d", StartCount);
	}
	DrawFormatString(0, 100, GetColor(255, 255, 255), "Time:%d", Countdown);
}

Time::~Time()
{

}