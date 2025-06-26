#pragma once
#include"DxLib.h"
#include"Random.h"

class Item
{
public:
    Item();
    virtual ~Item();
    void Init();                                //������
    void animtion();                            //�A�j���[�V����
    void Draw();                                //�`��
    void Collusion(const VECTOR Ppos,bool flg);          //�����蔻��
    void Update();                              //�X�V����
    bool returnflg() { return Hitflg; };        //���������̃t���O
    int returnNum() { return ItemNum; };        //�A�C�e���̔ԍ�
    void SetItem();                             //�A�C�e����ݒu

    void UI();
    void ScoreUI();

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
    int randomNum;                              //
    int ItemNum;                                //�A�C�e���̔ԍ�

    int frameimg;

    bool UIflg;
    VECTOR UIpos;
    int num;

    //int BombImg;                                //
    //const static int BombChipSize = 48;         //�摜�̃T�C�Y
    //const static int BombImgSize = ChipSize + 30;//�`��T�C�Y
    //float Angle;                                //
    //VECTOR Bombpos;                             //

    Random* rand = new Random();                //����

    //�����蔻��
    bool HitCheck(int leftx1, int topy1, int rightx1, int bottomy1, int leftx2, int topy2, int rightx2, int bottomy2);
};

