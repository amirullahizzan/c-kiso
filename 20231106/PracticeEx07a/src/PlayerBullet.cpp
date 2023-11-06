#include "WinMain.h"
#include "PlayerBullet.h"
// ------------------------------------------
//	�v���C���[�e�N���X�i������: �\�[�X�t�@�C���j
// ------------------------------------------
// �R���X�g���N�^
PlayerBullet::PlayerBullet()
{
	Init();

}

// ����������
void PlayerBullet::Init()
{
	// �����l�̐ݒ�
	r_		 = 10;
	color_	 = YELLOW;
	is_shot_ = false;

}

// �X�V����
void PlayerBullet::Update()
{
	if (!IsShot())
		return;

	y_ -= 8;
	if (y_ < -r_ * 2 )
	{
		is_shot_ = false;
	}

}

// �`�揈��
void PlayerBullet::Draw()
{
	if (!IsShot())
		return;

	DrawCircleAA(x_, y_, r_, 64, color_, TRUE);

}

// ���W�w��֐�
void PlayerBullet::SetPos(float x, float y)
{
	x_		 = x;
	y_		 = y;
	is_shot_ = true;

}

// ���WX�擾�֐�
float PlayerBullet::GetPosX() const
{
	return x_;
}

// ���WY�擾�֐�
float PlayerBullet::GetPosY() const
{
	return y_;
}

// ���a�擾�֐�
float PlayerBullet::GetR() const
{
	return r_;
}

// �e�����������ǂ���
bool PlayerBullet::IsShot() const
{
	return is_shot_;
}
