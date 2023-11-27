#include "DoubleNum.h"
#include <iostream>
using namespace std;

// コンストラクタ
//	基底クラスのコンストラクタに引数「3」を渡す
//	基底クラスのメンバ変数「m_num」を二倍して、m_num2に代入する
DoubleNum::DoubleNum() : BaseNum(3)
{
	m_num2 = m_num * 2;
}

// 数値を出力するメンバ関数
//	基底クラスの「Showメンバ関数」を呼ぶ
//	メンバ変数「m_num2」を出力する
void DoubleNum::Show()
{
	BaseNum::Show();
	cout << "2倍: " << m_num2 << endl;
}
