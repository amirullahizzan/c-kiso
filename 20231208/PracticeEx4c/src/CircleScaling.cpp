#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "CircleBase.h"
#include "CircleScaling.h"
// =====================================================
//	拡縮する円クラス（ソースファイル）
//	 拡大縮小する円
// =====================================================
// -----------------------------------------------------
//	コンストラクタ
//	 オブジェクトを宣言時に円の最大値を決められる
//	 指定がなければ、デフォルト引数にある50が使用される
// -----------------------------------------------------
CircleScaling::CircleScaling(float size) :
	CircleBase(size),
	MAX_SIZE(size)
{

}

// -----------------------------------------------------
//	更新処理
// -----------------------------------------------------
void CircleScaling::update()
{
	setColor(SKYBLUE);

	if (target_ != nullptr)
	{
		pos_ = target_->getPos();
	}

	++angle_;
	size_ = sinf(PI / 2 / 60 * angle_) * MAX_SIZE;
}

