#include "../src/WinMain.h"
#include "Bullet.h"
// ============================================
//	 Bulletクラス（ソースファイル）
//	  弾1発を扱う
// ============================================
// アニメーションの初期化処理
void Bullet::animationInit()
{
	animation_frame = 0;
	animation_x		= 0;
	animation_y		= 0;
}
// アニメーションの画像の読み込み処理
void Bullet::animationLoad(const char* fname_)
{
	// すでに画像が読み込まれている場合、LoadGraphする前に画像を破棄する
	// これをしないとメモリ上に画像が残り続けて最終的にクラッシュする
	if (ghandle_ != -1)
	{
		animationExit();
	}

	ghandle_ = LoadGraph(fname_);
}
// アニメーションの更新処理
void Bullet::animationUpdate()
{
	++animation_frame;
	animation_frame %= 3;
	if (animation_frame == 0)
	{
		++animation_x;
		animation_x %= ANIMATION_W_MAX;
		if (animation_x != 0)
			return;

		++animation_y;
		if (animation_y >= ANIMATION_H_MAX)
		{
			animation_y = ANIMATION_H_MAX;
		}
	}
}
// アニメーションの終了処理
void Bullet::animationExit()
{
	DeleteGraph(ghandle_);
}

// コンストラクタ
Bullet::Bullet()
{
}

// デストラクタ
Bullet::~Bullet()
{
}

// 初期化処理関数
//	GameInit関数内で1回だけ呼ぶ
//	または、ゲームをリセットする際にexitメンバ関数を呼んだ後に呼び出して
//	オブジェクトを初期状態に戻す際に呼ぶ
void Bullet::init()
{
	// 画像の読み込み
	animationLoad("data/bullet_red.png");
	// 初期値のセット
	r_ = (120 * (float)EX_RATE) / 2.0f;
	// 初期位置のセット
	pos_ = Pos2((float)WINDOW_W / 2, (float)WINDOW_H - r_ * 2);
	// 発射状態を「未発射」にする
	is_shot_ = false;
}

// 更新処理関数
//	GameUpdate関数内で毎フレーム呼ぶ
void Bullet::update()
{
	if (!isShot())
		return;

	animationUpdate();

	pos_.y = pos_.y - 8;
	if (getY() < -getR())
	{
		setErase();
	}

}

// 描画処理関数
//	GameDraw関数内で毎フレーム呼ぶ
//	この関数内ではメンバ変数を変更しないので、const付きメンバ関数とする
void Bullet::render() const
{
	if (!isShot())
		return;

	DrawRectRotaGraph((int)getX(), (int)getY(),
					  IMG_SIZE_W * getAnimationX(), IMG_SIZE_H * getAnimationY(),
					  IMG_SIZE_W, IMG_SIZE_H,
					  EX_RATE, 0, ghandle_, TRUE);
}

// 終了処理関数
//	GameExit関数内で1回だけ呼ぶ
//	または、ゲームをリセットする際にinitメンバ関数を呼ぶ前に呼び出して
//	オブジェクトを初期状態に戻す際に呼ぶ
void Bullet::exit()
{
	animationExit();

}
