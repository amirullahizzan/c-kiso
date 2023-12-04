#include "WinMain.h"
#include "ShapeBase.h"
#include "Circle.h"
// ------------------------------------------------
//	図形「円」クラス（ソースファイル）
//	 左右キーで移動・円を描画するクラス
// ------------------------------------------------
// ================================
//	初期化処理
// ================================
void Circle::init()
{
	pos_ = { WINDOW_W / 2, (float)(WINDOW_H - R - 10) };
}

// ================================
//	更新処理
// ================================
void Circle::update()
{
	if (IsKeyRepeat(KEY_INPUT_LEFT))
	{
		pos_.x -= SPEED;
	}
	if (IsKeyRepeat(KEY_INPUT_RIGHT))
	{
		pos_.x += SPEED;
	}

	fitWindowW();
}

// ================================
//	描画処理
// ================================
void Circle::render()
{
	DrawCircleAA(pos_.x, pos_.y, R, 64, PINK, TRUE);

}

// ================================
//	画面外に行かないようにする（X座標）
// ================================
void Circle::fitWindowW()
{
	if (pos_.x > WINDOW_W - R)
	{
		pos_.x = WINDOW_W - R;
	}
	if (pos_.x < 0 + R)
	{
		pos_.x = 0 + R;
	}
}
