#pragma once
// --------------------------------------------------------
//	WeaponTwinSword�N���X�i�w�b�_�[�t�@�C���j
//	 ����u�o���v�N���X
//	 �U���͂́u10�v�A1��̍U����2��̍U���͂��_���[�W�ʂƂ��ē���
// --------------------------------------------------------
class WeaponTwinSword :
	public WeaponBase
{
public:
	WeaponTwinSword();
	~WeaponTwinSword();

private:
	void AttackMain() override;

	const int ATTACK_NUM = 2;
};
