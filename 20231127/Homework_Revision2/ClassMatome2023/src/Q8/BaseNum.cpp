#include "BaseNum.h"
#include <iostream>
#include "BaseNum.h"
using namespace std;

// �����t���R���X�g���N�^
// �����o�ϐ��um_num�v�������œn���ꂽ�l�ŏ���������
BaseNum::BaseNum(int num_) :m_num(num_)
{

}

// ���l���o�͂��郁���o�֐�
// �����o�ϐ��um_num�v���o�͂���
void BaseNum::Show()
{
	cout << "���l: " << m_num << endl;
}
