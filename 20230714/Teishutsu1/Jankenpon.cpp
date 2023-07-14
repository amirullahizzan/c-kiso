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
		cout << "グー";
	}
	else if (janken == 1)
	{
		cout << "チョキ";
	}
	else if (janken == 2)
	{
		cout << "パー";
	}
	
}

void NotJanken()
{
	cout << "それはじゃんけんぽんじゃないよ！" << endl;
	cout << "----------------------------" << endl;
}


int PlayerJankenInput(string janken)
{
	if (janken == "グー" )
	{
		return 0;
	}
	else if (janken == "チョキ")
	{
		return 1;
	}
	else if (janken == "パー")
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
			cout << "じゃんけん..." << endl;
		}
		cout << "(グー　か、チョキ　か、パーを選んでください。) > ";
		cin >> input;
		if (PlayerJankenInput(input) == 4)
		{
			continue;
		}
	
		cout << "ぽん!!!" << endl;
		RandomizeEnemy(); 
		
		cout << endl << "「Player： " << input << "」" << " 「Npc：";
		DisplayJanKen(enemyjanken);
		cout << "」" << endl << endl;

		if (enemyjanken == PlayerJankenInput(input)+1)
		{
			cout << "勝つ！You win!" << endl;
			cout << "勝つまでに何回負けたのか : " << losecount << endl;
			isDraw = false;

			break;
		}
		else if (enemyjanken == PlayerJankenInput(input)-1)
		{
			cout << "負ける！You lose!。Try again!" << endl;
			losecount++;
			cout << "負けたカウンター : " << losecount << endl;
			cout << "----------------------------" << endl;
			isDraw = false;

			continue;
		}
		else if (PlayerJankenInput(input) == enemyjanken)
		{
			cout << "DRAW!。。。あいこです" << endl;
			cout << "----------------------------" << endl;
			isDraw = true;
			continue;
		}
	}
	
	cout << "----------------------------" << endl;




}