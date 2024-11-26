#pragma once
#include"DxLib.h"

class Animtion
{
public:
    Animtion();
    ~Animtion();

    enum class Anime
    {
        Run = 11,
        Wait = 3
    };
    void SetAnim(const Anime&anime, const int& modelHandle);
    void RemoveAnime(const Anime& anime, const int& modelHandle);
    void PlayAnime(const int& modelHandle);

private:
    //アニメーションの関数
    Anime attachAnim;           //再生中のアニメーション名
    int attachAnimeIndex;       //アニメーションのアタッチされた番号
    float animeTimer;           //アニメーションのタイマー
    float animeStopTime;        //アニメーションの終了タイマー
    //bool isLoopAnime;           //ループするアニメーションか否か
};

