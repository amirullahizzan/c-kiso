#include "WinMain.h"
#include <ctime>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetWindowSize(WINDOW_W, WINDOW_H);
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	SetBackgroundColor(128, 128, 128);
	SetMainWindowText("PracticeEx07f");
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	// ---------------
	// ����������
	// ---------------
	SRand((int)time(NULL));
	InputKeyInit();
	InputMouseInit();
	GameInit();


	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ---------------
		// �X�V����
		// ---------------
		InputKeyUpdate();
		InputMouseUpdate();
		GameUpdate();

		ClearDrawScreen();
		clsDx();
		// ------------------------
		//	Debug�p
		// ------------------------
		// ---------------
		// �`�揈��
		// ---------------
		GameDraw();
		ScreenFlip();
	}

	// ---------------
	// �I������
	// ---------------
	InputKeyExit();
	InputMouseExit();
	GameExit();

	DxLib_End();

	return 0;
}
//	X���W����ʒ��S�Ńt�H���g��`��
void DrawCenterString(int y, const char* str, int size, unsigned int color)
{
	int org_font_size = GetFontSize();
	SetFontSize(size);
	int font_w = GetDrawStringWidth(str, (int)strlenDx(str));
	DrawString(WINDOW_W / 2 - font_w / 2, y, str, color);
	SetFontSize(org_font_size);
}
