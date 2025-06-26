#pragma once
#include"DxLib.h"
#include"Random.h"

class Item
{
public:
    Item();
    virtual ~Item();
    void Init();                                //初期化
    void animtion();                            //アニメーション
    void Draw();                                //描画
    void Collusion(const VECTOR Ppos,bool flg);          //当たり判定
    void Update();                              //更新処理
    bool returnflg() { return Hitflg; };        //当たったのフラグ
    int returnNum() { return ItemNum; };        //アイテムの番号
    void SetItem();                             //アイテムを設置

    void UI();
    void ScoreUI();

private:
    VECTOR pos;                                 //アイテムの位置
    const static int ChipSize = 32;             //画像のサイズ
    const static int ImgSize = ChipSize + 30;   //描画サイズ
    const static int Xnum = 8;                  //画像の横の数
    const static int Ynum = 5;                  //画像の縦の数
    int animPattern;                            //アニメーションパターン
    bool Hitflg;                                //当たり判定
    int Img[Ynum][Xnum];                        //画像
    int frame;                                  //フレーム
    int randomNum;                              //
    int ItemNum;                                //アイテムの番号

    int frameimg;

    bool UIflg;
    VECTOR UIpos;
    int num;

    //int BombImg;                                //
    //const static int BombChipSize = 48;         //画像のサイズ
    //const static int BombImgSize = ChipSize + 30;//描画サイズ
    //float Angle;                                //
    //VECTOR Bombpos;                             //

    Random* rand = new Random();                //乱数

    //当たり判定
    bool HitCheck(int leftx1, int topy1, int rightx1, int bottomy1, int leftx2, int topy2, int rightx2, int bottomy2);
};

