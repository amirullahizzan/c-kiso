#include <iostream>
using namespace std;

int input[5];

int main()
{
	int i = 0;
	
	for (;i<5;i++)
	{
		cout << "���l����͂��Ă������� > ";
		cin  >> input[i];

		cout << "���͂��ꂽ���l:    " << input[i]	 << endl
			 << "�����2�{�������l: " << input[i] * 2 << endl
			 << "---------------------------------"  << endl;
	}
	
	system("pause");
	return 0;
}