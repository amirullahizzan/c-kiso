#include <iostream>
using namespace std;

void Display(int index1, int index2)
{
	cout <<"�ŏ��̗v�f " << "[0] �� " << index1 << endl 
		 <<"�Ō�̗v�f " << "[4] �� " << index2 << endl;
}

int main()
{
	// 1. �����^�̔z��ϐ����T�C�Y5�Ő錾
	int num[5];

	// 2. �u1.�v�Ő錾�����z��ϐ��̍Ō�̗v�f��5����
	num[4] = 5;

	// 3. �u1.�v�Ő錾�����z��ϐ��̍ŏ��̗v�f��7����
	num[0] = 7;

	// 4. �u1.�v�Ő錾�����z��ϐ��̍ŏ��̗v�f�ƍŌ�̗v�f���o��

	Display(num[0], num[4]);

	system("pause");
	return 0;
}