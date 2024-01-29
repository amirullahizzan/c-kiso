#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "EnemyKanamaru.h"
// =====================================================
//	�G�u���ہv�N���X�i�\�[�X�t�@�C���j
//	 ���E�Ɉړ�����G�N���X
// =====================================================
// �U������
void EnemyKanamaru::attack()
{
	pos_.x += move_speed_;
	if (pos_.x < getR() || 
		pos_.x > WINDOW_W - getR())
	{
		move_speed_ *= -1;
	}
}

// �U���V�[��: �`��
void EnemyKanamaru::attackRender()
{
	DrawCircleAA(WINDOW_W / 2, WINDOW_H / 2, 40, 64, RED, TRUE);
}

// �R���X�g���N�^
EnemyKanamaru::EnemyKanamaru() :
	EnemyBase("data/animation/enemy/enemy04.png")
{

}

// �f�X�g���N�^
EnemyKanamaru::~EnemyKanamaru()
{

}
