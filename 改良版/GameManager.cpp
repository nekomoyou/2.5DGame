#include "GameManager.h"
#include"PlayerBase.h"
#include"Time.h"
#include"Item.h"
#include"DelteTime.h"
#include"Camera.h"
#include"Score.h"

GameManager::GameManager()
    :ModelHandle(-1)
{
    //ModelHandle = MV1LoadModel("3Dƒ‚ƒfƒ‹/Character.mv1");
	//pos = VGet(300, -200, 100);
    player[0] = new PlayerBase("3Dƒ‚ƒfƒ‹/Character.mv1");
	player[1] = new PlayerBase("3Dƒ‚ƒfƒ‹/Character/Rabbit_Bald.mv1");

    time = new Time();
    for (int i = 0; i < 5; i++)
    {
        item[i] = new Item();
    }
    deltetime = new DelteTime();
	camera = new Camera(*player[0]);
	score = new Score();
}

void GameManager::Game()
{
	deltetime->Update();
	for (int i = 0; i < 5; i++)
	{
		item[i]->animtion();
		item[i]->Update();
		item[i]->SetItem();
		//item[i]->Draw();
		item[i]->Collusion(player[1]->Hitpos);
	}
	
	time->Count();
	player[1]->IsMove();
	player[1]->Update();
	player[1]->animtion();
	//player[1]->a();
	ScreenFlip();
	deltetime->Wait();
}

void GameManager::Draw()
{
	for (int i = 0; i < 5; i++)
	{
		item[i]->Draw();
	}
	deltetime->Draw();
	time->Draw();
	score->Draw();
	player[1]->Draw();
}

GameManager::~GameManager()
{
	delete player;
	delete item;
	delete deltetime;
	delete time;
	delete camera;
}