#include "WinMain.h"
#include "FontManager.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "Player.h"
#include "Enemies.h"
#include "EnemyManager.h"
#include "SceneBase.h"
#include "SceneTitle.h"
#include "SceneCredit.h"
#include "SceneGameMain.h"

// =====================================================
//	グローバル変数
// =====================================================
namespace
{
	// 変数
	SceneBase* scene	= nullptr;		// 現在のシーン
	SCENE	   scene_no = SCENE::TITLE;	// シーン番号
	float	   alpha	= 0;			// フェードイン/フェードアウト用アルファ値
	int		   action	= 0;			// 0: フェードイン, 1: 更新処理, 2: フェードアウト

	// 関数
	SceneBase* sceneFactory();			// シーン作成

}

// =====================================================
//		初期化
// =====================================================
void GameInit()
{
	if (scene != nullptr)
	{
		GameExit();
	}

	scene	 = new SceneTitle();
	scene_no = SCENE::TITLE;
	alpha	 = 255;
	action	 = 0;
}
// =====================================================
//		更新
// =====================================================
void GameUpdate()
{
	SCENE tmp_scene_no = scene_no;	// 現在のシーン番号を入れる
	switch (action)
	{
	case 0:
		alpha += (0 - alpha) * 0.075f;
		if (alpha < 10)
		{
			alpha  = 0;
			action = 1;
		}
		break;
	case 1:
		if (scene->update() == true)
		{
			scene_no = scene->getNext();
		}
		if (tmp_scene_no != scene_no)
		{
			// 更新処理後に、tmp_scene_noと現在のscene_noと違う場合は、
			// シーンの切り替えが発生する
			action = 2;
		}
		break;
	case 2:
		alpha += (255 - alpha) * 0.075f;
		if (alpha > 250)
		{
			alpha  = 255;
			action = 0;
			delete scene;
			scene = nullptr;

			scene = sceneFactory();
		}
		break;
	}
}
// =====================================================
//		描画
// =====================================================
void GameDraw()
{
	scene->render();

	// FO/FI用
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)alpha);
	DrawFillBox(0, 0, WINDOW_W, WINDOW_H, BLACK);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}
// =====================================================
//		終了
// =====================================================
void GameExit()
{
	if (scene != nullptr)
	{
		delete scene;
		scene = nullptr;
	}
}

namespace
{
	// シーン作成用関数
	SceneBase* sceneFactory()
	{
		switch (scene_no)
		{
		case TITLE:
			return new SceneTitle();
		case CREDIT:
			return new SceneCredit();
		case GAME_MAIN:
			return new SceneGameMain();
		}

		return nullptr;
	}
}