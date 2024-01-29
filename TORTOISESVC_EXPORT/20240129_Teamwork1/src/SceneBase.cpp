#include "WinMain.h"
#include "SceneBase.h"
// =====================================================
//	全てのシーンの基底クラス（ソースファイル）
//	 各シーンではupdateとrenderをオーバーライドする
// =====================================================
// コンストラクタ
//	シーン名を指定する
SceneBase::SceneBase(std::string name) :
	name_(name)
{

}
// デストラクタ
SceneBase::~SceneBase()
{

}

// 描画処理
void SceneBase::render()
{
#ifndef NDEBUG
	//printfDx("シーン: %s\n", name_.c_str());
#endif // !NDEBUG

}

// 次のシーン番号を返す
SCENE SceneBase::getNext() const
{
	return SCENE::TITLE;
}
