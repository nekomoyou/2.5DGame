#pragma once
#include"DxLib.h"

class PlayerBase
{
public:
    PlayerBase(const char *ModelHandle);
    virtual~PlayerBase();

    void Init();//������

    virtual void Draw(bool flg,bool drawflg);    //�`��
    virtual void Update();          //�X�V����
    virtual void IsMove();          //�ړ�����
    void ResultAnim();

    //�Đ�����A�j���[�V�����ԍ�
    int ReturnAnim() { return AnimPlaybackIndex; };

    //���f���n���h��
    int GetModelHandle() { return modelHandle; }

    // �|�W�V������getter/setter.
    const VECTOR& GetPos() const { return pos; }
    void SetPos(const VECTOR set) { pos = set; }

    const VECTOR& ReturnHitpos() { return Hitpos; };

    bool returnflg() { return graphflg; }

protected:
    int modelHandle;        //���f���n���h��
    VECTOR pos;             //���f���̃|�W�V����
    VECTOR dir;             //�ړ�����
    VECTOR Hitpos;          //�A�C�e���̓����蔻��

    bool pushLeft;          //�������������̃t���O
    bool pushRight;         //�E�����������̃t���O

    bool pushDash;          //�_�b�V���t���O
    int dashframe;          //�_�b�V���̃t���[��
    VECTOR gauge;           //�Q�[�W�̈ʒu

    float JumpPow;          //�W�����v�̍���
    float Gravity;          //�d��

    float PlayerSpeed;      //�v���C���[�̈ړ��X�s�[�h
    const float HitSpeed = 1.9;//�����蔻��̃X�s�[�h����

    VECTOR angle;           //�p�x

    int AnimPlaybackIndex;  //�Đ�����ԍ�

    bool graphflg;
};

