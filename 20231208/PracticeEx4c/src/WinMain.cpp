#include "WinMain.h"
#include <ctime>

void ExScription()
{
	// �L�����N�^�[�`��p�̋K����̕`��
	//for (int i = 1; i < 4; ++i)
	//{
	//	DrawLine(0 + (WINDOW_W / 4) * i,
	//		0,
	//		0 + (WINDOW_W / 4) * i,
	//		WINDOW_H,
	//		RED);
	//}
	//for (int i = 1; i < 4; ++i)
	//{
	//	DrawLine(0,
	//		0 + (WINDOW_H / 4) * i,
	//		WINDOW_W,
	//		0 + (WINDOW_H / 4) * i,
	//		BLUE);
	//}
	printfDx("Ex04c: �|�C���^�ł̃^�[�Q�e�B���O\n\n");
	printfDx("A�L�[        �^�[�Q�b�g�̕ύX�i���ԁj\n");
	printfDx("�X�y�[�X�L�[  �^�[�Q�b�g�̕ύX�i�����_���j\n");
	printfDx("�㉺���E�L�[  �^�[�Q�b�g�̈ړ�\n");

}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetWindowSize(WINDOW_W, WINDOW_H);
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	SetBackgroundColor(0, 0, 0);
	SetMainWindowText("Ex04c�u�|�C���^�ł̃^�[�Q�e�B���O�v");
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	// ---------------
	// ����������
	// ---------------
	SRand((int)time(NULL));
	InputKeyInit();
	InputPadInit();
	InputMouseInit();
	GameInit();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ---------------
		// �X�V����
		// ---------------
		InputKeyUpdate();
		InputPadUpdate();
		InputMouseUpdate();
		GameUpdate();

		// ---------------
		// �`�揈��
		// ---------------
		ClearDrawScreen();
		clsDx();
		GameDraw();

		// ------------------------
		//	Debug�p
		// ------------------------
		ExScription();
		ScreenFlip();
	}

	// ---------------
	// �I������
	// ---------------
	InputKeyExit();
	InputPadExit();
	InputMouseExit();
	GameExit();

	DxLib_End();

	return 0;
}

// 2�_�Ԃ̋��������߂�
float getDist(const Pos& pos1, const Pos& pos2)
{
	float x_dist = pos1.x - pos2.x;
	float y_dist = pos1.y - pos2.y;

	return sqrtf(x_dist * x_dist + y_dist * y_dist);
}
