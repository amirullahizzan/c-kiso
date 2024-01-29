#include "WinMain.h"
#include <ctime>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetWindowSize(WINDOW_W, WINDOW_H);
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
	InputPadInit();
	InputMouseInit();
	GameInit();


	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		clsDx();

		// ---------------
		// 更新処理
		// ---------------
		InputKeyUpdate();
		InputPadUpdate();
		InputMouseUpdate();
		GameUpdate();

		// ---------------
		// 描画処理
		// ---------------
		ClearDrawScreen();
		GameDraw();
		ScreenFlip();

		// ------------------------
		//	FPS用
		// ------------------------

	}

	// ---------------
	// 終了処理
	// ---------------
	InputKeyExit();
	InputPadExit();
	InputMouseExit();
	GameExit();

	DxLib_End();

	return 0;
}

//	X座標を画面中心でフォントを描画
void DrawCenterString(int y, const char* str, int size, unsigned int color)
{
	int org_font_size = GetFontSize();
	SetFontSize(size);
	int font_w = GetDrawStringWidth(str, (int)strlenDx(str));
	DrawString(WINDOW_W / 2 - font_w / 2, y, str, color);
	SetFontSize(org_font_size);
}
// 2点間の距離を求める
float getDist(const Pos& pos1, const Pos& pos2)
{
	float x_dist = pos1.x - pos2.x;
	float y_dist = pos1.y - pos2.y;

	return sqrtf(x_dist * x_dist + y_dist * y_dist);
}
