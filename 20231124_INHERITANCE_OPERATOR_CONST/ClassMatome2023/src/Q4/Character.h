#pragma once
class Character
{
public:
	const char* m_str;
	Character(const char* str_);	// コンストラクタ
	
	bool Search(char c) const;		// 引数で指定された文字が文字列にあるかどうか
	void Show() const;				// 文字列を出力
};

