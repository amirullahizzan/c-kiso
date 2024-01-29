#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "Enemy07Hamaguchi.h"
// =====================================================
//	�G�u�M���v�N���X�i�\�[�X�t�@�C���j
//	 ���E�Ɉړ�����G�N���X
// =====================================================
// �U������
void Enemy07Hamaguchi::attack()
{
	
	pos_.x -= move_x;
	pos_.y += move_y;

	if (pos_.x < getR() || 
		pos_.x > WINDOW_W - getR())
	{
		move_x *= -1.3;
	}

	if (pos_.y < getR() ||
		pos_.y > WINDOW_H - getR())
	{
		move_y *= -1.05;
	}
	if (move_x > 4)
	{
		move_x = 4;
	}

	if (move_y > 2.5)
	{
		move_y = 2.5;
	}
}

// �R���X�g���N�^
Enemy07Hamaguchi::Enemy07Hamaguchi() :
	EnemyBase("data/animation/enemy/enemy04.png")
{

}

// �f�X�g���N�^
Enemy07Hamaguchi::~Enemy07Hamaguchi()
{

}
