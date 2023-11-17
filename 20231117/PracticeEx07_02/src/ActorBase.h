#pragma once
// -----------------------------------------------------
//	キャラクター基底クラス（ヘッダーファイル）
//	 キー入力をしてアニメーションをするキャラクターを
//	 管理するクラス
// -----------------------------------------------------
class ActorBase
{
public:
	void render();						 // 描画処理
	void exit();						 // 終了処理

	virtual void init()
	{

	}		// 初期化処理
	virtual void update()
	{
		playAnimation();
		Move();
		posReset();
	}	// 更新処理
	virtual void posReset()
	{
	
	}

protected:
	virtual void Move()
	{

	}

	Pos pos_;							 // 座標
	DIR dir_	 = DIR::DOWN;			 // 向き
	int ghandle_ = -1;					 // アニメーション画像

	void playAnimation();				 // アニメーション再生用
	bool attachImage(const char* fname); // アニメーション画像を付ける

	int GetRandomTimer()
	{
		return GetRand(80)+80;
	}


private:
	// ==================================
	//	 アニメーション処理用定数一覧
	// ==================================
	//	画像切り抜き順番の一覧
	const int AnimationOrderList[4] =
	{
		1, 0, 1, 2
	};
	//	画像切り抜き順番の一覧配列のサイズ
	const int AnimationOrderSize = sizeof(AnimationOrderList) / sizeof(*AnimationOrderList);
	//	アニメーション速度
	const int AnimationSpeed = 10;

	int animation_frame_ = 0;	// アニメーションカウンター
	int animation_index_ = 0;	// アニメーション処理

};	// class ActorBase
