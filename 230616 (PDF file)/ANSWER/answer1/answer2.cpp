#include <iostream>

using namespace std;

//5 �̐��l����͂��Ă��������B
//�������A���͂��ꂽ���l������܂ł̓��͂ł��łɂ���Ă���ꍇ�́A���łɓ��͂���Ă�
//��|�̃G���[���o�͂��Ă��������B
//�Ȃ��A5 �̐��l����͊���������ɂ́A���͂��ꂽ���l�����ׂďo�͂��Ă��������B


int element[5] = {97,15,61,34,58};
int input = 0;

int main()
{
	while(true)
	{
		cout <<  " �v�f�𐔒l����͂��Ă������� > ";
		cin >> input;
		if (input>9 || input < 0)
		{
			cout << "�G���[�B�f�[�^�͂���܂��� " << endl;
			continue;
		}
		else if (input > 4)
		{
			cout << "���̗v�f�ɕۑ�����Ă���f�[�^�� : " << element[0] << endl;
			continue;
		}
		cout << "���̗v�f�ɕۑ�����Ă���f�[�^�� : " << element[input] << endl;
	}

}