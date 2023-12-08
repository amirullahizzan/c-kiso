#pragma once
// *************************************************************
//	編集禁止
// *************************************************************
// =====================================================
//	アニメーションキャラクタークラス（ヘッダーファイル）
//	 アニメーションするキャラクターを管理するクラス
// =====================================================
class ActorBase
{
private:
	AnimationImage* anim_ = nullptr;	// アニメーション
	bool is_target_		  = false;		// 現在ターゲットかどうか

protected:
	Pos pos_ = { 0, 0 };	// 座標
	DIR dir_ = DIR::DOWN;	// 向き

	virtual void updateBody() = 0;	// 更新処理本体

public:
	virtual ~ActorBase();

	virtual void init(const char* fname); // 初期化処理
	virtual void update() final;		  // 更新処理（オーバーライド不可）
	virtual void render();				  // 描画処理
	virtual void exit() final;			  // 終了処理（オーバーライド不可）

	// 座標の設定
	void setPos(const Pos& pos)
	{
		pos_ = pos;
	}
	// 座標の取得
	Pos getPos() const
	{
		return pos_;
	}
	// ターゲットです
	void setTarget()
	{
		is_target_ = true;
	}
	// ターゲットではないです
	void unsetTarget()
	{
		is_target_ = false;
	}

};
