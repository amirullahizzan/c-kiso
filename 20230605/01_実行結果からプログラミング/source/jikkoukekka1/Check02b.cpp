#include <iostream>
using namespace std;

int input[5];

int main()
{
	int i = 0;
	
	for (;i<5;i++)
	{
		cout << "数値を入力してください > ";
		cin  >> input[i];

		cout << "入力された数値:    " << input[i]	 << endl
			 << "それを2倍した数値: " << input[i] * 2 << endl
			 << "---------------------------------"  << endl;
	}
	
	system("pause");
	return 0;
}