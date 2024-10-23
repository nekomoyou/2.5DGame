#pragma once
#include"DxLib.h"

class PlayerBase
{
public:
    PlayerBase(const char *ModelHandle);
    virtual~PlayerBase();
    virtual void Draw();
    virtual void Update();
    virtual void IsMove();

    void animtion();
    void a();

    int GetModelHandle() { return modelHandle; }

    // �|�W�V������getter/setter.
    const VECTOR& GetPos() const { return pos; }
    void SetPos(const VECTOR set) { pos = set; }

    VECTOR Hitpos;//�����蔻��

    typedef enum Anim
    {
        Stop,
        Walk
    };

protected:
    int modelHandle;//���f���n���h��
    VECTOR pos;//���f���̃|�W�V����
    bool pushLeft;//�������������̃t���O
    bool pushRight;//�E�����������̃t���O

    const float PlayerSpeed = 2;//�v���C���[�̈ړ��X�s�[�h

    VECTOR angle;

    //�A�j���[�V�����̊֐�
    int AnimTotalTime;//�g�[�^������
    int AnimPlayTime;//�Đ�����
    int AnimStopIndex;//�����~�܂�
    int AnimWalkIndex;//����
    int AnimPlaybackIndex;//�Đ�����ԍ�
    int AnimIndex;
};

