#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
// =====================================================
//	アニメーションキャラクター管理クラス（ヘッダーファイル）
//	 ゲーム中のアニメーションをするキャラクターの基底クラス
// =====================================================
// コンストラクタ
//	画像のパスを指定する
ActorBase::ActorBase(std::string img_path, int anim_speed)
{
	anim_ = new AnimationImage();
	anim_->load(img_path.c_str());
	anim_->attach({ {1, 0, 1, 2}, anim_speed, true });
	animPlay();

}

// デストラクタ
ActorBase::~ActorBase()
{
	delete anim_;
	anim_ = nullptr;

}

// 更新処理
void ActorBase::update()
{
	assert(anim_ != nullptr);
	if (isAnimPlay())
	{
		anim_->update();
	}

	updateBody();
}

// 描画処理
void ActorBase::render()
{
	DrawRectRotaGraphF(getPos().x, getPos().y,
					   anim_->get() * IMG_SIZE,
					   getDir() * IMG_SIZE,
					   IMG_SIZE, IMG_SIZE,
					   scale_, D2R(angle_),
					   anim_->getGhandle(),
					   TRUE);

#ifndef NDEBUG
	DrawCircleAA(getPos().x, getPos().y, getR(), 32, RED, FALSE);
#endif // !NDEBUG

}

// 何かに当たった
void ActorBase::onHit(std::string tag)
{
	// ここでは何もしない
}
