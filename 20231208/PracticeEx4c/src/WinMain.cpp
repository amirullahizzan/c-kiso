#include "WinMain.h"
#include <ctime>

void ExScription()
{
	// キャラクター描画用の規定線の描画
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
	printfDx("Ex04c: ポインタでのターゲティング\n\n");
	printfDx("Aキー        ターゲットの変更（順番）\n");
	printfDx("スペースキー  ターゲットの変更（ランダム）\n");
	printfDx("上下左右キー  ターゲットの移動\n");

}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetWindowSize(WINDOW_W, WINDOW_H);
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	SetBackgroundColor(0, 0, 0);
	SetMainWindowText("Ex04c「ポインタでのターゲティング」");
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
		clsDx();
		GameDraw();

		// ------------------------
		//	Debug用
		// ------------------------
		ExScription();
		ScreenFlip();
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

// 2点間の距離を求める
float getDist(const Pos& pos1, const Pos& pos2)
{
	float x_dist = pos1.x - pos2.x;
	float y_dist = pos1.y - pos2.y;

	return sqrtf(x_dist * x_dist + y_dist * y_dist);
}
