#include"DxLib.h"
#include<Windows.h>
#include"Player.h"
#include"DelteTime.h"
#include"Item.h"

//ゲームプログラム
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//----------------------------------// 
	//基本設定
	//----------------------------------// 

	//ウィンドウモード
	ChangeWindowMode(TRUE);
	//ライブラリの初期化
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	//ウィンドウズサイズとカラーモード
	SetGraphMode(680, 500, 32);

	if (DxLib_Init() == -1)
	{
		return -1;
	}


	//Player* player = new Player();
	DelteTime* deltetime = new DelteTime();
	Item* item = new Item();

	//----------------------------------// 
	//ゲームスタート
	//----------------------------------// 
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		deltetime->Update();
		deltetime->Draw();
		item->animtion();
		item->Draw();
		ScreenFlip();
		deltetime->Wait();
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	//Dxライブラリの後始末
	DxLib_End();

	//ソフト終了
	return 0;
}
