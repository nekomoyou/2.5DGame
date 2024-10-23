#pragma once
#include"DxLib.h"

class Time
{
public:
    Time();
    virtual ~Time();
    void Count();
    void Draw();

    int RetrunTime() { return Countdown; };

private:
    int Countdown;
    int NowTime;
    int time;
};

