// CheckSrc02d.exeと同じ実行結果になるようにしてください
#include <iostream>
using namespace std;

// 入力された数値を取得する関数
int get_input_num()
{
	int n;
	cout << "数値を入力 > " << flush;
	cin >> n;
	return n;
}

int main()
{
	int num = 0;

	for (int i = 0; i < 5; ++i)
	{
		cout << i << ": " << (i + 1) * 2 << endl;
	}

	system("pause");
	return 0;
}