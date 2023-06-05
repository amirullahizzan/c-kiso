#include "WinMain.h"
#include <ctime>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetWindowSize(WINDOW_W, WINDOW_H);
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	SetBackgroundColor(128, 128, 128);
	SetMainWindowText("�����o�g��");
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
		// ------------------------
		//	Debug�p
		// ------------------------
		GameDraw();
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