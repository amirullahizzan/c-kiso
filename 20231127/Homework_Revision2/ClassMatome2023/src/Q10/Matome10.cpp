// Q10. ���z�֐�
// ���s�T���v�� > Q10.exe
// *********************************
//	���̃t�@�C����ҏW���Ȃ�����
// *********************************
#include <iostream>
#include "PointCardBase.h"
#include "GoldPointCard.h"
#include "SilverPointCard.h"
using namespace std;

int main()
{
	GoldPointCard card1;
	card1 += 500;
	card1.render();

	SilverPointCard card2;
	card2 += 300;
	card2.render();

	system("pause");
	return 0;
}