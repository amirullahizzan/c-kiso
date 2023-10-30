#include "../src/WinMain.h"
#include "Player.h"
// ============================================
//	 Playerクラス（ソースファイル）
//	  キー操作での移動を行う
// ============================================
// コンストラクタ
Player::Player()
{
}

// デストラクタ
Player::~Player()
{
}

// 初期化処理関数
//	GameInit関数内で1回だけ呼ぶ
//	または、ゲームをリセットする際にexitメンバ関数を呼んだ後に呼び出して
//	オブジェクトを初期状態に戻す際に呼ぶ
void Player::init()
{
	// 画像の読み込み
	ghandle_ = LoadGraph("data/red.png");
	// 初期値のセット
	r_ = IMG_SIZE / 2;	// 当たり判定用に必要な半径の値をセット
	// 初期位置のセット
	pos_ = Pos2((float)WINDOW_W / 2, (float)WINDOW_H - r_ * 2);

	damage_frame_ = 0;
}

// 更新処理関数
//	GameUpdate関数内で毎フレーム呼ぶ
void Player::update()
{
	if (damage_frame_ > 0)
	{
		--damage_frame_;
	}

	// 上下左右の矢印キーで移動
	if (IsKeyRepeat(KEY_INPUT_RIGHT))
	{
		pos_.x += 5;
	}
	if (IsKeyRepeat(KEY_INPUT_LEFT))
	{
		pos_.x -= 5;
	}
	if (IsKeyRepeat(KEY_INPUT_DOWN))
	{
		pos_.y += 5;
	}
	if (IsKeyRepeat(KEY_INPUT_UP))
	{
		pos_.y -= 5;
	}

	// 画面範囲外に行かないようにする処理
	//	メンバ変数の値を参照する時にはなるべくメンバ関数を使用する
	if (getX() < getR())
	{
		pos_.x = getR();
	}
	if (getY() < getR())
	{
		pos_.y = getR();
	}
	if (getX() > WINDOW_W - getR())
	{
		pos_.x = WINDOW_W - getR();
	}
	if (getY() > WINDOW_H - getR())
	{
		pos_.y = WINDOW_H - getR();
	}
}

// 描画処理関数
//	GameDraw関数内で毎フレーム呼ぶ
//	この関数内ではメンバ変数を変更しないので、const付きメンバ関数とする
void Player::render() const
{
	if (damage_frame_ % 3 != 0)
		return;

	// DrawGraph関数 … 画像左上座標
	// DrawRotaGraph関数 … 画像中心座標(当たり判定の計算上こちらを使用する)
	DrawRotaGraphF(getX(), getY(), EX_RATE, 0, ghandle_, TRUE);
}

// 終了処理関数
//	GameExit関数内で1回だけ呼ぶ
//	または、ゲームをリセットする際にinitメンバ関数を呼ぶ前に呼び出して
//	オブジェクトを初期状態に戻す際に呼ぶ
void Player::exit()
{
	// 使用した画像の削除
	DeleteGraph(ghandle_);
}

// ダメージの付加
void Player::setDamage()
{
	if (damage_frame_ > 0)
		return;

	damage_frame_ = (int)(60 * 1.5f);
}
