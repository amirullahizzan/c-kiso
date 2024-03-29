#include "WinMain.h"
#include "SceneBase.h"
// =============================================
//	全シーンの基底クラス（ソースファイル）
//	  全シーンの共通する部分があるクラス
// =============================================
// ----------------------------------------------------
//	初期化処理
// ----------------------------------------------------
void SceneBase::init()
{

}
// ----------------------------------------------------
//	更新処理
//	  is_next_がtrueになるとフェードアウト処理が開始する
//	  シーンが切り替わるときにtrueを返し、
//	  それ以外はfalseを返す
// ----------------------------------------------------
bool SceneBase::update()
{
	if (is_next_ == true)
	{
		// フェードアウト処理の開始
		alpha_ += (255 - alpha_) * 0.05f;
		if (alpha_ > 250)
		{
			alpha_ = 250;
			return true;
		}
		return false;
	}

	updateBody();

	return false;
}
// ----------------------------------------------------
//	更新（本体）処理
//	  SceneBaseクラスでは何もすることはない
// ----------------------------------------------------
void SceneBase::updateBody()
{

}
// ----------------------------------------------------
//	描画処理
//	  フェードアウト処理を行う
// ----------------------------------------------------
void SceneBase::render()
{
	renderBody();

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)alpha_);
	DrawBox(0, 0, WINDOW_W, WINDOW_H, BLACK, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}
// ----------------------------------------------------
//	描画（本体）処理
//	  SceneBaseクラスでは何もすることはない
// ----------------------------------------------------
void SceneBase::renderBody()
{

}
// ----------------------------------------------------
//	終了処理
// ----------------------------------------------------
void SceneBase::exit()
{
	alpha_   = 0;
	is_next_ = false;

}
