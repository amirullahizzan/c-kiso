#include <iostream>

using namespace std;

const int MAX_NAME = 16;

class Student
{
public:
	char name[MAX_NAME + 1];
	int scoreJapanese;
	int scoreMath;
	int scoreEnglish;
};

void Show(const Student& student)
{
	cout << "���O�@�F�@" << student.name << endl;
	cout << "����@�F�@" << student.scoreJapanese << "�_" << endl;
	cout << "���w�@�F�@" << student.scoreMath << "�_" << endl;
	cout << "�p��@�F�@" << student.scoreEnglish << "�_" << endl;
}

int main()
{
	Student student[] = {
		{"JAMES",73,98,86},{"JOHN",64,45,40},{"SMITH", 76,78,69}
	};

	int size = sizeof student / sizeof *student;

	for (int i = 0; i < size; i++)
	{
		Show(student[i]);
	}

}