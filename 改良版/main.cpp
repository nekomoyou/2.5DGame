#include"DxLib.h"
#include<Windows.h>
#include"GameManager.h"

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
	SetGraphMode(1920, 1080, 32);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//Player* player = new Player();
	GameManager* game = new GameManager();

	//----------------------------------// 
	//ゲームスタート
	//----------------------------------// 
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		game->Draw();
		game->Game();
		
		if (CheckHitKey(KEY_INPUT_A))
		{
			game->Reset();
		}

		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	delete (game);

	//Dxライブラリの後始末
	DxLib_End();

	//ソフト終了
	return 0;
}
