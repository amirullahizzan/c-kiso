#include "WeaponBase.h"
#include "WeaponTwinSword.h"
#include <iostream>
// --------------------------------------------------------
//	WeaponTwinSword�N���X�i�\�[�X�t�@�C���j
//	 ����u�o���v�N���X
//	 �U���͂́u10�v�A1��̍U����2��̍U���͂��_���[�W�ʂƂ��ē���
// --------------------------------------------------------
WeaponTwinSword::WeaponTwinSword() :
	WeaponBase("�o��", 10)
{
	std::cout << "WeaponTwinSword�N���X�̃R���X�g���N�^���Ă΂�܂���" << std::endl;

	attack_value_ = 5;
}

WeaponTwinSword::~WeaponTwinSword()
{
	std::cout << "WeaponTwinSword�N���X�̃f�X�g���N�^���Ă΂�܂���" << std::endl;
}

void WeaponTwinSword::AttackMain()
{
	for (int i = 0; i < ATTACK_NUM; ++i)
	{
		std::cout << "�_���[�W " << attack_value_ << "��^����" << std::endl;
		damage_value_ += attack_value_;
	}
}
