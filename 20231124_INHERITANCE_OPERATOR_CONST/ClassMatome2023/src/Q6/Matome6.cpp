// Q6. 継承を使って、「InputNumクラス」「RandomNumクラス」を書き換える
// 実行サンプル > Q6.exe
// *********************************
//	このファイルを編集しないこと
// *********************************
#include <iostream>
#include <ctime>
#include "BaseNum.h"
#include "InputNum.h"
#include "RandomNum.h"
using namespace std;

void Sum(BaseNum& num, int loop_num)
{
	int sum = 0;
	for (int i = 0; i < loop_num; ++i) {
		num.Set();
		sum += num.Get();
	}
	cout << "合計... " << sum << endl;
}

int main()
{
	srand((unsigned int)time(NULL));

	const int LOOP_NUM = 5;

	cout << "------------------------------------" << endl;
	cout << "入力した5つ数値の合計を求める" << endl;
	cout << "------------------------------------" << endl;
	InputNum inum;
	Sum(inum, LOOP_NUM);

	cout << "------------------------------------" << endl;
	cout << "ランダムな5つの数値の合計を求める" << endl;
	cout << "------------------------------------" << endl;
	RandomNum rnum;
	Sum(rnum, LOOP_NUM);

	system("pause");
	return 0;
}