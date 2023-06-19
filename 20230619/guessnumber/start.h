#pragma once


#include <iostream>

int roundcount = 1;

using namespace std;
//answers : 77
struct Round1
{
private:
	int wrong_count = 0;
public:
	int trueanswer[1] = { 77 };
	int input = 0;
	int trueanswer_ELEM = 0;
	int trueanswer_SIZE = 1;

	void DisplayIntro()
	{
		cout << "数字当てゲーム\n";
		cout << "数値を当てて見ましょう！\n";
	}

	void RoundCheck()
	{
		if (trueanswer_ELEM < trueanswer_SIZE)
		{
			cout << "次の問題。\n\n";
		}
		else if ( trueanswer_ELEM >= trueanswer_SIZE)
		{
			//out of question, go to next round
			cout << endl;
			cout << "あなたの間違いは : " << wrong_count << endl;
			cout << "次の回戦です！。\n\n";
			roundcount++;
		}
	}

	void NextQuestion()
	{
		
		trueanswer_ELEM++;
		RoundCheck();
	}


	void CorrectAnswer()
	{
		cout << "\nあなたの推測は合ってます (〇〇〇)\n";
		cout << "答えは" << trueanswer[trueanswer_ELEM] << "でした。";
		NextQuestion();
	}

	void WrongAnswer()
	{
		cout << "\n数値は合ってません (×××)\n";
		wrong_count++;
		cout << "不正解　カウント　： " << wrong_count << endl;
		if (trueanswer[trueanswer_ELEM] > input)
		{
			cout << "答えは " << input << " より大きいです\n" << endl;
		}
		else if (trueanswer[trueanswer_ELEM] < input)
		{
			cout << "答えは " << input << " より小さいです\n" << endl;
		}
		//round 1 does not have gameover GameOverCheck();
	}

	void AskUserInput()
	{
		cout << "0～100までの数値を入力してください > ";
		cin >> input;
	}
};


// int trueanswer[3] = { 52,12,78 };



struct Round2
{
private:
	int wrong_count = 0;
public:
	int trueanswer[3] = { 52,12,78 };
	int input = 0;
	int trueanswer_ELEM = 0;
	int trueanswer_SIZE = 3;

	void DisplayIntro()
	{
		cout << "数字当てゲーム\n";
		cout << "数値を当てて見ましょう！\n";
	}

	void GameOverCheck()
	{
		if (wrong_count >= 5)
		{
			cout << "5回間違えました。答えは : " << trueanswer[trueanswer_ELEM] << " でした。 答えはリセットされています。\n\n";
			trueanswer_ELEM = 0;
			wrong_count = 0;
		}
	}

	void RoundCheck()
	{
		if (trueanswer_ELEM < trueanswer_SIZE)
		{
			cout << "次の問題。\n\n";
		}
		else if (trueanswer_ELEM >= trueanswer_SIZE)
		{
			//out of question, go to next round
			cout << "あなたの間違いは : " << wrong_count << endl;
			cout << "次の回戦です！。\n\n";
			roundcount++;
		}
	}

	void NextQuestion()
	{
		trueanswer_ELEM++;
		RoundCheck();
	}


	void CorrectAnswer()
	{
		cout << "\nあなたの推測は合ってます (〇〇〇)\n";
		cout << "答えは" << trueanswer[trueanswer_ELEM] << "でした。";
		NextQuestion();
	}

	void WrongAnswer()
	{
		cout << "\n数値は合ってません (×××)\n";
		wrong_count++;
		cout << "不正解　カウント　： " << wrong_count << endl;
		if (trueanswer[trueanswer_ELEM] > input)
		{
			cout << "答えは " << input << " より大きいです\n" << endl;
		}
		else if (trueanswer[trueanswer_ELEM] < input)
		{
			cout << "答えは " << input << " より小さいです\n" << endl;
		}
		GameOverCheck();
	}

	void AskUserInput()
	{
		cout << "0～100までの数値を入力してください > ";
		cin >> input;
	}
};

struct Round3
{
private:
	int wrong_count = 0;
public:
	int trueanswer[5] = { 64,2,19, 24 ,43 };
	int input = 0;
	int trueanswer_ELEM = 0;
	int trueanswer_SIZE = 5;

	void DisplayIntro()
	{
		cout << "数字当てゲーム\n";
		cout << "数値を当てて見ましょう！\n";
	}

	void GameOverCheck()
	{
		if (wrong_count >= 5)
		{
			cout << "5回間違えました。答えは : " << trueanswer[trueanswer_ELEM] << " でした。 答えはリセットされています。\n\n";
			trueanswer_ELEM = 0;
			wrong_count = 0;
		}
	}

	void RoundCheck()
	{
		if (trueanswer_ELEM < trueanswer_SIZE)
		{
			cout << "次の問題。\n\n";
		}
		else if (trueanswer_ELEM >= trueanswer_SIZE)
		{
			//out of question, go to next round
			cout << "あなたの間違いは : " << wrong_count << endl;
			cout << "次の回戦です！。\n\n";
			roundcount++;
		}
	}

	void NextQuestion()
	{

		trueanswer_ELEM++;
		RoundCheck();
		cout << "次の問題。\n\n";
	}


	void CorrectAnswer()
	{
		cout << "\nあなたの推測は合ってます (〇〇〇)\n";
		cout << "答えは" << trueanswer[trueanswer_ELEM] << "でした。";
		NextQuestion();
	}

	void WrongAnswer()
	{
		cout << "\n数値は合ってません (×××)\n";
		wrong_count++;
		cout << "不正解　カウント　： " << wrong_count << endl;
		if (trueanswer[trueanswer_ELEM] > input)
		{
			cout << "答えは " << input << " より大きいです\n" << endl;
		}
		else if (trueanswer[trueanswer_ELEM] < input)
		{
			cout << "答えは " << input << " より小さいです\n" << endl;
		}
		GameOverCheck();
	}

	void AskUserInput()
	{
		cout << "0～100までの数値を入力してください > ";
		cin >> input;
	}
};
