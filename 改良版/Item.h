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
    VECTOR pos;                                 //�A�C�e���̈ʒu
    const static int ChipSize = 32;             //�摜�̃T�C�Y
    const static int ImgSize = ChipSize + 30;   //�`��T�C�Y
    const static int Xnum = 8;
    const static int Ynum = 5;
    int animPattern;                            //�A�j���[�V�����p�^�[��
    bool Hitflg;                                //�����蔻��
    int Img[Ynum][Xnum];

    //�����蔻��
    bool HitCheck(int leftx1, int topy1, int rightx1, int bottomy1, int leftx2, int topy2, int rightx2, int bottomy2);
};

