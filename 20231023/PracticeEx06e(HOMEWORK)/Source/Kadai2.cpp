#include <iostream>
#include "Num.h"
#include <ctime>

int main()
{
	srand((unsigned int)time(NULL));

	
	for (int i = 0; i < 50; i++)
	{
	Num num;
	num.set(rand() % 11 + 1, rand() % 11 + 1);
	std::cout << "�傫���ق� :" << num.getMax() << std::endl;
	std::cout << "�������ق� :" << num.getMin() << std::endl;
	}

	system("pause");
	return 0;
}