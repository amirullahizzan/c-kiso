#include <iostream>

using namespace std;

int main()
{
	int input;
	cout << "���͂��Ă������� " << endl;
	cin >> input;

	if (input <= 0)
	{
		cout << "���͂ł��܂���";
		return 0;
	}

	for(;input > 0;)
	{
		cout << "*";
		return 0;
	}

	system("pause");
	return 0;
}