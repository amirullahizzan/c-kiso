#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "Enemy12Yukioka.h"
// =====================================================
//	�G�u���ہv�N���X�i�\�[�X�t�@�C���j
//	 ���E�Ɉړ�����G�N���X
// =====================================================
// �U������
void Enemy12Yukioka::attack()
{
	//--------------------------------------
	// �o�E���h
	//--------------------------------------
	if (attack_mode_ == Bound)
	{
		power();
		frame_--;

		// ���˕Ԃ�
		if (pos_.x < getR() ||
			pos_.x > WINDOW_W - getR())
		{
			move_speed_ *= -1;
		}
		if (pos_.y < getR() ||
			pos_.y > WINDOW_H - getR())
		{
			move_speed_ *= -1;
		}

		// �R�b�o�����������ς���
		if (frame_ <= 0)
		{
			frame_ = 60 * 3;
			angle_ = GetRand(360);
		}

	}


	//--------------------------------------
	// �g���l�[�h
	//--------------------------------------
	if (attack_mode_ == Tornado)
	{
		power();
		angle_+= 0.5f;
		pos_.x += move_speed_;
		// ��ʊO�ɏo�Ȃ�
		if (pos_.x < getR() ||
			pos_.x > WINDOW_W - getR())
		{
			move_speed_ *= -1;
		}
	}
}

void Enemy12Yukioka::power()
{
	pos_.x += move_speed_ * cosf(angle_);
	pos_.y += move_speed_ * sinf(angle_);
}

// �R���X�g���N�^
Enemy12Yukioka::Enemy12Yukioka() :
	EnemyBase("data/animation/enemy/enemy01.png")
{
	attack_mode_ = GetRand(10) % 2;
	move_speed_ = 10;
	angle_ = GetRand(360);
	frame_ = 60 * 3;
}

// �f�X�g���N�^
Enemy12Yukioka::~Enemy12Yukioka()
{

}
