#pragma once
// --------------------------------------------------------
//	WeaponSword�N���X�i�w�b�_�[�t�@�C���j
//	 ����u��{�̌��v�N���X
//	 �U���͂́u10�v�A1��̍U����1��̍U���͂��_���[�W�ʂƂ��ē���
// --------------------------------------------------------
class WeaponSword :
	public WeaponBase
{
public:
	WeaponSword();
	~WeaponSword();

private:
	void AttackMain() override;

};
