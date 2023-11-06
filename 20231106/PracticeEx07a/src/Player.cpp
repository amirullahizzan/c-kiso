#include "WinMain.h"
#include "Player.h"

// ------------------------------------------
//	プレイヤークラス（実装部: ソースファイル）
// ------------------------------------------
// コンストラクタ
Player::Player()
{
	Init();
}

// 初期化処理
void Player::Init()
{
	// 初期値の設定
	r_			  = 30;
	x_			  = WINDOW_W / 2;
	y_			  = WINDOW_H - r_ * 2;
	color_		  = PINK;
	is_damage_	  = false;
	damage_frame_ = 0;

}

// 更新処理
void Player::Update()
{
	if (IsDamage())
	{
		--damage_frame_;
		if (damage_frame_ <= 0)
		{
			damage_frame_ = 0;
			is_damage_	  = false;
		}
	}

	// キー操作での移動
	if (IsKeyRepeat(KEY_INPUT_RIGHT))
	{
		x_ += 5;
	}
	else if (IsKeyRepeat(KEY_INPUT_LEFT))
	{
		x_ -= 5;
	}
	else if (IsKeyRepeat(KEY_INPUT_UP))
	{
		y_ -= 5;
	}
	else if (IsKeyRepeat(KEY_INPUT_DOWN))
	{
		y_ += 5;
	}

	// 座標が範囲外にいかないようにする
	if (x_ > WINDOW_W - r_)
	{
		x_ = WINDOW_W - r_;
	}
	if (x_ < r_)
	{
		x_ = r_;
	}
	if (y_ > WINDOW_H - r_)
	{
		y_ = WINDOW_H - r_;
	}
	if (y_ < r_)
	{
		x_ = r_;
		//y_ = r_; ??
	}
}

// 描画処理
void Player::Draw()
{
	bool is_fill = TRUE;
	if (IsDamage())
	{
		is_fill = (damage_frame_ % 5 == 0) ? TRUE : FALSE;
	}
	DrawCircleAA(x_, y_, r_, 64, color_, is_fill);

}

// 座標X取得関数
float Player::GetPosX() const
{
	return x_;
}

// 座標Y取得関数
float Player::GetPosY() const
{
	return y_;
}

// 半径取得関数
float Player::GetR() const
{
	return r_;
}

// ダメージ中かどうか
bool Player::IsDamage() const
{
	return is_damage_;
}

// ダメージを与える
void Player::SetDamage()
{
	if (IsDamage())
		return;

	// ダメージ中は新たにダメージを入れない
	is_damage_    = true;
	damage_frame_ = 60 * 1;
}
