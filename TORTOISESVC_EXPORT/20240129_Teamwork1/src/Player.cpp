#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "Player.h"
// =====================================================
//	�v���C���[�N���X�i�\�[�X�t�@�C���j
//	 �㉺���E�L�[�ňړ�����
// =====================================================
// �R���X�g���N�^
Player::Player() :
	ActorBase("data/animation/player/player04.png")
{
	pos_   = { (float)(WINDOW_W / 2), (float)(WINDOW_H / 2) };
	scale_ = 1.5;

	hp_ = HP_MAX;
}

// �`�揈��
void Player::render()
{
	if (damage_frame_ % 3 == 0)
	{
		__super::render();
	}

}

// �L�[���͂ł̈ړ�
void Player::keyMove()
{
	Pos now_pos = getPos();
	if (IsKeyRepeat(KEY_INPUT_RIGHT))
	{
		now_pos.x += MOVE_SPEED;
		dir_ = DIR::RIGHT;
		move_num_ += MOVE_SPEED;
	}
	else if (IsKeyRepeat(KEY_INPUT_LEFT))
	{
		now_pos.x -= MOVE_SPEED;
		dir_ = DIR::LEFT;
		move_num_ += MOVE_SPEED;
	}
	else if (IsKeyRepeat(KEY_INPUT_UP))
	{
		now_pos.y -= MOVE_SPEED;
		dir_ = DIR::UP;
		move_num_ += MOVE_SPEED;
	}
	else if (IsKeyRepeat(KEY_INPUT_DOWN))
	{
		now_pos.y += MOVE_SPEED;
		dir_ = DIR::DOWN;
		move_num_ += MOVE_SPEED;
	}

	// �͈͊O�̃`�F�b�N
	now_pos.x = max(now_pos.x, IMG_SIZE / 2);
	now_pos.y = max(now_pos.y, IMG_SIZE / 2);
	now_pos.x = min(now_pos.x, WINDOW_W - IMG_SIZE / 2);
	now_pos.y = min(now_pos.y, WINDOW_H - IMG_SIZE / 2);

	pos_ = now_pos;
}

// �X�V�����i�{�́j
void Player::updateBody()
{
	keyMove();

	updateDamage();
}

// �����ɓ�������
void Player::onHit(std::string tag)
{
	if (tag == "Enemy")
	{
		if (damage_frame_ != 0)
		{
			return;
		}

		// �_���[�W�ǉ�����
		damage_frame_ = DAMAGE_FRAME;
		--hp_;
		if (getHp() < 0)
		{
			hp_ = 0;
		}
	}
}
// --------------------------------
// �_���[�W����
// --------------------------------
// �X�V����
void Player::updateDamage()
{
	if (damage_frame_ <= 0)
		return;

	--damage_frame_;
	if (damage_frame_ <= 0)
	{
		damage_frame_ = 0;
	}
}
