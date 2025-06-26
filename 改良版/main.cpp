#include"DxLib.h"
#include<Windows.h>
//#include"GameManager.h"
#include"SceneManager.h"
#include"DelteTime.h"

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

	LPCSTR font_path = "img//Buildingsandundertherailwaytracks-Regular.otf"; // �ǂݍ��ރt�H���g�t�@�C���̃p�X
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
	}
	ChangeFont("Buildings and under the railway tracks", DX_CHARSET_DEFAULT);

	//Player* player = new Player();
	//GameManager* game = new GameManager();
	SceneManager* scene = new SceneManager();
	DelteTime* deltatime = new DelteTime();

	//----------------------------------// 
	//�Q�[���X�^�[�g
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

	//Dx���C�u�����̌�n��
	DxLib_End();

	//�\�t�g�I��
	return 0;
}
