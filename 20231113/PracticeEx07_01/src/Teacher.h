#pragma once
#include "Person.h"

// ===============================================
//	先生クラス（ヘッダーファイル）
//	 名前と担当教科のメンバ変数とそれに対する、
//	 getterメンバ関数がある
//	また、setメンバ関数を使用して名前と担当教科名に
//	引数の値をメンバ変数に代入することができる
// ===============================================
class Teacher : public Person
{
private:
	const char* subject_ = nullptr;

public:
	void set(const char* name, const char* subject);

	// getter
	const char* getSubject() const
	{
		return subject_;
	}

};