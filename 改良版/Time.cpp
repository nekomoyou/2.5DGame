#include "Time.h"

Time::Time()
    :Countdown(30),NowTime(0),time(0)
{
    time = NowTime = GetNowCount();
}

void Time::Count()
{
	NowTime = GetNowCount();
	if (NowTime - time > 1000)
	{
		//計測基準を現在にセット
		time = NowTime;
		Countdown--;

		if (Countdown < 0)
		{
			Countdown = 0;
		}
	}
}

void Time::Draw()
{
	DrawFormatString(0, 100, GetColor(255, 255, 255), "Time:%d", Countdown);
}

Time::~Time()
{

}