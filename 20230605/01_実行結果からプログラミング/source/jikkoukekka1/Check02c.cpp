#include <iostream>
using namespace std;

int input[5];

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "���l����͂��Ă������� > ";
		cin >> input[i];

		cout << "���͂��ꂽ���l:    " << input[i] << endl;
			if (input[i] % 2 != 0)
			{
				cout << input[i] << "�͊�ł�" << endl;
			}
		cout << "---------------------------------" << endl;
	}
	
	system("pause");
	return 0;
}	