// Q4. ��{�I�ȃN���X�̍���
// ���s�T���v�� > Q4.exe
// *********************************
//	���̃t�@�C����ҏW���Ȃ�����
// *********************************
#include <iostream>
#include "Character.h"
using namespace std;

int main()
{
	const char* SAMPLE = "Hello World!!";
	const char  SEARCH = 'o';
	Character ch(SAMPLE);

	ch.Show();
	cout << " �̒��ɂ� " << SEARCH << " ��" 
		 << ((ch.Search(SEARCH)) ? "����܂�" : "����܂���") << endl;

	system("pause");
	return 0;
}