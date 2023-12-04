#include "WinMain.h"
#include "ShapeBase.h"
#include "Box.h"
// ------------------------------------------------
//	図形「四角」クラス（ヘッダーファイル）
//	 円クラスを追従するクラス
// ------------------------------------------------
// ================================
//	初期化処理
// ================================
void Box::init()
{
	pos_ = { WINDOW_W / 2, (float)(H + 10) };
}

// ================================
//	描画処理
// ================================
void Box::render()
{
	DrawBoxAA(pos_.x - W / 2, pos_.y - H / 2,	// 左上
			  pos_.x + W / 2, pos_.y + H / 2,	// 右下
			  SKYBLUE, TRUE);

	// for Debug
	// 四角のpos_は四角の中心座標にしているため、
	// デバッグで中心位置に円を描画
	DrawCircleAA(pos_.x, pos_.y, 5, 64, RED, TRUE);
}

void Box::update()
{
	pos_.x = _circlepos_ptr->x;
}
