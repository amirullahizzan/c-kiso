#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "EnemyKanamaru.h"
// =====================================================
//	敵「金丸」クラス（ソースファイル）
//	 左右に移動する敵クラス
// =====================================================
// 攻撃処理
void EnemyKanamaru::attack()
{
	pos_.x += move_speed_;
	if (pos_.x < getR() || 
		pos_.x > WINDOW_W - getR())
	{
		move_speed_ *= -1;
	}
}

// 攻撃シーン: 描画
void EnemyKanamaru::attackRender()
{
	DrawCircleAA(WINDOW_W / 2, WINDOW_H / 2, 40, 64, RED, TRUE);
}

// コンストラクタ
EnemyKanamaru::EnemyKanamaru() :
	EnemyBase("data/animation/enemy/enemy04.png")
{

}

// デストラクタ
EnemyKanamaru::~EnemyKanamaru()
{

}
