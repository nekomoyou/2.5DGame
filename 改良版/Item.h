#pragma once
#include"DxLib.h"

class Item
{
public:
    Item();
    ~Item();
    void animtion();
    void Draw();
    void Collusion(const VECTOR Ppos);
    void Update();
    bool returnflg() { return Hitflg; };

private:
    VECTOR pos;                                 //アイテムの位置
    const static int ChipSize = 32;             //画像のサイズ
    const static int ImgSize = ChipSize + 30;   //描画サイズ
    const static int Xnum = 8;
    const static int Ynum = 5;
    int animPattern;                            //アニメーションパターン
    bool Hitflg;                                //当たり判定
    int Img[Ynum][Xnum];

    //当たり判定
    bool HitCheck(int leftx1, int topy1, int rightx1, int bottomy1, int leftx2, int topy2, int rightx2, int bottomy2);
};

