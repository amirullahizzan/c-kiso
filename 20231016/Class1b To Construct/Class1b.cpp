#include <iostream>

using namespace std;

const int MAX_NAME = 16;

class Student
{
//#define test 25 //this macro bleeds through scopes
	private :
	const char* name_ = nullptr;
	int scoreJapanese_ = 0;
	int scoreMath_ = 0;
	int scoreEnglish_ = 0;
public :
	Student(const char* name, int scoreJapanese, int scoreMath, int scoreEnglish);

	void Show();

};

Student::Student(const char* name, int scoreJapanese, int scoreMath, int scoreEnglish)
{
	name_ = name;
	scoreJapanese_ = scoreJapanese;
	scoreMath_ = scoreMath;
	scoreEnglish_ = scoreEnglish;
};

void Student::Show()
{
	cout << "���O�@�F�@" << name_ << endl;
	cout << "����@�F�@" << scoreJapanese_ << "�_" << endl;
	cout << "���w�@�F�@" << scoreMath_ << "�_" << endl;
	cout << "�p��@�F�@" << scoreEnglish_ << "�_" << endl;
}



int main()
{
	Student student[] = 
	{
		Student("�Ԉ�",73,98,86),
		Student("JOHN",64,45,40),
		Student("SMITH", 76,78,69)
	};

	int size = sizeof student / sizeof * student;

	for (int i = 0; i < size; i++)
	{
		student[i].Show();
	}

	

}