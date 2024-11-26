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
/// ������
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
/// �`��
/// </summary>
void Interfere::Draw()
{
    DrawRotaGraph(Bombpos.x, Bombpos.y, 0.15, Angle * DX_PI_F / 180.0, BombImg, true, false);
    DrawBox(Bombpos.x - 50, Bombpos.y - 50, Bombpos.x + 50, Bombpos.y + 50, GetColor(255, 0, 0), false);
	DrawExtendGraph(pos.x, pos.y, pos.x + ImgSize, pos.y + ImgSize, Img[animPattern], true);
    DrawBox(pos.x, pos.y + 10, pos.x + ImgSize - 10, pos.y + ImgSize - 20, GetColor(255, 0, 0), false);
}

/// <summary>
/// �A�j���[�V����
/// </summary>
void Interfere::Animtion()
{
    frame++;

    //�t���[�����ݒ肳��Ă���t���[�����Ƃ�
    if (frame % 10 == 0)
    {
        //�A�j���[�V�������P���i�߂�
        animPattern++;
        //�A�j���[�V�����������𒴂�����
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
/// �X�V
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