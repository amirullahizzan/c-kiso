#include <iostream>

using namespace std;

int numbers[5] = { 0,0,0,0,0 };

int main()
{

	cout << "====================================" << endl;
	cout << "���l��5����" << endl;
	cout << "���̐��l����͂��ꂽ�t���ŏo��" << endl;
	cout << "===================================="<<endl;


	
	int input[5] = {0,0,0,0,0};

	for (int i = 0; i < 5 ; i++)
	{
		cout << i+1 <<" ���: ���l���� > ";
		cin >> input[i];
		numbers[i] = input[i];
	}

	//int input1 = 0;
	//int input2 = 0;
	//int input3 = 0;
	//int input4 = 0;
	//int input5 = 0;

	//cout << "1 ���: ���l���� > ";
	//cin >> input1;
	//numbers[0] = input1;
	//cout << "2 ���: ���l���� > ";
	//cin >> input2;
	//numbers[1] = input2;
	//cout << "3 ���: ���l���� > ";
	//cin >> input3;
	//numbers[2] = input3;
	//cout << "4 ���: ���l���� > ";
	//cin >> input4;
	//numbers[3] = input4;
	//cout << "5 ���: ���l���� > ";
	//cin >> input5;
	//numbers[4] = input5;

	for (int i = 5; i > 0; i--)
	{
		cout << i << ": " << numbers[i-1] << endl;
	}

	
}