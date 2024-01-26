// Chapter07-11 クラスの動的確保
//	アップキャストの復習
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

	// 武器の作成

	WeaponSword		sword;
	WeaponTwinSword twin_sword;

	WeaponBase* weapons[2] =
	{
		&sword,&twin_sword
	};

	for (int i = 0; i < 20; ++i)
	{
		int use_weapon = rand() % 100;
		// 2分の1の確率でどちらかの武器を使う
		
		
	}

	system("pause");
	return 0;
}