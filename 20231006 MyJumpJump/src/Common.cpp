#include "WinMain.h"
#include "Common.h"
#include "Player.h"
// 共通ファイル（ヘッダーファイル/Common.h）

// 幅と高さを指定して四角の中心を座標とする四角を描画する関数


void drawBox(const Box& box)
{
	DrawBoxAA(box.x - box.w / 2, box.y - box.h / 2,	// 左上座標
		box.x + box.w / 2, box.y + box.h / 2,	// 右上座標
		box.color,				// 色
			  TRUE);				// 塗りつぶしする
}



