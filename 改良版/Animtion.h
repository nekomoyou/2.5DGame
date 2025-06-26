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
    //アニメーションの関数
    Anime attachAnim;           //再生中のアニメーション名
    int attachAnimeIndex;       //アニメーションのアタッチされた番号
    float animeTimer;           //アニメーションのタイマー
    float animeStopTime;        //アニメーションの終了タイマー
    bool isLoopAnime;           //ループするアニメーションか否か
};

