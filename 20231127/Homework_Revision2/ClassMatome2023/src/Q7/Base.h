#pragma once

class Base
{
protected:
	int m_n;

public:
	Base();				// �R���X�g���N�^

	virtual void Set();			// m_n��ݒ肷��
	void Mul();			// m_n��2�{����
	int Get() const;	// m_n���擾����
};