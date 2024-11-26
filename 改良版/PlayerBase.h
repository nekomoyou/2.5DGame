#pragma once
#include"DxLib.h"

class PlayerBase
{
public:
    PlayerBase(const char *ModelHandle);
    virtual~PlayerBase();

    void Init();//������

    virtual void Draw();            //�`��
    virtual void Update();          //�X�V����
    virtual void IsMove();          //�ړ�����

    //�Đ�����A�j���[�V�����ԍ�
    int ReturnAnim() { return AnimPlaybackIndex; };

    //���f���n���h��
    int GetModelHandle() { return modelHandle; }

    // �|�W�V������getter/setter.
    const VECTOR& GetPos() const { return pos; }
    void SetPos(const VECTOR set) { pos = set; }

    const VECTOR& ReturnHitpos() { return Hitpos; };

protected:
    int modelHandle;        //���f���n���h��
    VECTOR pos;             //���f���̃|�W�V����
    VECTOR dir;             //�ړ�����
    VECTOR Hitpos;          //�A�C�e���̓����蔻��
    VECTOR BodyHitpos;      //�̂̓����蔻��

    bool pushLeft;          //�������������̃t���O
    bool pushRight;         //�E�����������̃t���O
    bool pushJump;          //�W�����v�t���O
    bool onGround;          //�n�ʂɂ��邩�ǂ���

    float JumpPow;          //�W�����v�̍���
    float Gravity;          //�d��

    const float PlayerSpeed = 2;//�v���C���[�̈ړ��X�s�[�h
    const float HitSpeed = 1.9;//�����蔻��̃X�s�[�h����

    VECTOR angle;           //�p�x

    int AnimPlaybackIndex;  //�Đ�����ԍ�
};

