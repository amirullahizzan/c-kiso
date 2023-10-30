#include "Enemy.h"

void Enemy::init()
{
	ghandle_ = LoadGraph("data/enemy.png");
	// 初期値のセット
	r_ = IMG_SIZE / 2;	// 当たり判定用に必要な半径の値をセット
	// 初期位置のセット
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