#include <iostream>
#include "start.h"

using namespace std;

Round1 gameround;
Round2 gameround2;
Round3 gameround3;

int main()
{
	while (roundcount == 1)
	{
		cout << "=======================================\n\n";
		cout << "1回戦... はじめ！" << endl;
		gameround.AskUserInput();

		if (gameround.input < 0 || gameround.input > 99)
		{
			cout << "数値は 0～100 以外入力できません！ \n";
			continue;
		}
		else if (gameround.input == gameround.trueanswer[gameround.trueanswer_ELEM])
		{
			gameround.CorrectAnswer();
			continue;
		}
		else if (gameround.input != gameround.trueanswer[gameround.trueanswer_ELEM])
		{
			gameround.WrongAnswer();
			continue;
		}

	}
	
	
	while (roundcount == 2)
	{
		cout << gameround2.input << "!!!!!!!!!!!";
		cout << "=======================================\n\n";
		cout << "2回戦... はじめ！" << endl;
		gameround2.AskUserInput();

		if (gameround2.input < 0 || gameround2.input > 99)
		{
			cout << "数値は 0～100 以外入力できません！ \n";
			continue;
		}
		else if (gameround2.input == gameround2.trueanswer[gameround2.trueanswer_ELEM])
		{
			gameround2.CorrectAnswer();
			continue;
		}
		else if (gameround2.input != gameround2.trueanswer[gameround2.trueanswer_ELEM])
		{
			gameround2.WrongAnswer();
			continue;
		}

	}

	while (roundcount == 3)
	{
		cout << gameround3.input << "!!!!!!!!!!!";
		cout << "=======================================\n\n";
		cout << "3回戦... はじめ！" << endl;
		gameround3.AskUserInput();

		if (gameround3.input < 0 || gameround3.input > 99)
		{
			cout << "数値は 0～100 以外入力できません！ \n";
			continue;
		}
		else if (gameround3.input == gameround3.trueanswer[gameround3.trueanswer_ELEM])
		{
			gameround3.CorrectAnswer();
			continue;
		}
		else if (gameround3.input != gameround3.trueanswer[gameround3.trueanswer_ELEM])
		{
			gameround3.WrongAnswer();
			continue;
		}

	}

	cout << "=======================================\n";
	cout << "勝利。ゲーム終了。";

}