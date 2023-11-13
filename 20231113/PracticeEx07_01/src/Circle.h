#pragma once
#include "Object.h"

// ===============================================
//	円クラス（ヘッダーファイル）
//	 X座標、Y座標、半径のメンバ変数と
//	 それぞれに対するgetterメンバ関数がある
//	 メンバ変数のX座標、Y座標、半径に値を代入する、
//	 setメンバ関数がある
//	 指定された範囲内でランダムな数値を取得する、
//	 getRandNumメンバ関数がある
// ===============================================
class Circle : public Object
{
private:

	int r_ = 0;

public:
	void set(int x, int y, int r);

	// getter
	int getSize() const
	{
		return r_;
	}

};