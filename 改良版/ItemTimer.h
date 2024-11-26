#pragma once
#include"DxLib.h"

class ItemTimer
{
public:
	ItemTimer();
	~ItemTimer();
	void Init();
	void GetTime(int time) { CountTime = time; };
	void showItem();
	int ItemSet() { return ItemNum; };

private:
	int ItemNum;
	int CountTime;
	int Count;
};

