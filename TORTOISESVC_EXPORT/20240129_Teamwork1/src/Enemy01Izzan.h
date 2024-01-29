#pragma once
// =====================================================
//	�G�u���ہv�N���X�i�w�b�_�[�t�@�C���j
//	 ���E�Ɉړ�����G�N���X
// =====================================================
class Enemy01Izzan :
	public EnemyBase
{
private:
	void attack() override;

	bool isPlayerCloseTriggered = false;
	float move_speed_x = 4;
	float move_speed_y = 8;
	int spinTimer = 0;

	void SpinEnemy();
	void EnlargeSpriteAI();
	void EnemyAI();

public:
	Enemy01Izzan();
	virtual ~Enemy01Izzan();

};