#include "WinMain.h"
#include <ctime>

namespace 
{
	const int LINE_THICK = 1;
	void renderDebug()
	{
		for(int i = 1; i < 3; ++i)
		{
			DrawLine(WINDOW_W / 3 * i, 0,
					 WINDOW_W / 3 * i, WINDOW_H,
					 RED, LINE_THICK);
		}

		for(int i = 0; i < 3; ++i)
		{
			DrawLine(WINDOW_W / 3 * i + (WINDOW_W / 3 / 2), 0,
					 WINDOW_W / 3 * i + (WINDOW_W / 3 / 2), WINDOW_H,
					 BLUE, LINE_THICK);
		}
		DrawLine(0, WINDOW_H / 2, WINDOW_W, WINDOW_H / 2, RED, LINE_THICK);
	}
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetWindowSize(WINDOW_W, WINDOW_H);
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	SetBackgroundColor(0, 0, 0);
	SetMainWindowText("PracticeEx07-02");
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

		ClearDrawScreen();
		clsDx();
		// ------------------------
		//	Debug用
		// ------------------------
		renderDebug();
		// ---------------
		// 描画処理
		// ---------------
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
