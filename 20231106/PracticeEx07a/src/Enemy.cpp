#include "WinMain.h"
#include "Enemy.h"

// ------------------------------------------
//	�G�N���X�i������: �\�[�X�t�@�C���j
// ------------------------------------------
// �R���X�g���N�^
Enemy::Enemy()
{
	Init();
}

// ����������
void Enemy::Init()
{
	// �����l�̐ݒ�
	r_			  = 30;
	color_		  = GREEN;
	is_damage_	  = false;
	damage_frame_ = 0;
}

// �X�V����
void Enemy::Update()
{
	if (IsDamage())
	{
		--damage_frame_;
		if (damage_frame_ <= 0)
		{
			damage_frame_ = 0;
			is_damage_ = false;
		}
		return;
	}
	// �_���[�W���͈ȉ��������s��Ȃ�

}

// �`�揈��
void Enemy::Draw()
{
	bool is_fill = TRUE;
	if (IsDamage())
	{
		is_fill = (damage_frame_ % 5 == 0) ? TRUE : FALSE;
	}
	DrawCircleAA(x_, y_, r_, 64, color_, is_fill);

}

// ���W�w��֐�
void Enemy::SetPos(float x, float y)
{
	x_ = x;
	y_ = y;
}

// ���WX�擾�֐�
float Enemy::GetPosX() const
{
	return x_;
}

// ���WY�擾�֐�
float Enemy::GetPosY() const
{
	return y_;
}

// ���a�擾�֐�
float Enemy::GetR() const
{
	return r_;
}

// �_���[�W�����ǂ���
bool Enemy::IsDamage() const
{
	return is_damage_;
}

// �_���[�W��^����
void Enemy::SetDamage()
{
	if (IsDamage())
		return;

	// �_���[�W���͐V���Ƀ_���[�W�����Ȃ�
	is_damage_ = true;
	damage_frame_ = 60 * 1;
}
