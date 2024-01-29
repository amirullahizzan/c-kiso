#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "Enemy01Izzan.h"
// =====================================================
//	敵「ZAN」クラス（ソースファイル）
//	 左右に移動する敵クラス
// =====================================================
// 攻撃処理
void Enemy01Izzan::attack()
{
	EnemyAI();
	SpinEnemy();
	EnlargeSpriteAI();

	printfDx("dist : %f\n\n\n", getDist(target_ptr_->getPos(), pos_));
	printfDx("spinttimer  : %d\n\n\n", spinTimer);
}

void Enemy01Izzan::SpinEnemy()
{
	angle_ += 0.5f;
	spinTimer++;
	const int SPIN_TIME = 16;
	if (spinTimer == SPIN_TIME * 0)
	{
	dir_ = UP;
	}
	else if(spinTimer == SPIN_TIME * 1)
	{
	dir_ = RIGHT;
	}
	else if(spinTimer == SPIN_TIME * 2)
	{
	dir_ = DOWN;
	}
	else if (spinTimer == SPIN_TIME * 3)
	{
	dir_ = LEFT;
	}
	else if (spinTimer == SPIN_TIME * 4)
	{
		spinTimer = -1;
	}
}

void Enemy01Izzan::EnlargeSpriteAI()
{
	if (target_ptr_)
	{
		if (getDist(target_ptr_->getPos(), pos_) < 125.0f)
		{
			scale_ = 2.0f;
		}
		else
		{
			scale_ = 0.8f;
		}

	}
}

void Enemy01Izzan::EnemyAI()
{
	
		if (target_ptr_ && getDist(target_ptr_->getPos(), pos_) < 125.0f)
		{
			isPlayerCloseTriggered = true;
		}
		else
		{
			//isPlayerCloseTriggered = true;
		}

		if (isPlayerCloseTriggered)
		{
			pos_.y += move_speed_y;
			if (pos_.y < getR() ||
				pos_.y > WINDOW_H - getR())
			{
				move_speed_y *= -1;
			}
		}
		else
		{
			pos_.x += move_speed_x;
			if (pos_.x < getR() ||
				pos_.x > WINDOW_W - getR())
			{
				move_speed_x *= -1;
			}
		}
}

// コンストラクタ
Enemy01Izzan::Enemy01Izzan() :
	EnemyBase("data/animation/player/player08.png")
{

}

// デストラクタ
Enemy01Izzan::~Enemy01Izzan()
{

}
