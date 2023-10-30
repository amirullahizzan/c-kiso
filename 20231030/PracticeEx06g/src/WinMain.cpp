#include "WinMain.h"
#include <ctime>

static bool is_use_window = TRUE;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(is_use_window);
	if (is_use_window)
	{
		SetWindowSize(WINDOW_W, WINDOW_H);
	}
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	SetBackgroundColor(0, 0, 0);
	SetMainWindowText("C++ 基礎");
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	// ---------------
	// 初期化処理
	// ---------------
	SRand((int)time(NULL));
	InputKeyInit();
	InputMouseInit();
	GameInit();


	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ---------------
		// 更新処理
		// ---------------
		InputKeyUpdate();
		InputMouseUpdate();
		GameUpdate();

		// ---------------
		// 描画処理
		// ---------------
		ClearDrawScreen();
		clsDx();
		// ------------------------
		//	Debug用
		// ------------------------
		GameDraw();
		ScreenFlip();
	}

	// ---------------
	// 終了処理
	// ---------------
	InputKeyExit();
	InputMouseExit();
	GameExit();

	DxLib_End();

	return 0;
}
