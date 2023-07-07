#include "mondai1.h"
#include <iostream>

using namespace std;


int main()
{
	srand((unsigned int)time(NULL));


	cout << getRand(1);
}

int getRand(int x)
{
	return rand() % (x + 1);
}