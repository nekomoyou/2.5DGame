#pragma once
#include"DxLib.h"

class Sound
{
public:
    Sound();
    ~Sound();

    enum BGM
    {
        title,
        play,
        reslut
    };
    void Init();
    void PlaySoundA(const BGM& playIndex);
    void StopSound(const BGM& playIndex);

private:
    int bgm[3];
    int playnowsound;
};

class SoundSE
{
public:
    SoundSE();
    ~SoundSE();

    enum SE
    {
        coin,
        blue,
        green,
        key,
        star,
        bomb,
        botton,
        finish
    };
    void PlaySE(const SE& playse);

private:
    int se[8];

};

