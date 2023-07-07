#include "mondai1.h"
#include <iostream>

using namespace std;

bool goodluck = false;
bool badluck = false;
bool normalluck = false;

int main()
{
	srand((unsigned int)time(NULL));

	while (true)
	{
	Omikuji(getRand(3));
	if (goodluck == true && normalluck == true && badluck == true)
	{
		break;
	}

	}
	cout << endl << "end task" << endl;

}

int getRand(int x)
{
	return rand() % (x + 1);
}

void Omikuji(int x)
{
	switch (x)
	{
	case 1:cout << "‘å‹g" << endl;
		goodluck = true;
		break;
	case 2:cout << "‹g" << endl;
		normalluck = true;
		break;
	case 3:cout << "‘å‹¥" << endl;
		badluck = true;
		break;
	}
}