#include "WeaponBase.h"
#include "WeaponSword.h"
#include <iostream>

WeaponSword::WeaponSword() :
	WeaponBase("��{�̌�", 15)
{
	std::cout << "WeaponSword�N���X�̃R���X�g���N�^���Ă΂�܂���" << std::endl;

	attack_value_ = 15;
}

WeaponSword::~WeaponSword()
{
	std::cout << "WeaponSword�N���X�̃f�X�g���N�^���Ă΂�܂���" << std::endl;
}

void WeaponSword::AttackMain()
{
	std::cout << "�_���[�W " << attack_value_ << "��^����" << std::endl;

	damage_value_ += attack_value_;
}
