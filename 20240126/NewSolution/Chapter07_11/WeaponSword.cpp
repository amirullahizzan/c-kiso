#include "WeaponBase.h"
#include "WeaponSword.h"
#include <iostream>

WeaponSword::WeaponSword() :
	WeaponBase("基本の剣", 15)
{
	std::cout << "WeaponSwordクラスのコンストラクタが呼ばれました" << std::endl;

	attack_value_ = 15;
}

WeaponSword::~WeaponSword()
{
	std::cout << "WeaponSwordクラスのデストラクタが呼ばれました" << std::endl;
}

void WeaponSword::AttackMain()
{
	std::cout << "ダメージ " << attack_value_ << "を与えた" << std::endl;

	damage_value_ += attack_value_;
}
