#include "WinMain.h"
#include "SceneBase.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"
// =====================================================
//	グローバル変数
//	複数の関数で共通して使いたい変数はここに書く
// =====================================================
namespace
{
	int sceneNum = 0;
	Scene1 scene1;
	Scene2 scene2;
	Scene3 scene3;

	void ChangeScene(SceneBase& now, SceneBase& next)
	{
		now.exit();
		next.init();
	}
	
}

// =====================================================
//		初期化
//	ゲーム開始直後に最初に1回だけ実行される関数
//	最初の値を変数に入れたいときに使う
// =====================================================
void GameInit()
{
	scene1.init();
	scene2.init();
	scene3.init();

}
// =====================================================
//		更新
//	ゲームが終了されるまで実行される関数
//	1秒間に約60回呼ばれる
//	1フレームで行う処理をここに書く
// =====================================================
void GameUpdate()
{
	switch (sceneNum)
	{
	case 0:
		scene1.init();
		if (scene1.update())
		{
			ChangeScene(scene1, scene2);
			sceneNum += 1;
		}
		break;
	case 1:
		if (scene2.update())
		{
			ChangeScene(scene2, scene3);
			sceneNum += 1;
		}
		break;
	case 2:
		if (scene3.update())
		{
			ChangeScene(scene3, scene1);
			sceneNum = 0;
		}
		break;
	}

}
// =====================================================
//		描画
//	ゲームが終了されるまで実行される関数
//	1秒間に約60回呼ばれる
//	GameUpdate関数が実行された後に実行される関数
// =====================================================
void GameDraw()
{
	switch (sceneNum)
	{
	case 0:
	scene1.render();
		break;
	case 1:
	scene2.render();
		break;
	case 2:
	scene3.render();
		break;
	}
	printfDx("timer %d",scene3.timer);
}
// =====================================================
//		終了
//	ゲームが終了する前に1回だけ実行される関数
//	何か最後に後片付けを行うときに使う
// =====================================================
void GameExit()
{

}
