// Q8. エラーを修正しなさい
// 実行サンプル > Q8.exe
// *********************************
//	このファイルを編集しないこと
// *********************************
#include <iostream>
#include "DoubleNum.h"
using namespace std;

int main()
{
	BaseNum bnum(10);
	bnum.Show();
	cout << "------------" << endl;

	DoubleNum dnum;
	dnum.Show();

	system("pause");
	return 0;
}