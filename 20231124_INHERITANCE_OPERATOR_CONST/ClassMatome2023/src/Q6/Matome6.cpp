// Q6. �p�����g���āA�uInputNum�N���X�v�uRandomNum�N���X�v������������
// ���s�T���v�� > Q6.exe
// *********************************
//	���̃t�@�C����ҏW���Ȃ�����
// *********************************
#include <iostream>
#include <ctime>
#include "BaseNum.h"
#include "InputNum.h"
#include "RandomNum.h"
using namespace std;

void Sum(BaseNum& num, int loop_num)
{
	int sum = 0;
	for (int i = 0; i < loop_num; ++i) {
		num.Set();
		sum += num.Get();
	}
	cout << "���v... " << sum << endl;
}

int main()
{
	srand((unsigned int)time(NULL));

	const int LOOP_NUM = 5;

	cout << "------------------------------------" << endl;
	cout << "���͂���5���l�̍��v�����߂�" << endl;
	cout << "------------------------------------" << endl;
	InputNum inum;
	Sum(inum, LOOP_NUM);

	cout << "------------------------------------" << endl;
	cout << "�����_����5�̐��l�̍��v�����߂�" << endl;
	cout << "------------------------------------" << endl;
	RandomNum rnum;
	Sum(rnum, LOOP_NUM);

	system("pause");
	return 0;
}