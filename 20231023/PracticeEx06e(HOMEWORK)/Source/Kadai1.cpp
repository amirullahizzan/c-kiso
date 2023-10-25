#include <iostream>
#include "DoubleNum.h"
#include <ctime>

int main()
{

	srand((unsigned int)time(NULL));

	for (int i = 0;i < 5;i++)
	{
		DoubleNum doublenum;
		doublenum.set(rand() % 11 + 1);
		doublenum.show();
	}

}