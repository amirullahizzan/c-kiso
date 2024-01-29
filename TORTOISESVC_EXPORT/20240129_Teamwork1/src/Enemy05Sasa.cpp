#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "Enemy05Sasa.h"
// =====================================================
//	�G�u���X�v�N���X�i�\�[�X�t�@�C���j
//	 ���E�Ɉړ�����G�N���X
// =====================================================
// �U������
void Enemy05Sasa::attack()
{
	pos_.x += move_speed_;
	if (pos_.x < getR() || pos_.x > WINDOW_W - getR())
	{
		move_speed_ *= -1;
	}

	pos_.y += move_speed_;
	if (pos_.y < getR() || pos_.y > WINDOW_H - getR())
	{
		move_speed_ *= -1;
	}
}

// �R���X�g���N�^
Enemy05Sasa::Enemy05Sasa() :
	EnemyBase("data/animation/enemy/enemy04.png")
{

}

// �f�X�g���N�^
Enemy05Sasa::~Enemy05Sasa()
{

}
