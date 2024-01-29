#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "Enemy07Hamaguchi.h"
// =====================================================
//	敵「濵口」クラス（ソースファイル）
//	 左右に移動する敵クラス
// =====================================================
// 攻撃処理
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

// コンストラクタ
Enemy07Hamaguchi::Enemy07Hamaguchi() :
	EnemyBase("data/animation/enemy/enemy04.png")
{

}

// デストラクタ
Enemy07Hamaguchi::~Enemy07Hamaguchi()
{

}
