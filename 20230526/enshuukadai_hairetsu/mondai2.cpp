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
			cout << "�w�肳�ꂽ�ԍ��Ɍ�肪����܂�" << endl;
		}
		else
		{
			cout << i << " �Ԗڂ̗v�f�� " << hairetsu[i] << " �ł��B" << endl;
		}
		cout << "=======================" << endl;
	}

}