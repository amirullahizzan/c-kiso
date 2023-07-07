#include "mondai1.h"
#include <iostream>

using namespace std;


int main()
{
	srand((unsigned int)time(NULL));

	for (int i = 0;i<3;i++)
	{
		cout << getRand(3) << endl;
	}
}


int getRand(int x)
{
	return rand() % (x+1);
}