#include "WinMain.h"
#include "PlayerBullet.h"
// ------------------------------------------
//	プレイヤー弾クラス（実装部: ソースファイル）
// ------------------------------------------
// コンストラクタ
PlayerBullet::PlayerBullet()
{
	Init();

}

// 初期化処理
void PlayerBullet::Init()
{
	// 初期値の設定
	r_		 = 10;
	color_	 = YELLOW;
	is_shot_ = false;

}

// 更新処理
void PlayerBullet::Update()
{
	if (!IsShot())
		return;

	y_ -= 8;
	if (y_ < -r_ * 2 )
	{
		is_shot_ = false;
	}

}

// 描画処理
void PlayerBullet::Draw()
{
	if (!IsShot())
		return;

	DrawCircleAA(x_, y_, r_, 64, color_, TRUE);

}

// 座標指定関数
void PlayerBullet::SetPos(float x, float y)
{
	x_		 = x;
	y_		 = y;
	is_shot_ = true;

}

// 座標X取得関数
float PlayerBullet::GetPosX() const
{
	return x_;
}

// 座標Y取得関数
float PlayerBullet::GetPosY() const
{
	return y_;
}

// 半径取得関数
float PlayerBullet::GetR() const
{
	return r_;
}

// 弾を撃ったかどうか
bool PlayerBullet::IsShot() const
{
	return is_shot_;
}
