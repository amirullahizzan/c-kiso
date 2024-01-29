#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "Enemy08Fujii.h"
// =====================================================
//	�G�u����v�N���X�i�\�[�X�t�@�C���j
//	 
// =====================================================
// �U������
void Enemy08Fujii::attack()
{
	pos_.x += move_speed_;
	if (pos_.x < getR() ||
		pos_.x > WINDOW_W - getR())
	{
		move_speed_ *= -1.2;
	}
	pos_.y += move_speed_;
	if (pos_.y < getR() ||
		pos_.y > WINDOW_H - getR())
	{
		move_speed_ *= -1.2;
	}
}

// �R���X�g���N�^
Enemy08Fujii::Enemy08Fujii() :
	EnemyBase("data/animation/enemy/enemy03.png")
{

}

// �f�X�g���N�^
Enemy08Fujii::~Enemy08Fujii()
{

}
