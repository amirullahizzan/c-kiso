#include <iostream>
#include "InputNum.h"
#include <ctime>

int main()
{
	srand((unsigned int)time(NULL));

	for (int i = 0;i < 5;i++)
	{
		int randmin = rand() % 10;
		int randmax = randmin+rand() % 51+1;
		std::cout << randmin << "," << randmax << std::endl;
		InputNum inputnum(randmin,randmax);
		inputnum.set();
		std::cout << "“ü—Í‚³‚ê‚½”’l:" << inputnum.get() << std::endl;

	}

	system("pause");
	return 0;
}