// Q5. �G���[���C��
// ���s�T���v�� > Q5.exe
// *********************************
//	���̃t�@�C����ҏW���Ȃ�����
// *********************************
#include <iostream>
#include <ctime>
#include "Rand2Num.h"
using namespace std;

void ShowAB(const Rand2Num& h_)
{
	cout << "a: " << h_.GetA() << endl;
	cout << "b: " << h_.GetB() << endl;
}

int main()
{
	srand((unsigned int)time(NULL));

	Rand2Num h;
	ShowAB(h);

	system("pause");
	return 0;
}