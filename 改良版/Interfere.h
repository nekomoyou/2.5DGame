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
    VECTOR pos;                                 //�A�C�e���̈ʒu
    const static int ChipSize = 48;             //�摜�̃T�C�Y
    const static int ImgSize = ChipSize + 30;   //�`��T�C�Y
    const static int ChipNum = 4;               //�摜�̏c���̖���
    int animPattern;                            //�A�j���[�V�����p�^�[��
    bool Hitflg;                                //�����蔻��
    int Img[ChipNum * ChipNum];                 //�摜
    int frame;                                  //�t���[��
    int ItemNum;                                //�A�C�e���̔ԍ�

    int BombImg;                                //
    float Angle;                                //
    VECTOR Bombpos;                             //

    Random* rand = new Random();                //����

    //�����蔻��
    bool HitCheck(int leftx1, int topy1, int rightx1, int bottomy1, int leftx2, int topy2, int rightx2, int bottomy2);
};

