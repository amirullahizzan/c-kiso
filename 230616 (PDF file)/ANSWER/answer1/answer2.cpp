#include <iostream>

using namespace std;

//5 つの数値を入力してください。
//ただし、入力された数値がこれまでの入力ですでにされている場合は、すでに入力されてい
//る旨のエラーを出力してください。
//なお、5 つの数値を入力完了した後には、入力された数値をすべて出力してください。


int element[5] = {97,15,61,34,58};
int input = 0;

int main()
{
	while(true)
	{
		cout <<  " 要素を数値を入力してください > ";
		cin >> input;
		if (input>9 || input < 0)
		{
			cout << "エラー。データはありません " << endl;
			continue;
		}
		else if (input > 4)
		{
			cout << "この要素に保存されているデータは : " << element[0] << endl;
			continue;
		}
		cout << "この要素に保存されているデータは : " << element[input] << endl;
	}

}