#include <iostream>

using namespace std;

//5 �̐��l����͂��Ă��������B
//�������A���͂��ꂽ���l������܂ł̓��͂ł��łɂ���Ă���ꍇ�́A���łɓ��͂���Ă�
//��|�̃G���[���o�͂��Ă��������B
//�Ȃ��A5 �̐��l����͊���������ɂ́A���͂��ꂽ���l�����ׂďo�͂��Ă��������B


int input[5];

int main()
{
	for (int i = 0; i<5; )
	{
		cout << i+1 << " ��ڂ̐��l����͂��Ă������� > ";
		cin  >> input[i];
		if (i > 0)
		{
			if (input[i] == input[i - 1] || input[i] == input[i - 2] || input[i] == input[i - 3] || input[i] == input[i - 4] || input[i] == input[i - 5])
			{
				cout << "�G���[�B�f�[�^�͂��łɕۑ�����Ă���܂��A�ʂ̐��l����͂��Ă������� " << endl;
				continue;
			}
		}


		i++;


	}
	cout << "==========================" << endl;
	cout << "���Ȃ��̃f�[�^�� :" << endl;
	for (int i = 0; i<5;)
	{
		cout << input[i] <<endl;
		i++;
	}
	

}