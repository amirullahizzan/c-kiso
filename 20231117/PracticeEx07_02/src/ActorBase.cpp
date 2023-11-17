#include "WinMain.h"
#include "ActorBase.h"
// -----------------------------------------------------
//	キャラクター基底クラス（ソースファイル）
//	 キー入力をしてアニメーションをするキャラクターを
//	 管理するクラス
// -----------------------------------------------------
// =====================================================
//	描画処理
// =====================================================
void ActorBase::render()
{
	Pos src_pos = 
	{
		AnimationOrderList[animation_index_] * IMG_SIZE, dir_ * IMG_SIZE
	};
	DrawRectRotaGraph(pos_.x, pos_.y,		// 描画位置
					  src_pos.x, src_pos.y,	// 画像切り抜き位置
					  IMG_SIZE, IMG_SIZE,
					  1, 0,
					  ghandle_, TRUE);
}
// =====================================================
//	終了処理
// =====================================================
void ActorBase::exit()
{
	if (ghandle_ == -1)
		return;

	DeleteGraph(ghandle_);
}
// =====================================================
//	アニメーション画像を付ける
//	 引数は画像ファイル名にする
//	 画像の読み込みに失敗したときはfalseを返す
// =====================================================
bool ActorBase::attachImage(const char* fname)
{
	// すでに何らかの画像がある場合は画像データを破棄する
	if (ghandle_ != -1)
	{
		DeleteGraph(ghandle_);
	}

	ghandle_ = LoadGraph(fname);

	return ghandle_ != -1;
}
// =====================================================
//	アニメーション再生処理
// =====================================================
void ActorBase::playAnimation()
{
	++animation_frame_;
	animation_frame_ %= AnimationSpeed;
	if (animation_frame_ == 0)
	{
		++animation_index_;
		animation_index_ %= AnimationOrderSize;
	}
}
