#include <iostream>
#include "Student.h"
// ===============================================
//	学生クラス（ヘッダーファイル）
//	 名前と学校名と学年のメンバ変数とそれに対する、
//	 getterメンバ関数がある
//	 また、setメンバ関数を使用して引数の値を
//	 メンバ変数名前と学校名、学年に代入することができる
// ===============================================
// 引数の値をメンバ変数名前と学校名、学年に代入する
void Student::set(const char* name, const char* school, int year)
{
	name_	= name;
	school_ = school;
	year_	= year;
}
