#include <iostream>

using namespace std;

int numbers[5] = { 0,0,0,0,0 };

int main()
{
	cout << "========================================" << endl;
	cout << "���l��5����" << endl;
	cout << "���͂ł���͈͊O�̐��l�����͂��ꂽ�ꍇ�A" << endl;
	cout << "���l�̓��͂���蒼��" << endl;
	cout << "���͂ł���͈͂�0�`1000" << endl;
	cout << "========================================" << endl;

	int input[5] = { 0,0,0,0,0 };

	for (int i = 0; i < 5; )
	{
		cout << i << "  �Ԗڂ̐��l���� > ";
		cin >> input[i];
		if (input[i] < 1000)
		{
		numbers[i] = input[i];
		i++;
		}
		else
		{
		cout << "���l��0�ȏ�1000�ȉ��ł�" << endl;
		}
	}

	cout << "--------------------" << endl;
	//print arrays
	for (int i = 0; i < 5; i++)
	{
		cout << "[" << i << "]: " << numbers[i] << endl;
	}

	cout << "--------------------" << endl;

	


}