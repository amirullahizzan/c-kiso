#pragma once
// -----------------------------------------------------
//	犬クラス（ヘッダーファイル）
//	 キー入力で移動するキャラクタークラス
// -----------------------------------------------------
class ActorDog : public ActorBase
{
private:
	void posReset();			// 座標調整

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

public:
	void init() override;		// 初期化処理
	void update()override;	// 更新処理

};