#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "Enemy09Mai.h"
// =====================================================
//	�G�u���ہv�N���X�i�\�[�X�t�@�C���j
//	 ���E�Ɉړ�����G�N���X
// =====================================================
// �U������
void Enemy09Mai::attack()
{
	rot_speed += 0.5f;

	pos_.x += move_speed_ * sinf(rot_speed * 180.0f / 3.14159265f);
	pos_.y += move_speed_ * cosf(rot_speed * 180.0f / 3.14159265f);
	if (pos_.x < getR() || 
		pos_.x > WINDOW_W - getR())
	{
		move_speed_ *= -1;
	}
}

// �R���X�g���N�^
Enemy09Mai::Enemy09Mai() :
	EnemyBase("data/animation/enemy/enemy04.png")
{

}

// �f�X�g���N�^
Enemy09Mai::~Enemy09Mai()
{

}
