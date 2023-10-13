#include <iostream>

using namespace std;

const int MAX_NAME = 16;

class Student
{
//#define test 25 //this macro bleeds through scopes
public :
	char name[MAX_NAME + 1];
	int scoreJapanese;
	int scoreMath;
	int scoreEnglish;

	void Show();
	int GetSum();
	int GetJapaneseScore();
	void SetJapaneseScore(int newScore);

};

void Student::Show()
{
	cout << "���O�@�F�@" << name << endl;
	cout << "����@�F�@" << scoreJapanese << "�_" << endl;
	cout << "���w�@�F�@" << scoreMath << "�_" << endl;
	cout << "�p��@�F�@" << scoreEnglish << "�_" << endl;
}


int Student::GetSum()
{
	return scoreJapanese+scoreMath+scoreEnglish;
}

int Student::GetJapaneseScore()
{
	return scoreJapanese;
}
void Student::SetJapaneseScore(int newScore)
{
	if (newScore > 100)
	{
		newScore = 100;
	}
	if (newScore < 0)
	{
		newScore = 0;
	}

	newScore = scoreJapanese;
}

int main()
{
	Student student[] = {
	{"�Ԉ�",73,98,86},{"JOHN",64,45,40},{"SMITH", 76,78,69}
	};

	int size = sizeof student / sizeof * student;

	for (int i = 0; i < size; i++)
	{
		student[i].Show();
	}

	int all_sum = 0;
	for (int i = 0;i < size;i++)
	{
	all_sum += student[i].GetSum();
	}

	cout << all_sum << "�_" << endl;

	//cout << student[0].scoreJapanese << endl;
	//student->changeJapaneseScore(86); //Arrow means it's trying to access/change the full object
	student[0].SetJapaneseScore(86);


}