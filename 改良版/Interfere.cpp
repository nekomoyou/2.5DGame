#include "Interfere.h"

Interfere::Interfere()
	:pos(VGet(0,100,0))
	,frame(0)
	,Hitflg(false)
	,animPattern(12)
    ,Angle(0)
    ,Bombpos(VGet(100,100,0))
{
	LoadDivGraph("img/Crow.png", ChipNum * ChipNum, ChipNum, ChipNum, ChipSize, ChipSize, Img, true);
    BombImg = LoadGraph("img/other_bomb01_01-768x768.png");
}

/// <summary>
/// 初期化
/// </summary>
void Interfere::Init()
{
	pos = VGet(0, 100, 0);
	Hitflg = false;
	frame = 0;
	animPattern = 12;
    Bombpos = VGet(100, 100, 0);
}

/// <summary>
/// 描画
/// </summary>
void Interfere::Draw()
{
    DrawRotaGraph(Bombpos.x, Bombpos.y, 0.15, Angle * DX_PI_F / 180.0, BombImg, true, false);
    DrawBox(Bombpos.x - 50, Bombpos.y - 50, Bombpos.x + 50, Bombpos.y + 50, GetColor(255, 0, 0), false);
	DrawExtendGraph(pos.x, pos.y, pos.x + ImgSize, pos.y + ImgSize, Img[animPattern], true);
    DrawBox(pos.x, pos.y + 10, pos.x + ImgSize - 10, pos.y + ImgSize - 20, GetColor(255, 0, 0), false);
}

/// <summary>
/// アニメーション
/// </summary>
void Interfere::Animtion()
{
    frame++;

    //フレームが設定されているフレームごとに
    if (frame % 10 == 0)
    {
        //アニメーションを１枚進める
        animPattern++;
        //アニメーションが枚数を超えたら
        if (animPattern >= ChipNum * ChipNum - 1)
        {
            animPattern = 12;
        }
    }
    if (frame >= 100)
    {
        frame = 0;
    }
}

/// <summary>
/// 更新
/// </summary>
void Interfere::Update()
{
    float down = 2;
    pos = VAdd(pos, VGet(2, down ,0));
    Bombpos = VAdd(Bombpos, VGet(0, down, 0));
    Angle--;
}

Interfere::~Interfere()
{
    for (int i = 0; i < ChipNum * ChipNum; i++)
    {
        DeleteGraph(Img[i]);
    }
    DeleteGraph(BombImg);
}