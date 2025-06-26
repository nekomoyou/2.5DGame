#pragma once
#include"DxLib.h"

class Animtion
{
public:
    Animtion();
    ~Animtion();

    enum class Anime
    {
        fall = 0,
        Run = 11,
        Wait = 3,
        Move = 16
    };
    void SetAnim(const Anime&anime, const int& modelHandle, const bool& isLoop);
    void RemoveAnime(const int& modelHandle, const Anime& anime);
    void PlayAnime(const int& modelHandle);

private:
    //�A�j���[�V�����̊֐�
    Anime attachAnim;           //�Đ����̃A�j���[�V������
    int attachAnimeIndex;       //�A�j���[�V�����̃A�^�b�`���ꂽ�ԍ�
    float animeTimer;           //�A�j���[�V�����̃^�C�}�[
    float animeStopTime;        //�A�j���[�V�����̏I���^�C�}�[
    bool isLoopAnime;           //���[�v����A�j���[�V�������ۂ�
};

