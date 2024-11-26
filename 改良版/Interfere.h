#pragma once
#include"DxLib.h"
#include"Random.h"

class Interfere
{
public:
	Interfere();
	~Interfere();

    void Init();
    void Draw();
    void Animtion();
    void Update();

private:
    VECTOR pos;                                 //アイテムの位置
    const static int ChipSize = 48;             //画像のサイズ
    const static int ImgSize = ChipSize + 30;   //描画サイズ
    const static int ChipNum = 4;               //画像の縦横の枚数
    int animPattern;                            //アニメーションパターン
    bool Hitflg;                                //当たり判定
    int Img[ChipNum * ChipNum];                 //画像
    int frame;                                  //フレーム
    int ItemNum;                                //アイテムの番号

    int BombImg;                                //
    float Angle;                                //
    VECTOR Bombpos;                             //

    Random* rand = new Random();                //乱数

    //当たり判定
    bool HitCheck(int leftx1, int topy1, int rightx1, int bottomy1, int leftx2, int topy2, int rightx2, int bottomy2);
};

