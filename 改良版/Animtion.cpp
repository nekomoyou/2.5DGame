#include "Animtion.h"

Animtion::Animtion()
{
    attachAnim = static_cast<Anime>(-1);
    attachAnimeIndex = -1;
    animeStopTime = 0.0f;
    animeTimer = 0.0f;
    isLoopAnime = false;
}

/// <summary>
/// �A�j���[�V�����̃Z�b�g
/// </summary>
/// <param name="anime">�Đ�����A�j���[�V�����̔ԍ�</param>
/// <param name="modelHandle">�Đ����郂�f��</param>
void Animtion::SetAnim(const Anime& anime,const int& modelHandle, const bool& isLoop)
{
    if (anime == attachAnim)return;

    int anim = static_cast<int>(anime);

    MV1DetachAnim(modelHandle, attachAnimeIndex);

    attachAnimeIndex = MV1AttachAnim(modelHandle, anim, -1, false);
    attachAnim = anime;
    animeStopTime = MV1GetAttachAnimTotalTime(modelHandle, attachAnimeIndex);
    animeTimer = 0.0f;
    isLoopAnime = isLoop;
}

/// <summary>
/// �폜����A�j���[�V����
/// </summary>
/// <param name="anime">�Đ����Ă���A�j���[�V�����̔ԍ�</param>
/// <param name="modelHandle">�Đ����郂�f��</param>
void Animtion::RemoveAnime(const int& modelHandle,const Anime& anime)
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
        if (isLoopAnime)
        {
            animeTimer = 0.0f;
        }
        else
        {
            RemoveAnime(modelHandle,attachAnim);
        }
    }

    MV1SetAttachAnimTime(modelHandle, attachAnimeIndex, animeTimer);
    /*if (attachAnim == Anime::Move)
    {
        animeTimer += 0.6f;
    }*/
    if (attachAnim == Anime::fall)
    {
        animeTimer += 0.3f;
    }
    else
    {
        animeTimer += 0.5f;
    }
}

Animtion::~Animtion()
{
    //�����Ȃ�
}