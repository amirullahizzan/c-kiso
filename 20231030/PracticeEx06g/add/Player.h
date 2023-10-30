#pragma once
// ============================================
//	 Playerクラス（ヘッダーファイル）
//	  キー操作での移動を行う
// ============================================
class Player
{
protected:
	//like public but accessible by Derived
	Pos2  pos_;			// 座標
	int   ghandle_ = 0;	// 画像
	float r_	   = 0;	// 半径
	const double EX_RATE = 1.0;	// 画像拡大率

private:
	

	int     damage_frame_ = 0;	// ダメージ時間の計測

public:
	// ------------------------
	// コンストラクタ・デストラクタ
	// ------------------------
	Player();
	~Player();

	// ------------------------
	// メンバ関数
	// ------------------------
	void init();			// 初期化処理関数
	void update();			// 更新処理関数
	void render() const;	// 描画処理関数
	void exit();			// 終了処理関数

	void setDamage();		// ダメージ処理を付加

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

};