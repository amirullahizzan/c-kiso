#include <iostream>
using namespace std;

void Display(int num, int index)
{
	cout <<"インデックス " << index << " のvalueは " << num << endl;
}

int main()
{
	// 1. 整数型の配列変数をサイズ10で宣言
	int num[10];

	// 2. 「1.」で宣言した配列変数の0番目の要素に3を代入
	num[0] = 3;

	int index = 0;

	// 3. 「1.」で宣言した配列変数の0番目の要素を出力
	
	Display(num[0],index);

	system("pause");
	return 0;
}