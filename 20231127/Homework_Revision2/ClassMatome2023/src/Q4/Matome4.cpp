// Q4. 基本的なクラスの作り方
// 実行サンプル > Q4.exe
// *********************************
//	このファイルを編集しないこと
// *********************************
#include <iostream>
#include "Character.h"
using namespace std;

int main()
{
	const char* SAMPLE = "Hello World!!";
	const char  SEARCH = 'o';
	Character ch(SAMPLE);

	ch.Show();
	cout << " の中には " << SEARCH << " が" 
		 << ((ch.Search(SEARCH)) ? "あります" : "ありません") << endl;

	system("pause");
	return 0;
}