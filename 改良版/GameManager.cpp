#include "GameManager.h"
#include"PlayerBase.h"
#include"Time.h"
#include"Item.h"
#include"DelteTime.h"
#include"Camera.h"
#include"Score.h"
#include"Animtion.h"
#include"ItemTimer.h"
#include"BackObject.h"
#include"Interfere.h"
#include"BackGround.h"
#include"Light.h"
#include"Sound.h"

GameManager::GameManager()
{
    player[0] = new PlayerBase("3Dモデル/Character.mv1");
	//player[1] = new PlayerBase("3Dモデル/Character/Rabbit_Bald.mv1");

	finishImg = LoadGraph("img/終了.png");

	Gameflg = true;
	playflg = true;
	fin.x = 950;
	fin.y = 500;
	fin.rate = 0;
	fin.angle = 0;

	titleflg = true;

    time = new Time();
    for (int i = 0; i < 10; i++)
    {
        item[i] = new Item();
    }
    //deltetime = new DelteTime();
	camera = new Camera(*player[0]);
	score = new Score();
	anim = new Animtion();
	itemtimer = new ItemTimer();
	backobject = new BackObject();
	interfere = new Interfere();
	background = new BackGround();
	light = new Light();
	soundse = new SoundSE();
	backobject->SetObj();
}

/// <summary>
/// 更新処理
/// </summary>
void GameManager::Game()
{
	//deltetime->Update();
	if (playflg)
	{
		if (!titleflg)
		{
			time->Count();
		}
		if (!interfere->returnanimflg())
		{
			anim->SetAnim(Animtion::Anime(player[0]->ReturnAnim()), player[0]->GetModelHandle(), true);
		}
		else
		{
			anim->SetAnim(Animtion::Anime(0), player[0]->GetModelHandle(), false);
		}

		itemtimer->GetTime(time->ReturnTime());
		background->Update(time->lightManager());

		light->Update(background->Returnflg());

		if (time->ReturnStaet() < 0 || titleflg)
		{
			interfere->Update(time->bombManager(interfere->returnbomb()),titleflg);
			//interfere->Animtion();
			interfere->Collusion(player[0]->ReturnHitpos());
			for (int i = 0; i < itemtimer->showItem(); i++)
			{
				item[i]->animtion();
				item[i]->Update();
				item[i]->SetItem();
				item[i]->Collusion(player[0]->ReturnHitpos(),player[0]->returnflg());
				if (item[i]->returnflg() && !titleflg)
				{
					score->ScoreAdd(item[i]->returnNum()/*,interfere->returnflg()*/);
				}
			}
			if (!interfere->returnanimflg())
			{
				player[0]->IsMove();
				player[0]->Update();
			}
		}
		camera->Update();
		//anim->Setflg(interfere->returnflg());
		anim->PlayAnime(player[0]->GetModelHandle());
	}
	//deltetime->Wait();
}

/// <summary>
/// 描画
/// </summary>
void GameManager::Draw()
{
	background->Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	backobject->Draw();
	if (time->ReturnStaet() < 0 || titleflg)
	{
		for (int i = 0; i < itemtimer->showItem(); i++)
		{
			item[i]->Draw();
			item[i]->ScoreUI();
		}
	}
	//deltetime->Draw();
	player[0]->Draw(background->Returnflg(),interfere->returnanimflg());
	interfere->Draw(titleflg);
	finishUI();
	
	if (!titleflg)
	{
		item[0]->UI();
		score->Draw();
		time->Draw();
	}
}

int GameManager::RetrunScore()
{
	return score->ReturnScore();
}

void GameManager::ResetScore()
{
	score->Init();
}

void GameManager::finishUI()
{
	static bool flg = true;
	static int f;
	if (time->ReturnTime() <= 0)
	{
		if (flg)
		{
			soundse->PlaySE(SoundSE::finish);
			flg = false;
		}
		playflg = false;
		DrawRotaGraph(fin.x, fin.y, fin.rate, fin.angle * DX_PI_F / 180.0f, finishImg, true, false);
		if (fin.angle <= 360)
		{
			fin.angle += 5;
			fin.rate += 0.02;
		}
		else
		{
			f++;
		}
		if(f >= 80)
		{
			Gameflg = false;
			f = 0;
			flg = true;
		}
	}
}

/// <summary>
/// 初期化
/// </summary>
void GameManager::Reset()
{
	player[0]->Init();
	time->Init();
	score->Init();
	for (int i = 0; i < 10; i++)
	{
		item[i]->Init();
	}
	itemtimer->Init();
	interfere->Init();
	background->Init();
	fin.angle = 0;
	fin.rate = 0;
	Gameflg = true;
	playflg = true;
}

void GameManager::resultback()
{
	background->Draw();
	backobject->Draw();
	player[0]->ResultAnim();
	anim->SetAnim(Animtion::Anime(16), player[0]->GetModelHandle(), true);
	anim->PlayAnime(player[0]->GetModelHandle());
	player[0]->Draw(false,false);
}

GameManager::~GameManager()
{
	//anim->RemoveAnime(Animtion::Anime(player[0]->ReturnAnim()), player[0]->GetModelHandle());
	for (int i = 0; i < 10; i++)
	{
		delete item[i];
	}
	delete time;
	delete player;
	//delete deltetime;
	delete camera;
	delete score;
	delete anim;
	delete backobject;
	delete light;
	delete interfere;
	delete background;

	DeleteGraph(finishImg);
}