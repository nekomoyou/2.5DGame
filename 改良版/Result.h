#pragma once
#include"DxLib.h"

class Result
{
public:
    Result();
    ~Result();

    void Init();
    void LoadRanking(const char* filename);                             // �����L���O�f�[�^���t�@�C������ǂݍ��ފ֐�
    void SaveRanking(const char* filename);                             // �����L���O�f�[�^���t�@�C���ɕۑ�����֐�
    void DisplayRanking(int imgposx, int imgposy, int pulsimgx, int pulsimgy, int x, int y, int fontsize);// �����L���O����ʂɕ\������֐�
    void UpdateRanking(int score);                                      // �V�����X�R�A���o���Ƃ��Ƀ����L���O���X�V����֐�
    void SortRanking();                                                 // �����L���O�̃\�[�g
    void StringDraw();                                                  //���U���g�̕��͕\�L
    bool ReturnFlg() { return RankingInFlg; }

private:
    int scores[6];              //�����L���O�X�R�A
    int size;                   //�����L���O�̐�
    int myScore;                //����̃Q�[���̃X�R�A
    int img;                    //�����L���O�̊Ŕ�
    int congraImg;              //�����L���O���̎��̉摜
    int regretImg;              //�����L���O�O�̎��̉摜
    bool RankingInFlg;          //�����L���O�ɓ��������ǂ����̃t���O
    float angle;                //�p�x
    float rate;                 //�g�嗦
};

