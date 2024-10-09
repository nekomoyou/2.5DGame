#include "Item.h"

Item::Item()
    :pos(VGet(500,0 + ImgSize,0)),animPattern(0),Hitflg(false)
{
    //画像の読み込み
    LoadDivGraph("img/Bluejuwel.png", Xnum * 1, Xnum, 1, ChipSize, ChipSize, Img[0], true);
    LoadDivGraph("img/coin.png", Xnum * 1, Xnum, 1, ChipSize, ChipSize, Img[1], true);
    LoadDivGraph("img/Greenjuwel.png", Xnum * 1, Xnum, 1, ChipSize, ChipSize, Img[2], true);
    LoadDivGraph("img/key.png", Xnum * 1, Xnum, 1, ChipSize, ChipSize, Img[3], true);
    LoadDivGraph("img/star.png", Xnum * 1, Xnum, 1, ChipSize, ChipSize, Img[4], true);
}



void Item::animtion()
{
    static int frame = 0;
    frame++;

    //フレームが設定されているフレームごとに
    if (frame % 20 == 0)
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

void Item::Update()
{

}

void Item::Draw()
{
    DrawExtendGraph(pos.x, pos.y, pos.x + ImgSize, pos.y + ImgSize, Img[0][animPattern], true);
    DrawBox(pos.x, pos.y, pos.x + ImgSize, pos.y + ImgSize, GetColor(255, 0, 0), false);
}

void Item::Collusion(const VECTOR Ppos)
{
    Hitflg = HitCheck(Ppos.x, Ppos.y,
        Ppos.x + 130, Ppos.y + 30,
        pos.x, pos.y,
        pos.x + ImgSize, pos.y + ImgSize);
}

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