// Q9. �G���[���C�����Ȃ���
// ���s�T���v�� > Q9.exe
// *********************************
//	���̃t�@�C����ҏW���Ȃ�����
// *********************************
#include <iostream>
#include <ctime>
#include "ClassP.h"
#include "ClassC1.h"
#include "ClassC2.h"
using namespace std;

// �Z�b�g�Əo�͂�����֐�
void SetAndShow(ClassP& c_)
{
	c_.Set();
	c_.Show();
}

int main()
{
	srand((unsigned int)time(NULL));

	ClassC1 c1(10);
	SetAndShow(c1);

	ClassC2 c2(10);
	SetAndShow(c2);

	system("pause");
	return 0;
}