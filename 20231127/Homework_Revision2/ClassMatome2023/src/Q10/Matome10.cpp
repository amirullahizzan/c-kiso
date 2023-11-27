// Q10. 仮想関数
// 実行サンプル > Q10.exe
// *********************************
//	このファイルを編集しないこと
// *********************************
#include <iostream>
#include "PointCardBase.h"
#include "GoldPointCard.h"
#include "SilverPointCard.h"
using namespace std;

int main()
{
	GoldPointCard card1;
	card1 += 500;
	card1.render();

	SilverPointCard card2;
	card2 += 300;
	card2.render();

	system("pause");
	return 0;
}