#include "BaseNum.h"
#include <iostream>
#include "BaseNum.h"
using namespace std;

// 引数付きコンストラクタ
// メンバ変数「m_num」を引数で渡された値で初期化する
BaseNum::BaseNum(int num_) :m_num(num_)
{

}

// 数値を出力するメンバ関数
// メンバ変数「m_num」を出力する
void BaseNum::Show()
{
	cout << "数値: " << m_num << endl;
}
