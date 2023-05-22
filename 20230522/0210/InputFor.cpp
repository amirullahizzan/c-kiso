#include <iostream>

using namespace std;

int main()
{
	int input;
	cout << "“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ " << endl;
	cin >> input;

	if (input <= 0)
	{
		cout << "“ü—Í‚Å‚«‚Ü‚¹‚ñ";
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