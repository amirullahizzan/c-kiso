#pragma once
#include "Base.h"

class Player : public Base
{

public:
	Player();

	void Set() override;			// m_nを設定する
	void Mul();			// m_nを2倍する
	int Get() const;	// m_nを取得する
};

