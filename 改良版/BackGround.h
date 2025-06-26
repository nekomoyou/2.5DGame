#pragma once
#include"DxLib.h"

class BackGround
{
public:
	BackGround();
	~BackGround();

	void Init();
	void Draw();
	void Update(bool flg);
	bool Returnflg() { return lightflg; }

private:
	int Sky;
	int Night;
	int blend;
	bool flg;
	bool rightflg;
	int morningCount;
	int nightCount;
	bool lightflg;
};

