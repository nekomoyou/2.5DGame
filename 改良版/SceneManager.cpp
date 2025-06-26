#include "SceneManager.h"
#include"DxLib.h"
#include"GameManager.h"
#include"Sound.h"
#include"Result.h"

SceneManager::SceneManager()
    :scene(title)
{
    game = new GameManager();
    result = new Result();
    sound = new Sound();
    soundse = new SoundSE();
    img = LoadGraph("img/‘è–¼.png");
    //result->SaveRanking("Ranking.txt");
    bottonflg = false;
}

/// <summary>
/// XVˆ—
/// </summary>
void SceneManager::Update()
{
    result->LoadRanking("Ranking.txt");
            static int f;

    if (scene == title)
    {
        sound->PlaySoundA(Sound::title);
        game->SetGameflg(true);
        game->Game();
        if (CheckHitKey(KEY_INPUT_RETURN))
        {
            bottonflg = true;
            soundse->PlaySE(SoundSE::botton);
        }
        if (bottonflg)
        {
            f++;
            if (f >= 20)
            {
                sound->StopSound(Sound::title);
                game->SetGameflg(false);
                game->Reset();
                scene = play;
                f = 0;
                bottonflg = false;
            }
        }
    }
    if (scene == play)
    {
        sound->PlaySoundA(Sound::play);
        game->Game();
    }
        
    if (game->finishGame() == false /*|| CheckHitKey(KEY_INPUT_TAB)*/)
    {
        sound->StopSound(Sound::play);
        scene = record;
    }

    if (scene == record)
    {
        sound->StopSound(Sound::play);
        sound->PlaySoundA(Sound::reslut);
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            bottonflg = true;
            soundse->PlaySE(SoundSE::botton);
        }
        if (bottonflg)
        {
            f++;
            if (f >= 20)
            {
                game->Reset();
                result->Init();
                scene = title;
                f = 0;
                bottonflg = false;
            }
        }
        if (CheckHitKey(KEY_INPUT_RETURN))
        {
            bottonflg2 = true;
            soundse->PlaySE(SoundSE::botton);
        }
        if (bottonflg2)
        {
            f++;
            if (f >= 20)
            {
                game->Reset();
                result->Init();
                scene = play;
                f = 0;
                bottonflg2 = false;
            }
        }
    }
}

/// <summary>
/// •`‰æ
/// </summary>
void SceneManager::Draw()
{
    static int f;
    int s;
    static int font = 150;
    int i = 1;
    static float x = 470;
    static float y = 40;
    if (scene == title)
    {
        f++;
        s = f % 40;
        game->Draw();
        if(s <= 20)
        {
            DrawString(450, 950, "ENTER PUSH THE START", GetColor(0, 255, 255));
        }
        if (f >= 120)
        {
            f = 0;
        }
        SetFontSize(font);
        result->DisplayRanking(550,300,750,650,750,450,80);
        //result->UpdateRanking(game->RetrunScore());
        DrawExtendGraph(400, 0, 1400, 300, img, true);
    }
    if (scene == explanation)
    {

    }
    if (scene == play)
    {
        game->Draw();
        //game->finishUI();
    }
    if (scene == record)
    {
        game->resultback();
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        result->LoadRanking("Ranking.txt");
        result->UpdateRanking(game->RetrunScore());
        result->DisplayRanking(100,50,800,900,250,250,100);
        result->SaveRanking("Ranking.txt");
        result->StringDraw();
        game->ResetScore();
    }
    ScreenFlip();
}

SceneManager::~SceneManager()
{
    delete result;
    delete game;
    delete sound;
    DeleteGraph(img);
}