// Q7. �����������o�֐����Ă΂��悤�ɏC�����Ă�������
// ���s�T���v�� > Q7.exe
// *********************************
//	���̃t�@�C����ҏW���Ȃ�����
// *********************************
#include <iostream>
#include <ctime>
#include "Player.h"
#include "Enemy.h"
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	Player player;
	Enemy enemy;

	Base& b1 = player;
	b1.Set();
	cout << "Player: " << b1.Get() << endl;
	b1.Mul();
	cout << "Player(*2): " << b1.Get() << endl;

	Base& b2 = enemy;
	b2.Set();
	cout << "Enemy: " << b2.Get() << endl;
	b2.Mul();
	cout << "Enemy(*2): " << b2.Get() << endl;

	system("pause");
	return 0;
}