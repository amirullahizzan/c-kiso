#pragma once

class Rand2Num
{
	int m_a, m_b;	// 二つの数値

public:
	Rand2Num();		// コンストラクタ

	 int GetA() const;		// メンバ変数「m_a」を出力するメンバ関数
	 int GetB() const;		// メンバ変数「m_b」を出力するメンバ関数
};
