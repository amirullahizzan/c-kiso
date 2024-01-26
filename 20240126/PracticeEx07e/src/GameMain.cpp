#include "WinMain.h"
#include "Tree.h"
#include "RedBall.h"
#include "Hit.h"

// =====================================================
//	グローバル変数
//	複数の関数で共通して使いたい変数はここに書く
// =====================================================
namespace
{
	const int OBJ_NUM = 15;
	int obj_count = 0;

	Tree* tree = nullptr;
	RedBall* redball[OBJ_NUM] = {};
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
	int randomizer = GetRand(3);
	switch (randomizer)
	{
	case 0:
		redball = new RedBall(mousePos);
		break;
	case 1:
		redball = new RedBall(mousePos);
		break;
	case 2:
		redball = new RedBall(mousePos);
		break;
	}
}

void GameUpdate()
{
	tree->Update();
	if (obj_count >= OBJ_NUM) return;

	if(IsMouseOn(MOUSE_INPUT_LEFT))
	{
		Pos mousePos = { static_cast<float>(GetMouseX()) ,static_cast<float>(GetMouseY() )};
	}

	if (redball) 
	{ redball->Update(); }
	
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
	if (redball) 
	{ redball->Draw(); }
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

