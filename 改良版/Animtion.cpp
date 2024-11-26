#include "Animtion.h"

Animtion::Animtion()
{
    attachAnim = static_cast<Anime>(-1);
    attachAnimeIndex = -1;
    animeStopTime = 0.0f;
    animeTimer = 0.0f;
    //isLoopAnime = false;
}

/// <summary>
/// �A�j���[�V�����̃Z�b�g
/// </summary>
/// <param name="anime">�Đ�����A�j���[�V�����̔ԍ�</param>
/// <param name="modelHandle">�Đ����郂�f��</param>
void Animtion::SetAnim(const Anime& anime,const int& modelHandle)
{
    if (anime == attachAnim)return;

    int anim = static_cast<int>(anime);

    MV1DetachAnim(modelHandle, attachAnimeIndex);

    attachAnimeIndex = MV1AttachAnim(modelHandle, anim, -1, false);
    attachAnim = anime;
    animeStopTime = MV1GetAttachAnimTotalTime(modelHandle, attachAnimeIndex);
    animeTimer = 0.0f;
}

/// <summary>
/// �폜����A�j���[�V����
/// </summary>
/// <param name="anime">�Đ����Ă���A�j���[�V�����̔ԍ�</param>
/// <param name="modelHandle">�Đ����郂�f��</param>
void Animtion::RemoveAnime(const Anime& anime, const int& modelHandle)
{
    if (attachAnimeIndex == -1)return;
    if (anime != attachAnim)return;

    MV1DetachAnim(modelHandle, attachAnimeIndex);
    attachAnim = static_cast<Anime>(-1);
    attachAnimeIndex = -1;
    animeStopTime = 0.0f;
    animeTimer = 0.0f;
}

/// <summary>
/// �A�j���[�V�����Đ�
/// </summary>
/// <param name="modelHandle">�Đ����郂�f��</param>
void Animtion::PlayAnime(const int& modelHandle)
{
    if (attachAnimeIndex == -1)return;
    
    if (animeStopTime <= animeTimer)
    {
        animeTimer = 0.0f;
    }
    MV1SetAttachAnimTime(modelHandle, attachAnimeIndex, animeTimer);

    animeTimer += 0.5f;
}

Animtion::~Animtion()
{
    //�����Ȃ�
}