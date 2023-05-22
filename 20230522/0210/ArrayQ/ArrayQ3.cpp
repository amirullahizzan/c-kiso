#include <iostream>
using namespace std;

int main()
{
	// 1. 整数型の配列変数をサイズ10で宣言
	int num[10]; 
	// int num[]; //can also be written this way
	int index =0;
	// 2. 「1.」で宣言した配列変数の最初から最後の要素まで1～10の数値を代入
	for (num[0] = 1; num[0] < 11; num[0]++)
	{ 
	cout << num[0] << endl;
	}	

	// 3. 「1.」で宣言した配列変数の最初から最後の要素まで出力する



	system("pause");
	return 0;
}