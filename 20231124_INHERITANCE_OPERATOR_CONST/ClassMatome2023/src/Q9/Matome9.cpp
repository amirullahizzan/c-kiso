// Q9. エラーを修正しなさい
// 実行サンプル > Q9.exe
// *********************************
//	このファイルを編集しないこと
// *********************************
#include <iostream>
#include <ctime>
#include "ClassP.h"
#include "ClassC1.h"
#include "ClassC2.h"
using namespace std;

// セットと出力をする関数
void SetAndShow(ClassP& c_)
{
	c_.Set();
	c_.Show();
}

int main()
{
	srand((unsigned int)time(NULL));

	ClassC1 c1(10);
	SetAndShow(c1);

	ClassC2 c2(10);
	SetAndShow(c2);

	system("pause");
	return 0;
}