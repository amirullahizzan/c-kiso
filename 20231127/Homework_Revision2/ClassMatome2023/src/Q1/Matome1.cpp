// Q1. ��{�I�ȃN���X�̎g����
// IchimatsuMark�N���X���g���āA�s���͗l��3��o�͂��Ȃ���
// IchimatsuMark�N���X�́A�ȉ��̃����o�֐��������Ă���
//		Resize�����o�֐� �c �s���͗l�̃T�C�Y��ݒ肷��
//		Show�����o�֐�	 �c �s���͗l���T�C�Y���o�͂���
// ���s�T���v�� > Q1.exe
#include <iostream>
#include "IchimatsuMark.h"
using namespace std;


int main()
{
	IchimatsuMark imark;
	static int count = 0;
	while (count < 3)
	{
	imark.Resize();
	imark.Show();
	count++;
	}
	std::system("pause");
	return 0;
}