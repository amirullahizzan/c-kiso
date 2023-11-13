#pragma once
#include "Object.h"
// ===============================================
//	正方形クラス（ヘッダーファイル）
//	 X座標、Y座標、幅、高さのメンバ変数と
//	 それぞれに対するgetterメンバ関数がある
//	 メンバ変数のX座標、Y座標、幅、高さに引数の値を代入する、
//	 setメンバ関数がある
//	 指定された範囲内でランダムな数値を取得する、
//	 getRandNumメンバ関数がある
// ===============================================
class Square : public Object
{
private:

	int w_ = 0;
	int h_ = 0;

public:
	void set(int x, int y, int w);

	// getter

	int getSize() const
	{
		// 正方形なので幅・高さどちらを返しても同じ
		return w_;
	}


};