#include "Item.h"

Item::Item()
{
    //画像の読み込み
    LoadDivGraph("img/coin.png", Xnum * 1, Xnum, 1, ChipSize, ChipSize, Img[0], true);
    LoadDivGraph("img/Bluejuwel.png", Xnum * 1, Xnum, 1, ChipSize, ChipSize, Img[1], true);
    LoadDivGraph("img/Greenjuwel.png", Xnum * 1, Xnum, 1, ChipSize, ChipSize, Img[2], true);
    LoadDivGraph("img/key.png", Xnum * 1, Xnum, 1, ChipSize, ChipSize, Img[3], true);
    LoadDivGraph("img/star.png", Xnum * 1, Xnum, 1, ChipSize, ChipSize, Img[4], true);

    frameimg = LoadGraph("img/ki.png");
    Init();
}

/// <summary>
/// 初期化
/// </summary>
void Item::Init()
{
    frame = 0;
    animPattern = 0;
    Hitflg = false;
    pos = VGet(rand->Randpos(1800,ChipSize), 0 + ChipSize, 0);
    UIflg = false;
    UIpos = VGet(0, 0, 0);
}

/// <summary>
/// アニメーション
/// </summary>
void Item::animtion()
{
    frame++;
    //Angle--;

    //フレームが設定されているフレームごとに
    if (frame % 10 == 0)
    {
        //アニメーションを１枚進める
        animPattern++;
        //アニメーションが枚数を超えたら
        if (animPattern >= Xnum)
        {
            animPattern = 0;
        }
    }
}

/// <summary>
/// アイテムの設置
/// </summary>
void Item::SetItem()
{
    if (pos.y >= 900||Hitflg)
    {
        pos = VGet(rand->Randpos(1800, ChipSize), 0, 0);
        randomNum = rand->RandNum(100);
        frame = 0;
        if (randomNum >= 0 && randomNum <= 5)
        {
            ItemNum = 4;
        }
        else if (randomNum >= 6 && randomNum <= 20)
        {
            ItemNum = 3;
        }
        else if (randomNum >= 21 && randomNum <= 40)
        {
            ItemNum = 2;
        }
        else if (randomNum >= 41 && randomNum <= 60)
        {
            ItemNum = 1;
        }
        else
        {
            ItemNum = 0;
        }
    }
}

/// <summary>
/// 更新処理
/// </summary>
void Item::Update()
{
    if (frame >= 50)
    {
        pos = VAdd(pos, VGet(0, 3.5, 0));
    }
}

/// <summary>
/// 描画
/// </summary>
void Item::Draw()
{
    DrawExtendGraph(pos.x, pos.y, pos.x + ImgSize, pos.y + ImgSize, Img[ItemNum][animPattern], true);
    //DrawBox(pos.x, pos.y, pos.x + ImgSize, pos.y + ImgSize, GetColor(255, 0, 0), false);
    //DrawRotaGraph(Bombpos.x, Bombpos.y, 0.15, Angle * DX_PI_F / 180.0, BombImg, true, false);
    //DrawBox(Bombpos.x - 50, Bombpos.y - 50, Bombpos.x + 50, Bombpos.y + 50, GetColor(255, 0, 0), false);
}

void Item::UI()
{
    //365
    int between = 365;
    DrawExtendGraph(-80, 910, 2000, 1100, frameimg, true);
    for (int i = 0; i < Ynum; i++)
    {
        DrawExtendGraph(20 + between * i, 1020 - ImgSize, 20 + between * i + ImgSize + 30, 1020 + 30, Img[i][0], true);
    }
}

void Item::ScoreUI()
{
    static int f;
    int color = GetColor(255, 255, 255);
    if (Hitflg)
    {
        UIflg = true;
        UIpos = pos;
        num = ItemNum;
    }
    if (UIflg)
    {
        f++;
        SetFontSize(50);
        switch (num)
        {
        case 0:
            DrawString(UIpos.x, UIpos.y, "10", color);
            break;
        case 1:
            DrawString(UIpos.x, UIpos.y, "50", color);
            break;
        case 2:
            DrawString(UIpos.x, UIpos.y, "100", color);
            break;
        case 3:
            DrawString(UIpos.x, UIpos.y, "300", color);
            break;
        case 4:
            DrawString(UIpos.x, UIpos.y, "500", color);
            break;
        }
    }
    if (f >= 40)
    {
        UIflg = false;
        f = 0;
        num = -1;
    }
}

/// <summary>
/// 当たり判定
/// </summary>
/// <param name="Ppos">プレイヤーの位置</param>
void Item::Collusion(const VECTOR Ppos,bool flg)
{
    if (!flg)
    {
        Hitflg = HitCheck(Ppos.x, Ppos.y,       //プレイヤーの左上
            Ppos.x + 130, Ppos.y + 30,          //プレイヤーの右下
            pos.x, pos.y,                       //アイテムの左上
            pos.x + ImgSize, pos.y + ImgSize);  //アイテムの右下
    }
}

/// <summary>
/// 当たり判定
/// </summary>
bool Item::HitCheck(int leftx1, int topy1, int rightx1, int bottomy1, int leftx2, int topy2, int rightx2, int bottomy2)
{
    return (leftx1 <= rightx2 && leftx2 <= rightx1 && topy1 <= bottomy2 && topy2 <= bottomy1);
}

Item::~Item()
{
    for (int i = 0; i < Ynum; i++)
    {
        for (int j = 0; j < Xnum; j++)
        {
            DeleteGraph(Img[i][j]);
        }
    }
}