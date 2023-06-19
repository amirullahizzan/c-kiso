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
		cout << "�������ăQ�[��\n";
		cout << "���l�𓖂ĂČ��܂��傤�I\n";
	}

	void RoundCheck()
	{
		if (trueanswer_ELEM < trueanswer_SIZE)
		{
			cout << "���̖��B\n\n";
		}
		else if ( trueanswer_ELEM >= trueanswer_SIZE)
		{
			//out of question, go to next round
			cout << endl;
			cout << "���Ȃ��̊ԈႢ�� : " << wrong_count << endl;
			cout << "���̉��ł��I�B\n\n";
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
		cout << "\n���Ȃ��̐����͍����Ă܂� (�Z�Z�Z)\n";
		cout << "������" << trueanswer[trueanswer_ELEM] << "�ł����B";
		NextQuestion();
	}

	void WrongAnswer()
	{
		cout << "\n���l�͍����Ă܂��� (�~�~�~)\n";
		wrong_count++;
		cout << "�s�����@�J�E���g�@�F " << wrong_count << endl;
		if (trueanswer[trueanswer_ELEM] > input)
		{
			cout << "������ " << input << " ���傫���ł�\n" << endl;
		}
		else if (trueanswer[trueanswer_ELEM] < input)
		{
			cout << "������ " << input << " ��菬�����ł�\n" << endl;
		}
		//round 1 does not have gameover GameOverCheck();
	}

	void AskUserInput()
	{
		cout << "0�`100�܂ł̐��l����͂��Ă������� > ";
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
		cout << "�������ăQ�[��\n";
		cout << "���l�𓖂ĂČ��܂��傤�I\n";
	}

	void GameOverCheck()
	{
		if (wrong_count >= 5)
		{
			cout << "5��ԈႦ�܂����B������ : " << trueanswer[trueanswer_ELEM] << " �ł����B �����̓��Z�b�g����Ă��܂��B\n\n";
			trueanswer_ELEM = 0;
			wrong_count = 0;
		}
	}

	void RoundCheck()
	{
		if (trueanswer_ELEM < trueanswer_SIZE)
		{
			cout << "���̖��B\n\n";
		}
		else if (trueanswer_ELEM >= trueanswer_SIZE)
		{
			//out of question, go to next round
			cout << "���Ȃ��̊ԈႢ�� : " << wrong_count << endl;
			cout << "���̉��ł��I�B\n\n";
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
		cout << "\n���Ȃ��̐����͍����Ă܂� (�Z�Z�Z)\n";
		cout << "������" << trueanswer[trueanswer_ELEM] << "�ł����B";
		NextQuestion();
	}

	void WrongAnswer()
	{
		cout << "\n���l�͍����Ă܂��� (�~�~�~)\n";
		wrong_count++;
		cout << "�s�����@�J�E���g�@�F " << wrong_count << endl;
		if (trueanswer[trueanswer_ELEM] > input)
		{
			cout << "������ " << input << " ���傫���ł�\n" << endl;
		}
		else if (trueanswer[trueanswer_ELEM] < input)
		{
			cout << "������ " << input << " ��菬�����ł�\n" << endl;
		}
		GameOverCheck();
	}

	void AskUserInput()
	{
		cout << "0�`100�܂ł̐��l����͂��Ă������� > ";
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
		cout << "�������ăQ�[��\n";
		cout << "���l�𓖂ĂČ��܂��傤�I\n";
	}

	void GameOverCheck()
	{
		if (wrong_count >= 5)
		{
			cout << "5��ԈႦ�܂����B������ : " << trueanswer[trueanswer_ELEM] << " �ł����B �����̓��Z�b�g����Ă��܂��B\n\n";
			trueanswer_ELEM = 0;
			wrong_count = 0;
		}
	}

	void RoundCheck()
	{
		if (trueanswer_ELEM < trueanswer_SIZE)
		{
			cout << "���̖��B\n\n";
		}
		else if (trueanswer_ELEM >= trueanswer_SIZE)
		{
			//out of question, go to next round
			cout << "���Ȃ��̊ԈႢ�� : " << wrong_count << endl;
			cout << "���̉��ł��I�B\n\n";
			roundcount++;
		}
	}

	void NextQuestion()
	{

		trueanswer_ELEM++;
		RoundCheck();
		cout << "���̖��B\n\n";
	}


	void CorrectAnswer()
	{
		cout << "\n���Ȃ��̐����͍����Ă܂� (�Z�Z�Z)\n";
		cout << "������" << trueanswer[trueanswer_ELEM] << "�ł����B";
		NextQuestion();
	}

	void WrongAnswer()
	{
		cout << "\n���l�͍����Ă܂��� (�~�~�~)\n";
		wrong_count++;
		cout << "�s�����@�J�E���g�@�F " << wrong_count << endl;
		if (trueanswer[trueanswer_ELEM] > input)
		{
			cout << "������ " << input << " ���傫���ł�\n" << endl;
		}
		else if (trueanswer[trueanswer_ELEM] < input)
		{
			cout << "������ " << input << " ��菬�����ł�\n" << endl;
		}
		GameOverCheck();
	}

	void AskUserInput()
	{
		cout << "0�`100�܂ł̐��l����͂��Ă������� > ";
		cin >> input;
	}
};
