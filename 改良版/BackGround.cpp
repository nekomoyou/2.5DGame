#include "BackGround.h"

BackGround::BackGround()
	:blend(255)
	,flg(true)
	,rightflg(true)
	,morningCount(1),nightCount(2)
	,lightflg(true)
{
	Sky = LoadGraph("img/7fb8e46578641372c3172b3dd4ed3a90.jpg");
	Night = LoadGraph("img/Screenshot-2023-12-08-161049.png");
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void BackGround::Init()
{
	blend = 255;
	flg = true;
	rightflg = true;
	morningCount = 1;
	nightCount = 2;
	lightflg = true;
}

void BackGround::Draw()
{
	DrawExtendGraph(0, 0, 1920, 850, Night, false);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, blend);
	DrawExtendGraph(0, 0, 1920, 850, Sky, false);
}

void BackGround::Update(bool flg)
{
	/*if (time <= 50 * morningCount + 30 && !rightflg)
	{
		rightflg = true;
		morningCount--;
	}
	if (time <= 50 * nightCount && rightflg)
	{
		rightflg = false;
		nightCount--;
	}*/
	if (flg)
	{
		blend++;
		if (blend >= 255)
		{
			blend = 255;
			lightflg = true;
		}
	}
	if (!flg)
	{
		blend--;
		if (blend <= 0)
		{
			blend = 0;
			lightflg = false;
		}
	}
}

BackGround::~BackGround()
{
	DeleteGraph(Sky);
	DeleteGraph(Night);
}