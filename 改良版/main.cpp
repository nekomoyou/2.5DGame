#include"DxLib.h"
#include<Windows.h>
#include"Player.h"
#include"DelteTime.h"
#include"Item.h"

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
	SetGraphMode(680, 500, 32);

	if (DxLib_Init() == -1)
	{
		return -1;
	}


	//Player* player = new Player();
	DelteTime* deltetime = new DelteTime();
	Item* item = new Item();

	//----------------------------------// 
	//�Q�[���X�^�[�g
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

	//Dx���C�u�����̌�n��
	DxLib_End();

	//�\�t�g�I��
	return 0;
}
