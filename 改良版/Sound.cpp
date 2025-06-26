#include"Sound.h"

Sound::Sound()
{
    bgm[title] = LoadSoundMem("BGM/ゆったりお散歩.mp3");
    bgm[play] = LoadSoundMem("BGM/dotabatare-su.mp3");
    bgm[reslut] = LoadSoundMem("BGM/kamatamago_Recreation.mp3");

    for (int i = 0; i < 3; i++)
    {
        if (bgm[i] == -1)
        {
            printfDx("読み取れていません");
        }
    }

    Init();
}

SoundSE::SoundSE()
{
    se[coin] = LoadSoundMem("SE/coin05.mp3");
    se[blue] = LoadSoundMem("SE/coin04.mp3");
    se[green] = LoadSoundMem("SE/poka01.mp3");
    se[key] = LoadSoundMem("SE/poka03.mp3");
    se[star] = LoadSoundMem("SE/powerup10.mp3");
    se[bomb] = LoadSoundMem("SE/mini_bomb2.mp3");
    se[botton] = LoadSoundMem("SE/決定13.mp3");
    se[finish] = LoadSoundMem("SE/終了.mp3");

    for (int i = 0; i < 8; i++)
    {
        if (se[i] == -1)
        {
            printfDx("読み取れていません");
        }
    }
}

void Sound::Init()
{
    playnowsound = -1;
}

void Sound::PlaySoundA(const BGM& playIndex)
{
    if (playnowsound == playIndex)return;

    StopSoundMem(bgm[playnowsound]);

    playnowsound = playIndex;
    PlaySoundMem(bgm[playnowsound], DX_PLAYTYPE_LOOP);
}

void Sound::StopSound(const BGM& playIndex)
{
    if (playnowsound == -1)return;
    if (playnowsound != playIndex)return;

    if (CheckSoundMem(bgm[playnowsound]))
    {
        StopSoundMem(bgm[playnowsound]);
        playnowsound = -1;
    }
}

void SoundSE::PlaySE(const SE& playse)
{
    switch (playse)
    {
    case coin:
        PlaySoundMem(se[coin], DX_PLAYTYPE_BACK, true);
        break;
    case blue:
        PlaySoundMem(se[blue], DX_PLAYTYPE_BACK, true);
        break;
    case green:
        PlaySoundMem(se[green], DX_PLAYTYPE_BACK, true);
        break;
    case key:
        PlaySoundMem(se[key], DX_PLAYTYPE_BACK, true);
        break;
    case star:
        PlaySoundMem(se[star], DX_PLAYTYPE_BACK, true);
        break;
    case bomb:
        PlaySoundMem(se[bomb], DX_PLAYTYPE_BACK, true);
        break;
    case botton:
        PlaySoundMem(se[botton], DX_PLAYTYPE_BACK, true);
        break;
    case finish:
        PlaySoundMem(se[finish], DX_PLAYTYPE_BACK, true);
        break;
    }
}

Sound::~Sound()
{
    for (int i = 0; i < 4; i++)
    {
        DeleteSoundMem(bgm[i]);
    }
}

SoundSE::~SoundSE()
{
    for (int i = 0; i < 8; i++)
    {
        DeleteSoundMem(se[i]);
    }
}