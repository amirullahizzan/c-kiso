#include <iostream>

using namespace std;

int main()
{
	int input;
	cout << "入力してください " << endl;
	cin >> input;

	if (input <= 0)
	{
		cout << "入力できません";
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