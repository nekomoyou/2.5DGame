#include"DxLib.h"
#include<Windows.h>
//#include"GameManager.h"
#include"SceneManager.h"
#include"DelteTime.h"

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

	LPCSTR font_path = "img//Buildingsandundertherailwaytracks-Regular.otf"; // 読み込むフォントファイルのパス
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}
	ChangeFont("Buildings and under the railway tracks", DX_CHARSET_DEFAULT);

	//Player* player = new Player();
	//GameManager* game = new GameManager();
	SceneManager* scene = new SceneManager();
	DelteTime* deltatime = new DelteTime();

	//----------------------------------// 
	//ゲームスタート
	//----------------------------------// 
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		//SetLightEnable(false);
		//game->Game();
		//game->Draw();
		
		deltatime->Update();
		scene->Update();
		scene->Draw();
		//deltatime->Draw();

		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
		deltatime->Wait();
	}

	//delete (game);
	delete(scene);

	//Dxライブラリの後始末
	DxLib_End();

	//ソフト終了
	return 0;
}
