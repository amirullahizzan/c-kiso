#include <iostream>

using namespace std;

int numbers[5] = { 0,0,0,0,0 };

int main()
{

	cout << "====================================" << endl;
	cout << "数値を5つ入力" << endl;
	cout << "その数値を入力された逆順で出力" << endl;
	cout << "===================================="<<endl;


	
	int input[5] = {0,0,0,0,0};

	for (int i = 0; i < 5 ; i++)
	{
		cout << i+1 <<" 回目: 数値入力 > ";
		cin >> input[i];
		numbers[i] = input[i];
	}

	//int input1 = 0;
	//int input2 = 0;
	//int input3 = 0;
	//int input4 = 0;
	//int input5 = 0;

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

	for (int i = 5; i > 0; i--)
	{
		cout << i << ": " << numbers[i-1] << endl;
	}

	
}