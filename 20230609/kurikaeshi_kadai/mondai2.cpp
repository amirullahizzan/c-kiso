
#include <iostream>
using namespace std;


int input[3];

void InputDigit()
{
	for (int i = 0; i < 3;)
	{
	cout << "一桁の数字を3回入力してください > " << flush;
	cin >> input[i];
	cout << endl;
	if (input[i] > 9)
	{
		continue;
	}
	i++;
	}
}

void DisplayDigits()
{
	cout << "あなたの数字 :" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i+1 << "回目 は " << input[i] << endl;
	}
}

int main()
{
	InputDigit();
	DisplayDigits();
}