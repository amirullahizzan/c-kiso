#include "WinMain.h"
#include "Enemy.h"

// ------------------------------------------
//	敵クラス（実装部: ソースファイル）
// ------------------------------------------
// コンストラクタ
Enemy::Enemy()
{
	Init();
}

// 初期化処理
void Enemy::Init()
{
	// 初期値の設定
	r_			  = 30;
	color_		  = GREEN;
	is_damage_	  = false;
	damage_frame_ = 0;
}

// 更新処理
void Enemy::Update()
{
	if (IsDamage())
	{
		--damage_frame_;
		if (damage_frame_ <= 0)
		{
			damage_frame_ = 0;
			is_damage_ = false;
		}
		return;
	}
	// ダメージ中は以下処理を行わない

}

// 描画処理
void Enemy::Draw()
{
	bool is_fill = TRUE;
	if (IsDamage())
	{
		is_fill = (damage_frame_ % 5 == 0) ? TRUE : FALSE;
	}
	DrawCircleAA(x_, y_, r_, 64, color_, is_fill);

}

// 座標指定関数
void Enemy::SetPos(float x, float y)
{
	x_ = x;
	y_ = y;
}

// 座標X取得関数
float Enemy::GetPosX() const
{
	return x_;
}

// 座標Y取得関数
float Enemy::GetPosY() const
{
	return y_;
}

// 半径取得関数
float Enemy::GetR() const
{
	return r_;
}

// ダメージ中かどうか
bool Enemy::IsDamage() const
{
	return is_damage_;
}

// ダメージを与える
void Enemy::SetDamage()
{
	if (IsDamage())
		return;

	// ダメージ中は新たにダメージを入れない
	is_damage_ = true;
	damage_frame_ = 60 * 1;
}
