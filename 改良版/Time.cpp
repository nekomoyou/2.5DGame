#include "Time.h"

Time::Time()
    /*:Countdown(CountTime),NowTime(0),time(0),StartCount(StartTime)
	,Switchflg(true),morningCount(1),nightCount(0)
	,bombCount(6)*/
{
	startimg = LoadGraph("img/suta-tologo.png");
	Init();
}

/// <summary>
/// 初期化
/// </summary>
void Time::Init()
{
	time = NowTime = GetNowCount();
	Countdown = CountTime;
	StartCount = StartTime;
	Switchflg = true;
	morningCount = 1;
	nightCount = 0;
	bombCount = 8;
	bombflg = false;
	bombbeetween = 26;
}

/// <summary>
/// カウントダウン
/// </summary>
void Time::Count()
{
	NowTime = GetNowCount();
	if (NowTime - time > 1000)
	{
		//計測基準を現在にセット
		StartCount--;
		time = NowTime;
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

bool Time::bombManager(bool flg)
{
	bombflg = flg;
	if (Countdown <= ( 10 *  bombbeetween ))
	{
		bombflg = true;
		bombbeetween--;
		bombCount--;
		if (bombCount == 0)
		{
			bombCount = 1;
		}
	}
	return bombflg;
}

/// <summary>
/// 光源の時間管理
/// </summary>
/// <returns>光源のオン／オフ</returns>
bool Time::lightManager()
{
	SwitchSum = 30 * morningCount + 20 * nightCount;

	if (Countdown <= CountTime - SwitchSum  && Switchflg)
	{
		Switchflg = false;
		nightCount++;
	}

	SwitchSum = 30 * morningCount + 20 * nightCount;
	
	if (Countdown <= CountTime - SwitchSum && !Switchflg)
	{
		Switchflg = true;
		morningCount++;
	}
	return Switchflg;
}

/// <summary>
/// 描画
/// </summary>
void Time::Draw()
{
	SetFontSize(100);
	if (StartCount >= 1)
	{
		DrawFormatString(900, 500, GetColor(255, 69, 0), "%d", StartCount);
	}
	if (StartCount == 0)
	{
		DrawGraph(650, 350, startimg, true);
	}
	if (Switchflg)
	{
		DrawFormatString(850, 100, GetColor(112, 128, 144), "%d", Countdown);
	}
	else
	{
		DrawFormatString(850, 100, GetColor(255, 250, 250), "%d", Countdown);
	}
}



Time::~Time()
{

}