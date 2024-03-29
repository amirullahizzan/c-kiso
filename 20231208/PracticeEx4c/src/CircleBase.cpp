// *************************************************************
//	編集禁止
// *************************************************************
#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "CircleBase.h"
// =====================================================
//	円の基底クラス（ソースファイル）
//	 すべての円の基本情報を管理するクラス
// =====================================================
// -----------------------------------------------------
//	コンストラクタ
//	 オブジェクトを宣言時に円の最大値を決められる
// -----------------------------------------------------
CircleBase::CircleBase(float size) :
	size_(size)
{

}

// -----------------------------------------------------
//	描画処理
// -----------------------------------------------------
void CircleBase::render()
{
	DrawCircleAA(pos_.x, pos_.y, size_, 64, color_, is_fill_);
}
