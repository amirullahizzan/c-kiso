#pragma once
// =========================================================
//	共通ファイル
// =========================================================
// 構造体
// 座標
struct Pos
{
	float x = 0;
	float y = 0;
};
// 色
struct Color
{
	unsigned int r = 0;
	unsigned int g = 0;
	unsigned int b = 0;
	unsigned int get() const
	{
		return GetColor(r, g, b);
	}
};