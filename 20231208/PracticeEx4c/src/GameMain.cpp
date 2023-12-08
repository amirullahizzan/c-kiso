#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "Actor.h"
#include "CircleBase.h"
#include "CircleScaling.h"
#include "CircleMoving.h"
// =====================================================
//	グローバル変数
// =====================================================
namespace
{
	// ----------------------------------
	//	 定数
	// ----------------------------------
	const char* ACTOR_IMAGES[] =	// 画像ファイル
	{
		 "data/pipo-charachip019.png"
		,"data/pipo-charachip019a.png"
		,"data/pipo-charachip019b.png"
		,"data/pipo-charachip019c.png"
		,"data/pipo-charachip019d.png"
		,"data/pipo-charachip019e.png"
	};
	const int   ACTOR_IMAGES_SIZE = SIZE(ACTOR_IMAGES);	// 画像ファイルのサイズ
	const int	ACTOR_NUM		  = 4;					// 画面上のキャラクターの最大数
	const float ACTOR_MOVE_SPEED  = 3;					// キャラクターの移動速度

	// ----------------------------------
	//	 変数
	// ----------------------------------
	Actor  actors[ACTOR_NUM];			// 画面上のキャラクター
	Actor* target_actor	   = nullptr;	// ターゲットのキャラクターのアドレス格納用
	int	   now_actor_index = 0;			// 現在のターゲットキャラクターの配列の番号

	CircleScaling target_circle;		// ターゲティングの拡縮する円
	CircleMoving moving_circle;		// ターゲティングの拡縮する円

	// ----------------------------------
	//	 関数
	// ----------------------------------
	void targetActorUpdate();	// ターゲットのみの処理：更新
	void actorsInit();			// 画面上のキャラクターの一括処理：初期化
	void actorsUpdate();		// 画面上のキャラクターの一括処理：更新
	void actorsRender();		// 画面上のキャラクターの一括処理：描画
	void actorsExit();			// 画面上のキャラクターの一括処理：終了
}

// =====================================================
//		初期化
// =====================================================
void GameInit()
{
	actorsInit();
	target_actor = &actors[now_actor_index];
}

// =====================================================
//		更新
// =====================================================
void GameUpdate()
{
	actorsUpdate();
	targetActorUpdate();


	target_circle.update();
	moving_circle.update();
	
	moving_circle.setTarget(target_actor);
	target_circle.setTarget(target_actor);
	target_actor = &actors[now_actor_index];

	if (IsKeyOn(KEY_INPUT_SPACE))
	{
		now_actor_index = GetRand(3);
	}

	if (IsKeyOn(KEY_INPUT_A))
	{
		now_actor_index+=1;
		if (now_actor_index >= ACTOR_NUM)
		{ now_actor_index = 0; }
	}

}

// =====================================================
//		描画
// =====================================================
void GameDraw()
{
	printfDx("distance selector and actor : %f\n\n", getDist(target_actor->getPos(), moving_circle.getPos()));
	printfDx("distance selector and actor : %d\n\n", now_actor_index);
	target_circle.render();
	moving_circle.render();
	actorsRender();

}

// =====================================================
//		終了
// =====================================================
void GameExit()
{
	actorsExit();

}

namespace
{
	// *************************************************************
	//	編集禁止
	// *************************************************************
	// ターゲットのみの処理：更新
	void targetActorUpdate()
	{
		if (target_actor == nullptr)
		{
			return;
		}

		target_actor->setTarget();

		Pos now_pos = target_actor->getPos();
		if (IsKeyRepeat(KEY_INPUT_RIGHT))
		{
			now_pos.x += ACTOR_MOVE_SPEED;
		}
		else if (IsKeyRepeat(KEY_INPUT_LEFT))
		{
			now_pos.x -= ACTOR_MOVE_SPEED;
		}
		else if (IsKeyRepeat(KEY_INPUT_UP))
		{
			now_pos.y -= ACTOR_MOVE_SPEED;
		}
		else if (IsKeyRepeat(KEY_INPUT_DOWN))
		{
			now_pos.y += ACTOR_MOVE_SPEED;
		}

		// 範囲外のチェック
		now_pos.x = max(now_pos.x, IMG_SIZE / 2);
		now_pos.y = max(now_pos.y, IMG_SIZE / 2);
		now_pos.x = min(now_pos.x, WINDOW_W - IMG_SIZE / 2);
		now_pos.y = min(now_pos.y, WINDOW_H - IMG_SIZE / 2);

		target_actor->setPos(now_pos);
	}
	// 画面上のキャラクターの一括処理：初期化
	void actorsInit()
	{
		for (int i = 0; i < ACTOR_NUM; ++i)
		{
			int x_space = i % (ACTOR_NUM / 2);
			int y_space = i / (ACTOR_NUM / 2);
			float start_x = (float)(0 + (WINDOW_W / 4) + WINDOW_W / 2 * x_space);
			float start_y = (float)(0 + (WINDOW_H / 4) + WINDOW_H / 2 * y_space);
			actors[i].init(ACTOR_IMAGES[GetRand(ACTOR_IMAGES_SIZE - 1)]);
			actors[i].setPos({ start_x, start_y });
		}
	}
	// 画面上のキャラクターの一括処理：更新
	void actorsUpdate()
	{
		for (int i = 0; i < ACTOR_NUM; ++i)
		{
			actors[i].update();
		}
	}
	// 画面上のキャラクターの一括処理：描画
	void actorsRender()
	{
		for (int i = 0; i < ACTOR_NUM; ++i)
		{
			actors[i].render();
		}
	}
	// 画面上のキャラクターの一括処理：終了
	void actorsExit()
	{
		for (int i = 0; i < ACTOR_NUM; ++i)
		{
			actors[i].exit();
		}
	}
	// *************************************************************
	//	編集禁止
	// *************************************************************
}