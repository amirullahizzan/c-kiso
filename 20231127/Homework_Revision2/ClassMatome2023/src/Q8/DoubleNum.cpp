#include "DoubleNum.h"
#include <iostream>
using namespace std;

// �R���X�g���N�^
//	���N���X�̃R���X�g���N�^�Ɉ����u3�v��n��
//	���N���X�̃����o�ϐ��um_num�v���{���āAm_num2�ɑ������
DoubleNum::DoubleNum() : BaseNum(3)
{
	m_num2 = m_num * 2;
}

// ���l���o�͂��郁���o�֐�
//	���N���X�́uShow�����o�֐��v���Ă�
//	�����o�ϐ��um_num2�v���o�͂���
void DoubleNum::Show()
{
	BaseNum::Show();
	cout << "2�{: " << m_num2 << endl;
}
