#include "Rand2Num.h"
#include <iostream>
using namespace std;

// �R���X�g���N�^
// �����o�ϐ��um_a, m_b�v�Ƀ����_���Ȑ��l��������
Rand2Num::Rand2Num()
{
	m_a = rand() % 10;
	m_b = 10 + rand() % 10;
}

// �����o�ϐ��um_a�v���o�͂��郁���o�֐�
 int Rand2Num::GetA() const
{
	return m_a;
}

// �����o�ϐ��um_b�v���o�͂��郁���o�֐�
 int Rand2Num::GetB() const
{
	return m_b;
}
