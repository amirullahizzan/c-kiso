// Chapter06-08 �R�s�[�R���X�g���N�^
//	�G���[���o�錴����˂��~�߂Ă�������
#include "PackNumber.h"
#include <iostream>
#include <ctime>
using namespace std;

void ShowNumbers(const PackNumber& pack)
{
	for (int i = 0; i < pack.SIZE; ++i)
	{
		printf_s("[%2d]: %2d\n", i, pack.Get(i));
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	PackNumber pack1(10);
	for (int i = 0; i < pack1.SIZE; ++i)
	{
		pack1.Set(i, rand() % 10 + 1);
	}

	ShowNumbers(pack1);

}