#pragma once
// =====================================================
//	アニメーションキャラクター管理クラス（ヘッダーファイル）
//	 ゲーム中のアニメーションをするキャラクターの基底クラス
// =====================================================
class ActorBase
{
private:
	AnimationImage* anim_	   = nullptr;
	bool			anim_play_ = false;

protected:
	Pos	   pos_	  = { 0, 0 };	// 座標
	DIR	   dir_	  = DIR::DOWN;	// 向き
	double scale_ = 1.0;		// 拡縮率
	double angle_ = 0;			// 回転角度（度で指定）

	virtual void updateBody() = 0;

	// アニメーション再生中かどうか
	bool isAnimPlay() const
	{
		return anim_play_;
	}
	// アニメーション再生
	void animPlay()
	{
		anim_play_ = true;
	}
	// アニメーション停止
	void animStop()
	{
		anim_play_ = false;
		anim_->reset();
	}

public:
	ActorBase(std::string img_path, int anim_speed = 20);
	virtual ~ActorBase();

			void update();
	virtual void render();

	const Pos& getPos() const
	{
		return pos_;
	}
	const DIR& getDir() const
	{
		return dir_;
	}
	// サイズの取得
	const float getSize() const
	{
		return (float)(IMG_SIZE * scale_);
	}
	// 半径の取得
	const float getR() const
	{
		return getSize() / 2;
	}
	// 何かに当たった
	virtual void onHit(std::string tag);

};