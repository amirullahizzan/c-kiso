// Q3. ���Z�q�I�[�o�[���[�h
// ���s�T���v�� > Q3.exe
// *********************************
//	���̃t�@�C����ҏW���Ȃ�����
// *********************************
#include <iostream>
#include "Day.h"
using namespace std;

int main()
{
	Day day1(2);
	day1 -= 5;
	cout << day1.get() << endl;

	Day day2(29);
	day2 += 5;
	cout << day2.get() << endl;

	Day day3(45);
	day3 += 2;
	cout << day3.get() << endl;

	system("pause");
	return 0;
}