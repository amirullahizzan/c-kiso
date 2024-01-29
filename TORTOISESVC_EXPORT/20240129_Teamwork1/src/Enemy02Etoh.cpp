#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "Enemy02Etoh.h"
// =====================================================
//	�G�u�]���v�N���X�i�\�[�X�t�@�C���j
// =====================================================
// �U������
void Enemy02Etoh::attack()
{
	//pos_.x++;
	enemy_frame++;
	if (enemy_frame >= 100)
	{
		enemy_mode = GetRand(3);
		enemy_frame = 0;
	}
	//�ォ���Ɉړ��������ƃW�O�U�N�ړ�����
	switch (enemy_mode)
	{
	case ENEMY_UP:
		pos_.y -= 5;
		break;
	case ENEMY_DOWN:
		pos_.y += 5;
		break;
	case ENEMY_RIGHT:
		pos_.x += 5;
		break;
	case ENEMY_LEFT:
		pos_.x -= 5;
		break;
	}
	//��ʔ����ɏo�Ȃ�����
	if (pos_.x >= WINDOW_W)
	{
		pos_.x = WINDOW_W;
		enemy_mode = GetRand(3);
	}
	if (pos_.x <= 0)
	{
		pos_.x = 0;
		enemy_mode = GetRand(3);
	}
	if (pos_.y >= WINDOW_H)
	{
		pos_.y = WINDOW_H;
		enemy_mode = GetRand(3);
	}
	if (pos_.y <= 0)
	{
		pos_.y = 0;
		enemy_mode = GetRand(3);
	}

}

// �R���X�g���N�^
Enemy02Etoh::Enemy02Etoh() :
	EnemyBase("data/animation/enemy/enemy01.png")
	,enemy_frame(0)
{

}

// �f�X�g���N�^
Enemy02Etoh::~Enemy02Etoh()
{

}
