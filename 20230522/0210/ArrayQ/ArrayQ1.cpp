#include <iostream>
using namespace std;

void Display(int num, int index)
{
	cout <<"�C���f�b�N�X " << index << " ��value�� " << num << endl;
}

int main()
{
	// 1. �����^�̔z��ϐ����T�C�Y10�Ő錾
	int num[10];

	// 2. �u1.�v�Ő錾�����z��ϐ���0�Ԗڂ̗v�f��3����
	num[0] = 3;

	int index = 0;

	// 3. �u1.�v�Ő錾�����z��ϐ���0�Ԗڂ̗v�f���o��
	
	Display(num[0],index);

	system("pause");
	return 0;
}