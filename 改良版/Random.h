#pragma once
#include"DxLib.h"

class Random
{
public:
    int Xpos;
    int Number;
    int Randpos(int WindowSize, int chipSize)
    {
        Xpos = GetRand(WindowSize - chipSize);
        if (Xpos >= WindowSize)
        {
            Xpos = WindowSize - chipSize;
        }
        return Xpos;
    }
    int RandNum(int Num)
    {
        Number = GetRand(Num);
        return Number;
    }
};