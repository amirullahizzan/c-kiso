#include <iostream>

using namespace std;

const int MAX_NAME = 16;

struct Student {

	char name[MAX_NAME + 1];
	int scoreJapanese;
	int scoreMath;
	int scoreEnglish;
	
	

};



void Show(const Student& student)
{
	cout << "���O : " << student.name << endl
		<< " ���� : " << student.scoreJapanese << " �_"
		<< "�A ���w : " << student.scoreMath << " �_"
		<< "�A �p�� : " << student.scoreEnglish << " �_" << endl;
	
	
		
}

int main()
{
	Student student[] = //Constructing arrays of struct
	{
	{"�}�C�P��",73,98,86},
	{"�W�F�[���Y",64,45,40},
	{"�X�~�X",76,78,69},
	};

	int size = sizeof student / sizeof * student;

	for (int i = 0;i<size;i++)
	{
		Show(student[i]);
	}
}