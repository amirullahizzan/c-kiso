#include <iostream>

using namespace std;

int numbers[5] = { 0,0,0,0,0 };

int main()
{
	cout << "========================================" << endl;
	cout << "数値を5つ入力" << endl;
	cout << "入力できる範囲外の数値が入力された場合、" << endl;
	cout << "数値の入力をやり直す" << endl;
	cout << "入力できる範囲は0～1000" << endl;
	cout << "========================================" << endl;

	int input[5] = { 0,0,0,0,0 };

	for (int i = 0; i < 5; )
	{
		cout << i << "  番目の数値入力 > ";
		cin >> input[i];
		if (input[i] < 1000)
		{
		numbers[i] = input[i];
		i++;
		}
		else
		{
		cout << "数値は0以上1000以下です" << endl;
		}
	}

	cout << "--------------------" << endl;
	//print arrays
	for (int i = 0; i < 5; i++)
	{
		cout << "[" << i << "]: " << numbers[i] << endl;
	}

	cout << "--------------------" << endl;

	


}