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

GameManager::GameManager()
{
    player[0] = new PlayerBase("3Dƒ‚ƒfƒ‹/Character.mv1");
	//player[1] = new PlayerBase("3Dƒ‚ƒfƒ‹/Character/Rabbit_Bald.mv1");

    time = new Time();
    for (int i = 0; i < 6; i++)
    {
        item[i] = new Item();
    }
    deltetime = new DelteTime();
	camera = new Camera(*player[0]);
	score = new Score();
	anim = new Animtion();
	itemtimer = new ItemTimer();
	backobject = new BackObject();
	interfere = new Interfere();
	background = new BackGround();
}

void GameManager::Game()
{
	deltetime->Update();
	anim->SetAnim(Animtion::Anime(player[0]->ReturnAnim()), player[0]->GetModelHandle());
	time->Count();
	itemtimer->GetTime(time->ReturnTime());
	itemtimer->showItem();
	interfere->Update();
	interfere->Animtion();
	backobject->SetObj();
	background->Update(time->ReturnTime());

	if (time->ReturnStaet() < 0)
	{
		for (int i = 0; i < itemtimer->ItemSet(); i++)
		{
			item[i]->animtion();
			item[i]->Update();
			item[i]->SetItem();
			item[i]->Collusion(player[0]->ReturnHitpos());
			if (item[i]->returnflg())
			{
				score->ScoreAdd(item[i]->returnNum());
			}
		}
		player[0]->IsMove();
		player[0]->Update();
	}
	camera->Update();
	anim->PlayAnime(player[0]->GetModelHandle());
	deltetime->Wait();
}

void GameManager::Draw()
{
	background->Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	backobject->Draw();
	for (int i = 0; i < itemtimer->ItemSet(); i++)
	{
		item[i]->Draw();
	}
	time->Draw();
	deltetime->Draw();
	score->Draw();
	player[0]->Draw();
	interfere->Draw();
	ScreenFlip();
}

void GameManager::Reset()
{
	player[0]->Init();
	time->Init();
	score->Init();
	for (int i = 0; i < 6; i++)
	{
		item[i]->Init();
	}
	itemtimer->Init();
}

GameManager::~GameManager()
{
	//anim->RemoveAnime(Animtion::Anime(player[0]->ReturnAnim()), player[0]->GetModelHandle());
	delete player;
	delete item;
	delete deltetime;
	delete time;
	delete camera;
	delete score;
	delete anim;
	delete backobject;
}