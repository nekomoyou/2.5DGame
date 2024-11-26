#include "Item.h"

Item::Item()
    :pos(VGet(300,0 + ImgSize,0)),animPattern(0),Hitflg(false),frame(0),ItemNum(0)
{
    //画像の読み込み
    LoadDivGraph("img/coin.png", Xnum * 1, Xnum, 1, ChipSize, ChipSize, Img[0], true);
    LoadDivGraph("img/Bluejuwel.png", Xnum * 1, Xnum, 1, ChipSize, ChipSize, Img[1], true);
    LoadDivGraph("img/Greenjuwel.png", Xnum * 1, Xnum, 1, ChipSize, ChipSize, Img[2], true);
    LoadDivGraph("img/key.png", Xnum * 1, Xnum, 1, ChipSize, ChipSize, Img[3], true);
    LoadDivGraph("img/star.png", Xnum * 1, Xnum, 1, ChipSize, ChipSize, Img[4], true);
}

/// <summary>
/// 初期化
/// </summary>
void Item::Init()
{
    frame = 0;
    animPattern = 0;
    Hitflg = false;
    pos = VGet(500, 0 - ImgSize, 0);
}

/// <summary>
/// アニメーション
/// </summary>
void Item::animtion()
{
    frame++;

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
    if (pos.y >= 1000||Hitflg)
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
        pos = VAdd(pos, VGet(0, 3, 0));
    }
}

/// <summary>
/// 描画
/// </summary>
void Item::Draw()
{
    DrawExtendGraph(pos.x, pos.y, pos.x + ImgSize, pos.y + ImgSize, Img[ItemNum][animPattern], true);
    DrawBox(pos.x, pos.y, pos.x + ImgSize, pos.y + ImgSize, GetColor(255, 0, 0), false);
}

/// <summary>
/// 当たり判定
/// </summary>
/// <param name="Ppos">プレイヤーの位置</param>
void Item::Collusion(const VECTOR Ppos)
{
    Hitflg = HitCheck(Ppos.x, Ppos.y,       //プレイヤーの左上
        Ppos.x + 130, Ppos.y + 30,          //プレイヤーの右下
        pos.x, pos.y,                       //アイテムの左上
        pos.x + ImgSize, pos.y + ImgSize);  //アイテムの右下
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