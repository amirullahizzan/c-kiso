#include <iostream>
using namespace std;

int input[5];

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "数値を入力してください > ";
		cin >> input[i];

		cout << "入力された数値:    " << input[i] << endl;
			if (input[i] % 2 != 0)
			{
				cout << input[i] << "は奇数です" << endl;
			}
		cout << "---------------------------------" << endl;
	}
	
	system("pause");
	return 0;
}	