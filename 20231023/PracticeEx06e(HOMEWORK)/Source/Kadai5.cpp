#include <iostream>
#include "ArrayNum.h"

int main()
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 50; i++)
	{
		ArrayNum arraynum ;
		for (int j = 0; j < arraynum.getSize(); j++)
		{
		arraynum.set(j,rand()%10);
		}
		arraynum.show();
		std::cout << "「" << i << " 番目の要素: " << arraynum.get(i) << "」" << std::endl;;
	}

	system("pause");
	return 0;
}