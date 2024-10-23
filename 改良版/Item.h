#pragma once
#include"DxLib.h"
#include"Random.h"

class Item
{
public:
    Item();
    virtual ~Item();
    void animtion();
    void Draw();
    void Collusion(const VECTOR Ppos);
    void Update();
    bool returnflg() { return Hitflg; };
    void SetItem();

private:
    VECTOR pos;                                 //�A�C�e���̈ʒu
    const static int ChipSize = 32;             //�摜�̃T�C�Y
    const static int ImgSize = ChipSize + 30;   //�`��T�C�Y
    const static int Xnum = 8;                  //�摜�̉��̐�
    const static int Ynum = 5;                  //�摜�̏c�̐�
    int animPattern;                            //�A�j���[�V�����p�^�[��
    bool Hitflg;                                //�����蔻��
    int Img[Ynum][Xnum];                        //�摜
    int frame;                                  //�t���[��
    int ItemNum;                                //�A�C�e���̔ԍ�

    Random* rand = new Random();

    //�����蔻��
    bool HitCheck(int leftx1, int topy1, int rightx1, int bottomy1, int leftx2, int topy2, int rightx2, int bottomy2);
};

