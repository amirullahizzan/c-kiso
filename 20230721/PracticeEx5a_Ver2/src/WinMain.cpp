#include "WinMain.h"
#include <chrono>
//#include <ctime>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	SetBackgroundColor(0, 0, 0);
	SetMainWindowText("C++ Šî‘b");
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	// ---------------
	// ‰Šú‰»ˆ—
	// ---------------
	SRand((int)time(NULL));
	InputKeyInit();
	InputMouseInit();
	InputPadInit();
	GameInit();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ---------------
		// XVˆ—
		// ---------------
		InputKeyUpdate();
		InputPadUpdate();
		GameUpdate();

		// ---------------
		// •`‰æˆ—
		// ---------------
		ClearDrawScreen();
		clsDx();
		GameDraw();
		ScreenFlip();
	}

	// ---------------
	// I—¹ˆ—
	// ---------------
	InputKeyExit();
	InputPadExit();
	GameExit();

	DxLib_End();

	return 0;
}
