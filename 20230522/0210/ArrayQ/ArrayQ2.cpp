#include <iostream>
using namespace std;

void Display(int index1, int index2)
{
	cout <<"最初の要素 " << "[0] は " << index1 << endl 
		 <<"最後の要素 " << "[4] は " << index2 << endl;
}

int main()
{
	// 1. 整数型の配列変数をサイズ5で宣言
	int num[5];

	// 2. 「1.」で宣言した配列変数の最後の要素に5を代入
	num[4] = 5;

	// 3. 「1.」で宣言した配列変数の最初の要素に7を代入
	num[0] = 7;

	// 4. 「1.」で宣言した配列変数の最初の要素と最後の要素を出力

	Display(num[0], num[4]);

	system("pause");
	return 0;
}