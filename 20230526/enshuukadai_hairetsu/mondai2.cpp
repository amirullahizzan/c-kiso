#include <iostream>

using namespace std;

int hairetsu[5] = {5,12,4,7,2};
int input;
int i = 0;

int main()
{
	for (int x = 0;x<5;x++)
	{

	
		cout << "Input Data " << endl;
		cin >> i;
		cout << endl;
		if (i > 4 || i <0)
		{
			cout << "指定された番号に誤りがあります" << endl;
		}
		else
		{
			cout << i << " 番目の要素は " << hairetsu[i] << " です。" << endl;
		}
		cout << "=======================" << endl;
	}

}