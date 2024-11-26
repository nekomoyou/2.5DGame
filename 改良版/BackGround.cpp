#include "BackGround.h"

BackGround::BackGround()
	:blend(255)
	,flg(true)
	,rightflg(false)
{
	Sky = LoadGraph("img/7fb8e46578641372c3172b3dd4ed3a90.jpg");
	Night = LoadGraph("img/Screenshot-2023-12-08-161049.png");
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void BackGround::Draw()
{
	DrawExtendGraph(0, 0, 1920, 850, Night, false);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, blend);
	DrawExtendGraph(0, 0, 1920, 850, Sky, false);
}

void BackGround::Update(int time)
{
	if (time <= 110 && flg)
	{
		blend--;
	}
	if (blend <= 0)
	{
		blend = 0;
		flg = false;
		rightflg = true;
	}
	if (rightflg && blend >=0)
	{
		blend++;
	}
	if (blend >= 255)
	{
		rightflg = false;
		flg = true;
	}
}

BackGround::~BackGround()
{

}