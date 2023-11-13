#include <iostream>
#include "Teacher.h"
// ===============================================
//	先生クラス（ソースファイル）
//	 名前と担当教科のメンバ変数とそれに対する、
//	 getterメンバ関数がある
//	また、setメンバ関数を使用して名前と担当教科名に
//	引数の値をメンバ変数に代入することができる
// ===============================================
// 引数の値をメンバ変数「name_」、「subject_」に代入する
void Teacher::set(const char* name, const char* subject)
{
	name_	 = name;
	subject_ = subject;
}
