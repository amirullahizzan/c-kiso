#pragma once
#include "Person.h"
// ===============================================
//	学生クラス（ヘッダーファイル）
//	 名前と学校名と学年のメンバ変数とそれに対する、
//	 getterメンバ関数がある
//	 また、setメンバ関数を使用して引数の値を
//	 メンバ変数名前と学校名、学年に代入することができる
// ===============================================
class Student : public Person
{
private:
	const char* school_ = nullptr;
	int			year_	= 0;

public:
	void set(const char* name, const char* school, int year);

	// getter
	const char* getSchool() const
	{
		return school_;
	}
	int getYear() const
	{
		return year_;
	}

};