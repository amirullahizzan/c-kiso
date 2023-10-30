#include "Enemy.h"

void Enemy::init()
{
	ghandle_ = LoadGraph("data/enemy.png");
	// �����l�̃Z�b�g
	r_ = IMG_SIZE / 2;	// �����蔻��p�ɕK�v�Ȕ��a�̒l���Z�b�g
	// �����ʒu�̃Z�b�g
	initPos();
}

void const Enemy::render()
{
	if (!isDestroyed)
	{
	DrawRotaGraphF(getX(), getY(), EX_RATE, 0, ghandle_, TRUE);
	}
}

void Enemy::spawn()
{
	isDestroyed = false;
}

void Enemy::destroy()
{
	if (!isDestroyed)
	{
		initPos();
		isDestroyed = true;
	}
}

void Enemy::moveWave()
{
	pos_.y+=4;
}

bool Enemy::getIsDestroyed()
{
	return isDestroyed;
}