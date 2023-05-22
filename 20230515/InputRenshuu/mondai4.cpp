#include <iostream>

using namespace std;

//1. 整数値の入力
//2. 整数値の入力
//3. 整数値の入力
//4. 「1.」～「3.」で入力された値の中でいちばん大きい数値を
//「「1.」で入力された値、「2」で入力された値、「3」で入力された値のうち、最も大き
//い数値は、「1.」～「3.」で入力された値の中でいちばん大きい数値」
//という形式で出力
//ただし、「1.」～「3.」で入力された値が全て等しい場合は、「全ての数値が等しいです」
//と出力
//※ 下線部分は、それぞれ数値が出力されます

int InputNumber(int num)
{
	cin >> num;
	//cout << num << endl;
	return num;
}

void DisplayBiggestNumber(int num1,int num2,int num3)
{
	if (num1 > num2 && num1 > num3)
	{
		//一番大きい数値を出力
		cout << num1 << endl;
	}
	else if (num2 > num1 && num2 > num3)
	{
		//一番大きい数値を出力
		cout << num2 << endl;
	}
	else if (num3 > num1 && num3 > num2)
	{
		//一番大きい数値を出力
		cout << num3 << endl;
	}
	else if (num1 == num2 && num2 == num3 && num3 == num1)
	{
		cout << "全ての数値が等しいです" << endl;
	}
}

int main()
{
	int num1 = 0;
	
	int num2 = 0;
	
	int num3 = 0;

	num1 = InputNumber(num1);
	num2 = InputNumber(num2);
	num3 = InputNumber(num3);
	
	DisplayBiggestNumber(num1,num2,num3);
}