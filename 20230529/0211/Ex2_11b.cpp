#include <iostream>

using namespace std;

int numbers[5] = { 0,0,0,0,0 };

int main()
{

cout << "==================================" << endl;
cout << "数値を5つ入力します" << endl;
cout << "その数値をすべて出力" << endl;
cout << "その数値の中から奇数だけを出力" << endl;
cout << "====================================" << endl;

//int input1 = 0;
//int input2 = 0;
//int input3 = 0;
//int input4 = 0;
//int input5 = 0;
//
//cout << "1 回目: 数値入力 > ";
//cin >> input1;
//numbers[0] = input1;
//cout << "2 回目: 数値入力 > ";
//cin >> input2;
//numbers[1] = input2;
//cout << "3 回目: 数値入力 > ";
//cin >> input3;
//numbers[2] = input3;
//cout << "4 回目: 数値入力 > ";
//cin >> input4;
//numbers[3] = input4;
//cout << "5 回目: 数値入力 > ";
//cin >> input5;
//numbers[4] = input5;

int input[5] = { 0,0,0,0,0 };

for (int i = 0; i < 5; i++)
{
	cout << i + 1 << " 回目: 数値入力 > ";
	cin >> input[i];
	numbers[i] = input[i];
}

cout << "---------------------" << endl;

for (int i = 0; i < 5 ; i++)
{

	cout << "[" << i << "]: " << numbers[i] << endl;

}

cout << "---------------------" << endl;
cout << "その中で奇数なのは..." << endl;

int guusuucount = 0; //Even
int kisuucount = 0; //Odd

for (int i = 0; i<5; i++)
{
	//cout << "right now is " << numbers[i] << endl;
	if (numbers[i] % 2 != 0)
	{
	cout << "[" << i << "]: " << numbers[i] << endl;
	kisuucount++;
	}
	else
	{
	guusuucount++;
	}

}

cout << "の" << kisuucount << "個の数値です";

}