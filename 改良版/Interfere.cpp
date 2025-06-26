#include "Interfere.h"
#include"Sound.h"

Interfere::Interfere()
	:Angle(0)
    ,Bombpos(VGet(100,100,0))
    ,fallflg(false)
{
	//LoadDivGraph("img/Crow.png", ChipNum * ChipNum, ChipNum, ChipNum, ChipSize, ChipSize, Img, true);
    BombImg = LoadGraph("img/other_bomb01_01-768x768.png");
    soundse = new SoundSE();
    Init();
}

/// <summary>
/// 初期化
/// </summary>
void Interfere::Init()
{
	//pos = VGet(0, 100, 0);
	/*frame = 0;
	animPattern = 12;*/
	Hitflg = false;
    Bombpos = VGet(rand->Randpos(1980,100), 100, 0);
    fallflg = false;
    Saveflg = false;
    down = 3;
}

/// <summary>
/// 描画
/// </summary>
void Interfere::Draw(bool flg)
{
    if (fallflg || flg)
    {
        DrawRotaGraph(Bombpos.x, Bombpos.y, 0.15, Angle * DX_PI_F / 180.0, BombImg, true, false);
        //DrawBox(Bombpos.x - 50, Bombpos.y - 50, Bombpos.x + 50, Bombpos.y + 50, GetColor(255, 0, 0), false);
    }
}

/// <summary>
/// 更新
/// </summary>
void Interfere::Update(bool flg,bool titleflg)
{
    static int f;
    fallflg = flg;
    //pos = VAdd(pos, VGet(2, down ,0));

    if (Hitflg || Bombpos.y >= 900)
    {
        Bombpos = VGet(rand->Randpos(1980,100), 100, 0);
        if (!titleflg)
        {
            down += 0.5;
        }
        fallflg = false;
    }
    if (fallflg || titleflg)
    {
        Bombpos = VAdd(Bombpos, VGet(0, down, 0));
        Angle -= 2;
    }
    if (Hitflg)
    {
        Saveflg = true;
        soundse->PlaySE(SoundSE::bomb);
    }
    if (Saveflg)
    {
        f++;
    }
    if (f >= 65)
    {
        Saveflg = false;
        f = 0;
    }
}

/// <summary>
/// 当たり判定
/// </summary>
/// <param name="Ppos">プレイヤーの位置</param>
void Interfere::Collusion(const VECTOR Ppos)
{
    Hitflg = HitCheck(Ppos.x, Ppos.y,               //プレイヤーの左上
        Ppos.x + 130, Ppos.y + 30,                  //プレイヤーの右下
        Bombpos.x, Bombpos.y,                       //アイテムの左上
        Bombpos.x + 50, Bombpos.y + 50);            //アイテムの右下
  }

/// <summary>
/// 当たり判定
/// </summary>
bool Interfere::HitCheck(int leftx1, int topy1, int rightx1, int bottomy1, int leftx2, int topy2, int rightx2, int bottomy2)
{
    return (leftx1 <= rightx2 && leftx2 <= rightx1 && topy1 <= bottomy2 && topy2 <= bottomy1);
}

Interfere::~Interfere()
{
    //for (int i = 0; i < ChipNum * ChipNum; i++)
    {
       //DeleteGraph(Img[i]);
    }
    DeleteGraph(BombImg);
}