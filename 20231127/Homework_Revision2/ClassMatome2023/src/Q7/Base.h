#pragma once

class Base
{
protected:
	int m_n;

public:
	Base();				// コンストラクタ

	virtual void Set();			// m_nを設定する
	void Mul();			// m_nを2倍する
	int Get() const;	// m_nを取得する
};