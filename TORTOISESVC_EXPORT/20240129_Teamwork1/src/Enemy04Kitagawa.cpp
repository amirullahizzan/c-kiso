#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "Enemy04Kitagawa.h"
// =====================================================
//	敵「北川」クラス（ソースファイル）
//	 
// =====================================================
// 攻撃処理
void Enemy04Kitagawa::attack()
{
	pos_.y += speed_y;
	pos_.x += speed_x;

	time++;

	if (pos_.y <= getR() || pos_.y >= WINDOW_H - getR())
	{
		speed_y *= -1.0;
	}

	if (pos_.x <= getR() || pos_.x >= WINDOW_W - getR())
	{
		speed_x *= -1.0;
	}

	if (time >= 60 * 10)
	{
		if (speed_y < 20)
		{
			speed_y += 1;
		}

		if (speed_x < 20)
		{
			speed_x += 1;
		}
	}




}

// コンストラクタ
Enemy04Kitagawa::Enemy04Kitagawa() :
	EnemyBase("data/animation/enemy/enemy04.png")
{

}

// デストラクタ
Enemy04Kitagawa::~Enemy04Kitagawa()
{

}
