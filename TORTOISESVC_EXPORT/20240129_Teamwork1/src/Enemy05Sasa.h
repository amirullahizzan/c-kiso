#pragma once
// =====================================================
//	�G�u���X�v�N���X�i�w�b�_�[�t�@�C���j
//	 ���E�Ɉړ�����G�N���X
// =====================================================
class Enemy05Sasa :
	public EnemyBase
{
private:
	void attack() override;

	float move_speed_ = 8;

public:
	Enemy05Sasa();
	virtual ~Enemy05Sasa();

};