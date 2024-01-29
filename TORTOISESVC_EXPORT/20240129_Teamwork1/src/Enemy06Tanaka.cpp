#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "Enemy06Tanaka.h"
// =====================================================
//	敵「田中」クラス（ソースファイル）
//	 斜めに移動する敵クラス
// =====================================================
// 攻撃処理
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

// コンストラクタ
Enemy06Tanaka::Enemy06Tanaka() :
	EnemyBase("data/animation/enemy/enemy03.png")
{

}

// デストラクタ
Enemy06Tanaka::~Enemy06Tanaka()
{

}
