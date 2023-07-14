#include <iostream>

using namespace std;


string input;

int playerjanken = 0;
int enemyjanken = 0;
bool isDraw = false;
int losecount;
bool isPlayerWin = false;

void DisplayJanKen(int janken)
{
	if (janken == 0)
	{
		cout << "�O�[";
	}
	else if (janken == 1)
	{
		cout << "�`���L";
	}
	else if (janken == 2)
	{
		cout << "�p�[";
	}
	
}

void NotJanken()
{
	cout << "����͂���񂯂�ۂ񂶂�Ȃ���I" << endl;
	cout << "----------------------------" << endl;
}


int PlayerJankenInput(string janken)
{
	if (janken == "�O�[" )
	{
		return 0;
	}
	else if (janken == "�`���L")
	{
		return 1;
	}
	else if (janken == "�p�[")
	{
		return 2;
	}
	else
	{
		NotJanken();
		return 4;
	}

}



void RandomizeEnemy()
{
	enemyjanken = rand() % 3;
}

int main()
{
	srand((unsigned int) time(NULL));

	while (true)
	{
		isPlayerWin = false;

		if (isDraw == false)
		{
			cout << "����񂯂�..." << endl;
		}
		cout << "(�O�[�@���A�`���L�@���A�p�[��I��ł��������B) > ";
		cin >> input;
		if (PlayerJankenInput(input) == 4)
		{
			continue;
		}
	
		cout << "�ۂ�!!!" << endl;
		RandomizeEnemy(); 
		
		cout << endl << "�uPlayer�F " << input << "�v" << " �uNpc�F";
		DisplayJanKen(enemyjanken);
		cout << "�v" << endl << endl;

		if (enemyjanken == PlayerJankenInput(input)+1)
		{
			cout << "���IYou win!" << endl;
			cout << "���܂łɉ��񕉂����̂� : " << losecount << endl;
			isDraw = false;

			break;
		}
		else if (enemyjanken == PlayerJankenInput(input)-1)
		{
			cout << "������IYou lose!�BTry again!" << endl;
			losecount++;
			cout << "�������J�E���^�[ : " << losecount << endl;
			cout << "----------------------------" << endl;
			isDraw = false;

			continue;
		}
		else if (PlayerJankenInput(input) == enemyjanken)
		{
			cout << "DRAW!�B�B�B�������ł�" << endl;
			cout << "----------------------------" << endl;
			isDraw = true;
			continue;
		}
	}
	
	cout << "----------------------------" << endl;




}