#pragma once
// =====================================================
//	�G�u���ہv�N���X�i�w�b�_�[�t�@�C���j
//	 ���E�Ɉړ�����G�N���X
// =====================================================
class Enemy09Mai :
	public EnemyBase
{
private:
	void attack() override;
	int rot_speed = 0;
	float move_speed_ = 8;

public:
	Enemy09Mai();
	virtual ~Enemy09Mai();

};