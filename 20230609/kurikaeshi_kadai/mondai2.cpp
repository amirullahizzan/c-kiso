
#include <iostream>
using namespace std;


int input[3];

void InputDigit()
{
	for (int i = 0; i < 3;)
	{
	cout << "�ꌅ�̐�����3����͂��Ă������� > " << flush;
	cin >> input[i];
	cout << endl;
	if (input[i] > 9)
	{
		continue;
	}
	i++;
	}
}

void DisplayDigits()
{
	cout << "���Ȃ��̐��� :" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i+1 << "��� �� " << input[i] << endl;
	}
}

int main()
{
	InputDigit();
	DisplayDigits();
}