#pragma once
#include "Base.h"
class Enemy :
	public Base
{
public:
	Enemy();

	void Set();			// m_nを設定する
	void Mul();			// m_nを2倍する
	int Get() const;	// m_nを取得する
};

