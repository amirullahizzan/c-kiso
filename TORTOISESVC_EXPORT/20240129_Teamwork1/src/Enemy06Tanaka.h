#pragma once
// =====================================================
//	�G�u�c���v�N���X�i�w�b�_�[�t�@�C���j
//	 
// =====================================================
class Enemy06Tanaka :
	public EnemyBase
{
private:
	void attack() override;

	float move_speed_x = 5;
	float move_speed_y = 10;

public:
	Enemy06Tanaka();
	virtual ~Enemy06Tanaka();

};