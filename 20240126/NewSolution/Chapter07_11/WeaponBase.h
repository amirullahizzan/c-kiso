#pragma once
// --------------------------------------------------------
//	WeaponBase�N���X�i�w�b�_�[�t�@�C���j
//	 ����̊��N���X
//	 AttackMain�����o�֐���h���N���X�ŃI�[�o�[���C�h���Ďg�p����
// --------------------------------------------------------
class WeaponBase
{
public:
	WeaponBase(const char* name, int hp);	// �R���X�g���N�^(����̖��̂������Ɏw��)
	virtual ~WeaponBase() ;							// �f�X�g���N�^

	void Show() const;						// ����̖��̂ƍU���͂��o��
	int  Attack();							// �U���i����̎g�p�j

protected:
	int attack_value_ = 0;					// �U����
	int damage_value_ = 0;					// �^����_���[�W��
	virtual void AttackMain() = 0;			// �U���idamage_value_�𑝂₷�j

private:
	const char* NAME;						// ����̖���
	int hp_			  = 0;					// �����HP�i�ϋv���j

	void MissAttack() const;				// �U�����s�̃��b�Z�[�W�o��

};
