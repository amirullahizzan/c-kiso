#include <iostream>

using namespace std;

//1. �����l�̓���
//2. �����l�̓���
//3. �����l�̓���
//4. �u1.�v�`�u3.�v�œ��͂��ꂽ�l�̒��ł����΂�傫�����l��
//�u�u1.�v�œ��͂��ꂽ�l�A�u2�v�œ��͂��ꂽ�l�A�u3�v�œ��͂��ꂽ�l�̂����A�ł��傫
//�����l�́A�u1.�v�`�u3.�v�œ��͂��ꂽ�l�̒��ł����΂�傫�����l�v
//�Ƃ����`���ŏo��
//�������A�u1.�v�`�u3.�v�œ��͂��ꂽ�l���S�ē������ꍇ�́A�u�S�Ă̐��l���������ł��v
//�Əo��
//�� ���������́A���ꂼ�ꐔ�l���o�͂���܂�

int InputNumber(int num)
{
	cin >> num;
	//cout << num << endl;
	return num;
}

void DisplayBiggestNumber(int num1,int num2,int num3)
{
	if (num1 > num2 && num1 > num3)
	{
		//��ԑ傫�����l���o��
		cout << num1 << endl;
	}
	else if (num2 > num1 && num2 > num3)
	{
		//��ԑ傫�����l���o��
		cout << num2 << endl;
	}
	else if (num3 > num1 && num3 > num2)
	{
		//��ԑ傫�����l���o��
		cout << num3 << endl;
	}
	else if (num1 == num2 && num2 == num3 && num3 == num1)
	{
		cout << "�S�Ă̐��l���������ł�" << endl;
	}
}

int main()
{
	int num1 = 0;
	
	int num2 = 0;
	
	int num3 = 0;

	num1 = InputNumber(num1);
	num2 = InputNumber(num2);
	num3 = InputNumber(num3);
	
	DisplayBiggestNumber(num1,num2,num3);
}