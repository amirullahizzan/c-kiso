#include <iostream>
#include "RandomNum.h"
#include <ctime>

int main()
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 100; i++)
	{
		RandomNum randomnum(rand() % 10, rand() % 11 + rand() % 10);
		randomnum.set();
		randomnum.show();
	}

	system("pause");
	return 0;
}