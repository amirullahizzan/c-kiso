// Chapter07-11 �N���X�̓��I�m��
//	�A�b�v�L���X�g�̕��K
#include "WeaponBase.h"
#include "WeaponSword.h"
#include "WeaponTwinSword.h"
#include <iostream>
#include <ctime>
using namespace std;


void UseWeapon(WeaponBase* weapon)
{
	weapon->Show();
	weapon->Attack();
}

WeaponBase* WeaponFactory(int i)
{
	switch (i)
	{
		case 0: return ;
		case 1: return ;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	// ����̍쐬

	WeaponSword		sword;
	WeaponTwinSword twin_sword;

	WeaponBase* weapons[2] =
	{
		&sword,&twin_sword
	};

	for (int i = 0; i < 20; ++i)
	{
		int use_weapon = rand() % 100;
		// 2����1�̊m���łǂ��炩�̕�����g��
		
		
	}

	system("pause");
	return 0;
}