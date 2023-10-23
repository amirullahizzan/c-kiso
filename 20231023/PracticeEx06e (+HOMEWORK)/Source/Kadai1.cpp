#include <iostream>
#include "DoubleNum.h"
#include <ctime>

int main()
{
	DoubleNum doublenum (0);

	srand((unsigned int)time(NULL));

	for (int i = 0;i < 5;i++)
	{
		doublenum.set(rand() % 11 + 1);
		doublenum.show();
	}

}