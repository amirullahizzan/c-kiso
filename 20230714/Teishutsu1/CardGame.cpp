#include <iostream>

using namespace std;

char input;

int playercard = 0;
int enemycard = 0;

int DrawCard()
{
	const int setcards = rand() % (14 - 1) + 1;
	return setcards;
}

bool isPlayerWin = false;
bool isEnemyWin = false;

bool IsPlayerHigherCheck()
{
	if (playercard > enemycard)
	{
		isPlayerWin = true;
		return true;
	}
}

void PlayerWin()
{
	cout << "You win!" << endl;
}

void EnemyWin()
{
	cout << "You lose!" << endl;
}

void WhoWinCheck()
{
	if (isPlayerWin == true)
	{
		PlayerWin();
	}
	else if (isEnemyWin == true)
	{
		EnemyWin();
	}
}




void PlayerAceCheck()
{
	if (playercard == 1)
	{
		isPlayerWin = true;
		WhoWinCheck();
	}
	
}

void EnemyAceCheck()
{
	if (enemycard == 1)
	{
		isEnemyWin = true;
		WhoWinCheck();
	}
}


void PrintWhatCard(int card)
{
	if (card > 1 && card < 11)
	{
		cout << card;
	}
	else if (card == 1)
	{
		cout <<  "Ace";
	}
	else if (card == 11)
	{
		cout << "Jack (11)";
	}
	else if (card == 12)
	{
		cout << "Queen (12)";
	}
	else if (card == 13)
	{
		cout << "King (13)";
	}

	cout << endl;
	
}



int main()
{
	srand((unsigned int)time(NULL));
	cout << "Card Game Begin" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	while (true)
	{
		isPlayerWin = false;
		isEnemyWin = false;
		cout << "Type in 0 で カードを引く!" << endl;
		cout << "Type 0以外で終了 " << endl;
		cout << "=====================" << endl;
		cin >> input;
		if (input != '0')
		{
			break;
		}
		cout << "=====================" << endl;

		//https://github.com/amirullahizzan/c-kiso/blob/main/20230707/0308/Rand1.cpp
		playercard = DrawCard();
		cout << "あなたのカード : ";
		PrintWhatCard(playercard);
		PlayerAceCheck();
		if (isPlayerWin == true)
		{
			continue;
		}

		cout << "==================" << endl;
		cout << "Enemy's のターン..." << endl;
		cout << "Enemy がカードを引く..." << endl;
		enemycard = DrawCard();
		cout << "Enemy カード : " ;
		PrintWhatCard(enemycard);
		EnemyAceCheck();
		cout << "==================" << endl;
		if (playercard == enemycard)
		{
			cout << "Match Draw!" << endl;
			cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
			continue;
		}
		else if (playercard > enemycard)
		{
			PlayerWin();
			cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
			continue;
		}
		else if (enemycard > playercard)
		{
			EnemyWin();
			cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;

			continue;
		}
		
		cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;

	}

	cout << endl << "プログラム終了" << endl;
}
