// CheckSrc02e.exeと同じ実行結果になるようにしてください
#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		int num;
		cout << "数値を入力 > " << flush;
		cin >> num;

		if (num > 10)
		{

		}
		cout << num << " * 2  = " << num * 2 << endl;
	}

	system("pause");
	return 0;
}