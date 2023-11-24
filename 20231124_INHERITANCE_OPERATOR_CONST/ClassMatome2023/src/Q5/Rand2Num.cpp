#include "Rand2Num.h"
#include <iostream>
using namespace std;

// コンストラクタ
// メンバ変数「m_a, m_b」にランダムな数値を代入する
Rand2Num::Rand2Num()
{
	m_a = rand() % 10;
	m_b = 10 + rand() % 10;
}

// メンバ変数「m_a」を出力するメンバ関数
 int Rand2Num::GetA() const
{
	return m_a;
}

// メンバ変数「m_b」を出力するメンバ関数
 int Rand2Num::GetB() const
{
	return m_b;
}
