#pragma once
// ------------------------
//	構造体
// ------------------------
// 座標用
struct Pos
{
	int x = 0, y = 0;
};
// ------------------------
//	列挙体
// ------------------------
// 向き用
enum DIR
{
	DOWN = 0,
	LEFT, RIGHT, UP,
	DIR_MAX
};
