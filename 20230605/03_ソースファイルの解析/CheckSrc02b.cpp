// CheckSrc02b.exeと同じ実行結果になるようにしてください
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
	int a = 0;	... ひとつめの入力
	int b = 0;	... ふたつめの入力

	cout << "数値1: " << a << " / 数値2: " << b << endl;
	cout << a << " + " << b << " = " << (a + b) << endl;
	cout << a << " - " << b << " = " << (a - b) << endl;
	cout << a << " * " << b << " = " << (a * b) << endl;
	cout << a << " / " << b << " = " << (a / b)
		 << " ...あまり"		<< (a % b) << endl;

	system("pause");
	return 0;
}
