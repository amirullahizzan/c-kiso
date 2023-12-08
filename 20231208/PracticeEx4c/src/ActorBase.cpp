// *************************************************************
//	編集禁止
// *************************************************************
#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
// =====================================================
//	アニメーションキャラクタークラス（ソースファイル）
//	 アニメーションするキャラクターを管理するクラス
// =====================================================
// -----------------------------------------------------
//	デストラクタ
// -----------------------------------------------------
ActorBase::~ActorBase()
{
	exit();
}

// -----------------------------------------------------
//	初期化処理
//	 引数には画像のファイルパスを指定する
// -----------------------------------------------------
void ActorBase::init(const char* fname)
{
	// アニメーションデータの確保（生成）
	anim_ = new AnimationImage();
	// 画像の読み込み
	anim_->load(fname);
	// アニメーションデータの付与({ アニメーション順番 }, 再生速度)
	anim_->attach({ {1, 0, 1, 2}, 20 });
}

// -----------------------------------------------------
//	更新処理
//	 派生クラスでオーバーライドすることはできないため、
//	 各派生クラスで更新処理がある場合、updateBody関数へ
// -----------------------------------------------------
void ActorBase::update()
{
	assert(anim_ != nullptr);
	anim_->update();

	updateBody();
}

// -----------------------------------------------------
//	描画処理
//	 x, y座標は、画像の中心となる
// -----------------------------------------------------
void ActorBase::render()
{
	DrawRectRotaGraphF(pos_.x, pos_.y,
					   anim_->get() * IMG_SIZE,
					   dir_ * IMG_SIZE,
					   IMG_SIZE, IMG_SIZE,
					   1, 0,
					   anim_->getGhandle(),
					   TRUE);
}

// -----------------------------------------------------
//	終了処理
//	 使用したアニメーションクラスのオブジェクトを解放する
// -----------------------------------------------------
void ActorBase::exit()
{
	delete anim_;
	anim_ = nullptr;
}
