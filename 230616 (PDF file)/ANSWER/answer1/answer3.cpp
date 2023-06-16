#include <iostream>

using namespace std;

//5 つの数値を入力してください。
//ただし、入力された数値がこれまでの入力ですでにされている場合は、すでに入力されてい
//る旨のエラーを出力してください。
//なお、5 つの数値を入力完了した後には、入力された数値をすべて出力してください。


int element[5] = { 97,15,61,34,58 };
int input = 0;

int main()
{
	while (true)
	{
		cout << "要素を数値を入力してください > ";
		cin >> input;
		if (input < 0)
		{
			cout << "エラー。 " << endl << endl;
			continue;
		}
		cout << "0 から" << input;
		if (input > 4)
		{
			input %= 5;
		}
		cout << "番目の要素...[" << input << "]:" << element[input] << endl << endl;

	}

}