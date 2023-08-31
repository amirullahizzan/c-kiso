#include <iostream>

using namespace std;

void DecideAlphaNum(int& alphanumint)
{
	int alphanumdecider = 0;
	alphanumdecider = rand() % 3;
	switch (alphanumdecider)
	{
		//Number
	case 0: alphanumint = rand() % (58 - 48) + 48;
		break;

		//UPPERCASE
	case 1: alphanumint = rand() % (91 - 65) + 65;
		break;

		//lowercase
	case 2: alphanumint = rand() % (123 - 97) + 97;
		break;
	}
}

void GenerateAlphaNum(int amount)
{
	char output[256] = {};
	int alphanumint = 0;

	for (int i = 0; i < amount; i++)
	{
		DecideAlphaNum(alphanumint);
		output[amount] = alphanumint;
		cout << output[amount];
		//cout << "amo";
	}
}

int main()
{

	srand((unsigned int)(time(NULL)));

	int alphanumcount = 0;

	int linecount = 0;

	linecount = rand() % (11-5) + 5;
	
	for (;linecount > 0;linecount--)
	{
		alphanumcount = rand() % (16 - 5) + 5;
		GenerateAlphaNum(alphanumcount);
		cout << endl;
	}
		
	system("pause");
	return 0;
}
