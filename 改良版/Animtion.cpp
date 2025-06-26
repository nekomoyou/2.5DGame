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
/// アニメーションのセット
/// </summary>
/// <param name="anime">再生するアニメーションの番号</param>
/// <param name="modelHandle">再生するモデル</param>
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
/// 削除するアニメーション
/// </summary>
/// <param name="anime">再生しているアニメーションの番号</param>
/// <param name="modelHandle">再生するモデル</param>
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
/// アニメーション再生
/// </summary>
/// <param name="modelHandle">再生するモデル</param>
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
    //処理なし
}