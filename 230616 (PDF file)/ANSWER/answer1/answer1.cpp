#include <iostream>

using namespace std;

//5 つの数値を入力してください。
//ただし、入力された数値がこれまでの入力ですでにされている場合は、すでに入力されてい
//る旨のエラーを出力してください。
//なお、5 つの数値を入力完了した後には、入力された数値をすべて出力してください。


int input[5];

int main()
{
	for (int i = 0; i<5; )
	{
		cout << i+1 << " 回目の数値を入力してください > ";
		cin  >> input[i];
		if (i > 0)
		{
			if (input[i] == input[i - 1] || input[i] == input[i - 2] || input[i] == input[i - 3] || input[i] == input[i - 4] || input[i] == input[i - 5])
			{
				cout << "エラー。データはすでに保存されております、別の数値を入力してください " << endl;
				continue;
			}
		}


		i++;


	}
	cout << "==========================" << endl;
	cout << "あなたのデータは :" << endl;
	for (int i = 0; i<5;)
	{
		cout << input[i] <<endl;
		i++;
	}
	

}