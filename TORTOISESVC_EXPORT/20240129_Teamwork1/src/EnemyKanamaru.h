#pragma once
// =====================================================
//	�G�u���ہv�N���X�i�w�b�_�[�t�@�C���j
//	 ���E�Ɉړ�����G�N���X
// =====================================================
class EnemyKanamaru :
	public EnemyBase
{
private:
	void attack() override;

	float move_speed_ = 8;
	void attackRender() override;

public:
	EnemyKanamaru();
	virtual ~EnemyKanamaru();

};