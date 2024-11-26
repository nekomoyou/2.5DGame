#include"DxLib.h"
#include<Windows.h>
#include"GameManager.h"

//�Q�[���v���O����
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//----------------------------------// 
	//��{�ݒ�
	//----------------------------------// 

	//�E�B���h�E���[�h
	ChangeWindowMode(TRUE);
	//���C�u�����̏�����
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	//�E�B���h�E�Y�T�C�Y�ƃJ���[���[�h
	SetGraphMode(1920, 1080, 32);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//Player* player = new Player();
	GameManager* game = new GameManager();

	//----------------------------------// 
	//�Q�[���X�^�[�g
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

	//Dx���C�u�����̌�n��
	DxLib_End();

	//�\�t�g�I��
	return 0;
}
