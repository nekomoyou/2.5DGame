#pragma once
#include"DxLib.h"

class BackGround
{
public:
	BackGround();
	~BackGround();

	void Draw();
	void Update(int time);

private:
	int Sky;
	int Night;
	int blend;
	bool flg;
	bool rightflg;
};

