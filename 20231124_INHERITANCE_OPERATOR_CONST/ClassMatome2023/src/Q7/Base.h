#pragma once

class Base
{
	int m_n;

public:
	Base();				// コンストラクタ

	void Set();			// m_nを設定する
	void Mul();			// m_nを2倍する
	int Get() const;	// m_nを取得する
};