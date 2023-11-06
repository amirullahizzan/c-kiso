#include "WinMain.h"
#include "Player.h"

// ------------------------------------------
//	�v���C���[�N���X�i������: �\�[�X�t�@�C���j
// ------------------------------------------
// �R���X�g���N�^
Player::Player()
{
	Init();
}

// ����������
void Player::Init()
{
	// �����l�̐ݒ�
	r_			  = 30;
	x_			  = WINDOW_W / 2;
	y_			  = WINDOW_H - r_ * 2;
	color_		  = PINK;
	is_damage_	  = false;
	damage_frame_ = 0;

}

// �X�V����
void Player::Update()
{
	if (IsDamage())
	{
		--damage_frame_;
		if (damage_frame_ <= 0)
		{
			damage_frame_ = 0;
			is_damage_	  = false;
		}
	}

	// �L�[����ł̈ړ�
	if (IsKeyRepeat(KEY_INPUT_RIGHT))
	{
		x_ += 5;
	}
	else if (IsKeyRepeat(KEY_INPUT_LEFT))
	{
		x_ -= 5;
	}
	else if (IsKeyRepeat(KEY_INPUT_UP))
	{
		y_ -= 5;
	}
	else if (IsKeyRepeat(KEY_INPUT_DOWN))
	{
		y_ += 5;
	}

	// ���W���͈͊O�ɂ����Ȃ��悤�ɂ���
	if (x_ > WINDOW_W - r_)
	{
		x_ = WINDOW_W - r_;
	}
	if (x_ < r_)
	{
		x_ = r_;
	}
	if (y_ > WINDOW_H - r_)
	{
		y_ = WINDOW_H - r_;
	}
	if (y_ < r_)
	{
		x_ = r_;
		//y_ = r_; ??
	}
}

// �`�揈��
void Player::Draw()
{
	bool is_fill = TRUE;
	if (IsDamage())
	{
		is_fill = (damage_frame_ % 5 == 0) ? TRUE : FALSE;
	}
	DrawCircleAA(x_, y_, r_, 64, color_, is_fill);

}

// ���WX�擾�֐�
float Player::GetPosX() const
{
	return x_;
}

// ���WY�擾�֐�
float Player::GetPosY() const
{
	return y_;
}

// ���a�擾�֐�
float Player::GetR() const
{
	return r_;
}

// �_���[�W�����ǂ���
bool Player::IsDamage() const
{
	return is_damage_;
}

// �_���[�W��^����
void Player::SetDamage()
{
	if (IsDamage())
		return;

	// �_���[�W���͐V���Ƀ_���[�W�����Ȃ�
	is_damage_    = true;
	damage_frame_ = 60 * 1;
}
