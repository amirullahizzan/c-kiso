#pragma once
#include "Base.h"
class Enemy :
	public Base
{
public:
	Enemy();

	void Set();			// m_n��ݒ肷��
	void Mul();			// m_n��2�{����
	int Get() const;	// m_n���擾����
};

