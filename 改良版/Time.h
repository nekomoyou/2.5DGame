#pragma once
#include"DxLib.h"

class Time
{
public:
    Time();
    virtual ~Time();
    void Count();               //�J�E���g����
    void Draw();                //�`��
    void Init();                //������
    bool lightManager();        //�����Ǘ�
    bool bombManager(bool flg);


    int ReturnTime() { return Countdown; };     //�J�E���g�̎���
    int ReturnStaet() { return StartCount; };   //�X�^�[�g�܂ł̎���

private:
    const int StartTime = 3;        //�Q�[���J�n�O
    const int CountTime = 130;       //�Q�[������
    int Countdown;                  //�J�E���g�_�E��
    int NowTime;                    //���ݎ���
    int time;                       //�P�t���[���O�̎���
    int StartCount;                 //�X�^�[�g�܂ł̎���

    bool Switchflg;                 //�����t���O
    int morningCount;               //���̃J�E���g
    int nightCount;                 //��̃J�E���g
    int SwitchSum;                  //���v�l

    bool bombflg;
    int bombCount;
    int bombbeetween;

    int startimg;
};

