#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "Enemy12Yukioka.h"
// =====================================================
//	敵「金丸」クラス（ソースファイル）
//	 左右に移動する敵クラス
// =====================================================
// 攻撃処理
void Enemy12Yukioka::attack()
{
	//--------------------------------------
	// バウンド
	//--------------------------------------
	if (attack_mode_ == Bound)
	{
		power();
		frame_--;

		// 跳ね返る
		if (pos_.x < getR() ||
			pos_.x > WINDOW_W - getR())
		{
			move_speed_ *= -1;
		}
		if (pos_.y < getR() ||
			pos_.y > WINDOW_H - getR())
		{
			move_speed_ *= -1;
		}

		// ３秒経ったら向きを変える
		if (frame_ <= 0)
		{
			frame_ = 60 * 3;
			angle_ = GetRand(360);
		}

	}


	//--------------------------------------
	// トルネード
	//--------------------------------------
	if (attack_mode_ == Tornado)
	{
		power();
		angle_+= 0.5f;
		pos_.x += move_speed_;
		// 画面外に出ない
		if (pos_.x < getR() ||
			pos_.x > WINDOW_W - getR())
		{
			move_speed_ *= -1;
		}
	}
}

void Enemy12Yukioka::power()
{
	pos_.x += move_speed_ * cosf(angle_);
	pos_.y += move_speed_ * sinf(angle_);
}

// コンストラクタ
Enemy12Yukioka::Enemy12Yukioka() :
	EnemyBase("data/animation/enemy/enemy01.png")
{
	attack_mode_ = GetRand(10) % 2;
	move_speed_ = 10;
	angle_ = GetRand(360);
	frame_ = 60 * 3;
}

// デストラクタ
Enemy12Yukioka::~Enemy12Yukioka()
{

}
