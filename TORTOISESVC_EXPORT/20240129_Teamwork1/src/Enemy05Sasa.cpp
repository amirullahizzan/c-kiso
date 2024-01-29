#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "Enemy05Sasa.h"
// =====================================================
//	敵「佐々」クラス（ソースファイル）
//	 左右に移動する敵クラス
// =====================================================
// 攻撃処理
void Enemy05Sasa::attack()
{
	pos_.x += move_speed_;
	if (pos_.x < getR() || pos_.x > WINDOW_W - getR())
	{
		move_speed_ *= -1;
	}

	pos_.y += move_speed_;
	if (pos_.y < getR() || pos_.y > WINDOW_H - getR())
	{
		move_speed_ *= -1;
	}
}

// コンストラクタ
Enemy05Sasa::Enemy05Sasa() :
	EnemyBase("data/animation/enemy/enemy04.png")
{

}

// デストラクタ
Enemy05Sasa::~Enemy05Sasa()
{

}
