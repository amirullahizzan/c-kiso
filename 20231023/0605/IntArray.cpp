#include "IntArray.h"
#include <iostream>

using namespace std;

IntArray::IntArray()
{
	//fill_n �͎w�肵���f�[�^�Ŕz��Ȃǂ𖄂߂�֐��̂悤�Ȃ��̂ł�
	fill_n(m_array, INTARRAY_SIZE, 0);

	cout << "�R���X�g���N�^�[���Ă΂�܂���" << endl;
}

int IntArray::Get(int i)
{
	CheckIndex(i);
	return m_array[i];
}

void IntArray::Set(int i, int value)
{
	CheckIndex(i);
	m_array[i] = value;
}

void IntArray::CheckIndex(int i)
{

	if (0 <= i && i < INTARRAY_SIZE)
	{
		//Index ����
	}
	else
	{
		cout << "�C���f�b�N�X���s���ł��I�I" << endl
		<< "�l�F" << i << endl;
		exit(EXIT_FAILURE);
	}

}
