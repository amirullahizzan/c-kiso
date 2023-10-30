#pragma once
// ============================================
//	 Bulletクラス（ヘッダーファイル）
//	  弾1発を扱う
// ============================================
class Bullet
{
private:
	const double EX_RATE = 0.1;		// 画像拡大率

	const int IMG_SIZE_W	  = 120;// 画像幅（絵ひとつ分）
	const int IMG_SIZE_H	  = 120;// 画像高さ（絵ひとつ分）
	const int ANIMATION_W_MAX = 4;	// アニメーション 横の最大数
	const int ANIMATION_H_MAX = 3;	// アニメーション 縦の最大数

	Pos2  pos_;								// 座標
	float r_	   = 120 * (float)EX_RATE;	// サイズ
	bool  is_shot_ = false;					// 発射したかどうか

	/////////////////////////
	//	アニメーション関係
	/////////////////////////
	int	ghandle_		= -1;	// 画像
	int animation_frame = 0;	// アニメーション経過時間
	int	animation_x		= 0;	// アニメーションX
	int animation_y		= 0;	// アニメーションY
	
	void animationInit();					// アニメーションの初期化処理
	void animationLoad(const char* fname_);	// アニメーションの画像の読み込み処理
	void animationUpdate();					// アニメーションの更新処理
	void animationExit();					// アニメーションの終了処理
	int  getAnimationX() const
	{
		return animation_x;
	}
	int  getAnimationY() const
	{
		return animation_y;
	}

public:
	// ------------------------
	// コンストラクタ・デストラクタ
	// ------------------------
	Bullet();
	~Bullet();

	// ------------------------
	// メンバ関数
	// ------------------------
	void init();			// 初期化処理関数
	void update();			// 更新処理関数
	void render() const;	// 描画処理関数
	void exit();			// 終了処理関数
	
	// 弾を撃っている状態がどうか
	bool isShot() const
	{
		return is_shot_;
	}
	// 出現処理
	void setShot(const Pos2& pos)
	{
		if (isShot())
			return;

		pos_ = pos;
		is_shot_ = true;
		animationInit();
	}
	// 消去処理
	void setErase()
	{
		is_shot_ = false;
	}

	// ------------------------
	//	メンバ変数getter関数
	// ------------------------
	const Pos2& getPos() const
	{
		return pos_;
	}
	float getX()		 const
	{
		return pos_.x;
	}
	float getY()		 const
	{
		return pos_.y;
	}
	float getR()		 const
	{
		return r_;
	}

	//CUSTOM
};