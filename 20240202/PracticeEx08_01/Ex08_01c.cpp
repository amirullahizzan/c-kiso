#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	cout << "計算式:";
	string inputstr;
	getline(cin, inputstr);
	cout << inputstr << endl;
	if (stoi(inputstr) < 0)
	{
		cout << "ERROR: 計算できない演算子が含まれています";
	}
	else
	{
		stringstream inputSstr (inputstr);
		int x, y;

		inputSstr >> x >> y;
		cout << "=" << x + y; //結果
	}
	
	
	cout << "\nプログラムを終了します..." << endl;

	system("pause");
	return 0;
}