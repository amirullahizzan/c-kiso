#include <iostream>


using namespace std;

int input = 1;
char chr = 97;

void UserInput()
{
	cout << "�ړ��������(0 �I��) > ";
	cin >> input;
}
void DetectOverload()
{
	if (input > 25)
	{
		input %= 26;
	}
	chr += (int)input;
}

int main()
{
	while(true)
	{
		UserInput();
	if (input == 0)
	{
		break;
	}
	cout << "a ���� " << input << " �ړ�����ƁA";
	DetectOverload();
	
	
	cout << chr << " �ł��B\n";

	//reset
	chr = 97;
	}
	cout << "�v���O�����I���B";
}