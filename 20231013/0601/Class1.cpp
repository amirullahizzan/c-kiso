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
	cout << "名前　：　" << student.name << endl;
	cout << "国語　：　" << student.scoreJapanese << "点" << endl;
	cout << "数学　：　" << student.scoreMath << "点" << endl;
	cout << "英語　：　" << student.scoreEnglish << "点" << endl;
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