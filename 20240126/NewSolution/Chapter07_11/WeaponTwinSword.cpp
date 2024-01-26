#include "WeaponBase.h"
#include "WeaponTwinSword.h"
#include <iostream>
// --------------------------------------------------------
//	WeaponTwinSwordクラス（ソースファイル）
//	 武器「双剣」クラス
//	 攻撃力は「10」、1回の攻撃で2回の攻撃力がダメージ量として入る
// --------------------------------------------------------
WeaponTwinSword::WeaponTwinSword() :
	WeaponBase("双剣", 10)
{
	std::cout << "WeaponTwinSwordクラスのコンストラクタが呼ばれました" << std::endl;

	attack_value_ = 5;
}

WeaponTwinSword::~WeaponTwinSword()
{
	std::cout << "WeaponTwinSwordクラスのデストラクタが呼ばれました" << std::endl;
}

void WeaponTwinSword::AttackMain()
{
	for (int i = 0; i < ATTACK_NUM; ++i)
	{
		std::cout << "ダメージ " << attack_value_ << "を与えた" << std::endl;
		damage_value_ += attack_value_;
	}
}
