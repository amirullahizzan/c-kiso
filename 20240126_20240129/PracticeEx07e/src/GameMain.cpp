#include "WinMain.h"
#include "Tree.h"
#include "RedBall.h"
#include "SnowMan.h"
#include "SnowFlake.h"
#include "Hit.h"

// =====================================================
//	グローバル変数
//	複数の関数で共通して使いたい変数はここに書く
// =====================================================
namespace
{
	const int OBJ_NUM = 15;
	int obj_count = 0;
	
	enum TreeDecorationEnum
	{
		RedBallE = 0, 
		SnowFlakeE = 1, 
		SnowmanE = 2
	};
	int obj_type = RedBallE;


	Tree* tree = nullptr;
	BaseObj* baseobj[OBJ_NUM] = {};
	//RedBall* redball = {};
}

// =====================================================
//		初期化
//	ゲーム開始直後に最初に1回だけ実行される関数
//	最初の値を変数に入れたいときに使う
// =====================================================
void GameInit()
{
	tree = new Tree();

}
// =====================================================
//		更新
//	ゲームが終了されるまで実行される関数
//	1秒間に約60回呼ばれる
//	1フレームで行う処理をここに書く
// =====================================================

void SpawnRandomizeDecoration(Pos mousePos)
{
	int randomizeType = GetRand(2);
	obj_type = randomizeType;
	switch (obj_type)
	{
	case RedBallE:
		for (int i = 0; i < OBJ_NUM; i++)
		{
			if (baseobj[i]) continue;
			baseobj[i] = new RedBall(mousePos);
			break;
		}
		break;

	case SnowFlakeE:
		for (int i = 0; i < OBJ_NUM; i++)
		{
			if (baseobj[i]) continue;
			baseobj[i] = new SnowFlake(mousePos);
			break;
		}

		break;

	case SnowmanE:
		for (int i = 0; i < OBJ_NUM; i++)
		{
			if (baseobj[i]) continue;
			baseobj[i] = new SnowMan(mousePos);
			break;
		}

		break;

	default:
		break;
	}


}

void SpawnObj(BaseObj* objtype, Pos mousePos)
{

}

void GameUpdate()
{
	tree->Update();
	if (IsKeyOn(KEY_INPUT_SPACE))
	{
		for (int i = 0; i < OBJ_NUM; i++)
		{
			delete baseobj[i];
			baseobj[i] = nullptr;
		}
	}


	for (int i = 0 ; i < OBJ_NUM;i++)
	{
	
	if (baseobj[i])
	{
		baseobj[i]->Update();
	}

	}

	if (obj_count >= OBJ_NUM) return;
	
	if (IsMouseOn(MOUSE_INPUT_LEFT))
	{
		obj_count++;
		Pos mousePos = { static_cast<float>(GetMouseX()) ,static_cast<float>(GetMouseY()) };
		SpawnRandomizeDecoration(mousePos);
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
	tree->Draw();
	for (int i = 0 ; i < OBJ_NUM; i++)
	{
		if (baseobj[i])
		{
		baseobj[i]->Draw();
		}
	}

	DrawFormatString(0,0,WHITE,"%d / 15 ", obj_count);
}
// =====================================================
//		終了
//	ゲームが終了する前に1回だけ実行される関数
//	何か最後に後片付けを行うときに使う
// =====================================================
void GameExit()
{
	if (tree != nullptr)
	{
		delete tree;
		tree = nullptr;
	}
}

