#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "Enemy06Tanaka.h"
// =====================================================
//	�G�u�c���v�N���X�i�\�[�X�t�@�C���j
//	 �΂߂Ɉړ�����G�N���X
// =====================================================
// �U������
void Enemy06Tanaka::attack()
{
	pos_.x += move_speed_x;
	pos_.y += move_speed_y;

	if (pos_.x < getR() ||
		pos_.x > WINDOW_W - getR())
	{
		move_speed_x *= -1;
	}
	if (pos_.y < getR() ||
		pos_.y> WINDOW_H - getR())
	{
		move_speed_y *= -1;
	}
}

// �R���X�g���N�^
Enemy06Tanaka::Enemy06Tanaka() :
	EnemyBase("data/animation/enemy/enemy03.png")
{

}

// �f�X�g���N�^
Enemy06Tanaka::~Enemy06Tanaka()
{

}
