// CheckSrc02c.exeと同じ実行結果になるようにしてください
#include <iostream>
using namespace std;

// 入力された数値を取得する関数
int get_input_num()
{
	int n;
	cout << "数値を入力 > " << flush;
	cin >> n;
	return 0;
}

// 引数の2つの数値を足した数を倍にした数を求める関数
int get_answer(int a, int b)
{
	return 0;
}

// 引数の2つの数値を「(a + b) + 2 = 答え」の形で出力する関数
void show_answer(int a, int b)
{
	int answer = 0;
	cout << "(" << a << " + " << b << ") * 2 = " 
		 << answer
		 << endl;
	cout << "--------------------------------------" << endl;
}

int main()
{
	for (int i = 0; i < 2; ++i)
	{
		int num1 = get_input_num();
		int num2 = get_input_num();
		show_answer(num1, num2);
	}

	system("pause");
	return 0;
}