#pragma once
// =====================================================
//	�G�u����v�N���X�i�w�b�_�[�t�@�C���j
//	 
// =====================================================
class Enemy08Fujii :
	public EnemyBase
{
private:
	void attack() override;

	float move_speed_ = 5;

public:
	Enemy08Fujii();
	virtual ~Enemy08Fujii();

};