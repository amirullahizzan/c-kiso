#include "WinMain.h"
#include "Common.h"
#include "Hit.h"
#include "Player.h"

// 命名規則
//	基本的にそれぞれの名称は、長くなってもいいので
//	意味のある、またそれぞれの使用用途を表す単語にする
//	禁止事項：「a」「speed」などの誰のものか主語が分からない名称にすること
//	変数(引数)	… dog_and_cat
//	自作関数		… dogAndCat
//	構造体		… DogAndCat
//	定数(列挙体)	… DOG_AND_CAT

// =====================================================
//	定数
// =====================================================
const float GROUND_Y = (float)WINDOW_H - 60;	// 地面の座標
const int	ENEMY_MAX_NUM = 10;						// 敵の数
const int	ENEMY_SPEED = 1;						// 敵の移動速度

// =====================================================
//	列挙体
// =====================================================

//static Box player;
static Box enemy[ENEMY_MAX_NUM];

// =====================================================
//	グローバル変数
//	 内部リンケージにするので、
//	 変数の宣言時に「static」をつける
// =====================================================


// -----------------------------------------------------
//	敵用変数
// -----------------------------------------------------
//static float		enemy_x[ENEMY_MAX_NUM]	   = { 0 };	// X座標
//static float		enemy_y[ENEMY_MAX_NUM]	   = { 0 };	// Y座標
//static float		enemy_w[ENEMY_MAX_NUM]	   = { 0 };	// 幅
//static float		enemy_h[ENEMY_MAX_NUM]	   = { 0 };	// 高さ
//static unsigned int enemy_color[ENEMY_MAX_NUM] = { 0 };	// 色
// 出現処理用

static int enemy_wait_frame[ENEMY_MAX_NUM] = { 0 };
bool isShown[ENEMY_MAX_NUM];


// =====================================================
//		初期化
// =====================================================
void GameInit()
{
	// プレイヤー
	{
		playerInit();
	}
	// 敵
	{
		for (int i = 0; i < ENEMY_MAX_NUM; ++i)
		{
			enemy[i].color = RED;
			// 初期座標の設定
			//	高さがランダムなので、ランダムに設定する
			//	高さが決まってから、Y座標が決まるので先に高さを決める
			enemy[i].w = 20;
			enemy[i].h = (float)(100 + GetRand(5) * 10);
			enemy[i].x = WINDOW_W + enemy[i].w / 2;		// 画面右端外に置く（右から左に移動するため）
			enemy[i].y = GROUND_Y - enemy[i].h / 2;
			// 待機時間の設定

			enemy_wait_frame[i] = (i + 1) * 160+GetRand(30);
			isShown[i] = true;

		}
	}

}
// =====================================================
//		更新
// =====================================================
int currentenemyIndex = 0;
int nextEnemy = 0;
void GameUpdate()
{
	// プレイヤー
	{
		playerUpdate();
		playerDamageUpdate();

	}

	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		if (CheckHitBox(getPlayer(), enemy[i]) )
		{
			playerSetDamage();
			//exit(0);
			//isShown[i] = false;
		}
	}


	// 敵
	{
		for (int i = 0; i < ENEMY_MAX_NUM; ++i)
		{
			if (enemy_wait_frame[i] <= 0)
			{
				enemy[i].x -= ENEMY_SPEED;
				// 移動中
				enemy_wait_frame[i] = 0;
				if (enemy[i].x < 0 - enemy[i].w / 2 && enemy_wait_frame[ENEMY_MAX_NUM-1] == 0)
				{
					// 座標と待機時間の再設定
					enemy[i].h			= (float)(50 + GetRand(5) * 10);
					enemy[i].x			= WINDOW_W + enemy[i].w / 2;
					enemy[i].y			= GROUND_Y - enemy[i].h / 2;
					enemy_wait_frame[i] = (i + 1) * 160+GetRand(30);
					isShown[i] = true;
				}
			}
			else
			{
				// 待機中
				--enemy_wait_frame[i];
			}
		}
	}

}
// =====================================================
//		描画
// =====================================================

void GameDraw()
{
	
	/*printfDx("currentenemy : %d\n", enemy_wait_frame[0]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[1]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[2]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[3]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[4]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[5]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[6]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[7]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[8]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[9]);*/

	// 背景
	{
		DrawBoxAA(0, GROUND_Y, WINDOW_W, WINDOW_H, BLACK, TRUE);
	}

	// プレイヤー
	{
		playerRender();
	}

	// 敵
	{
		for (int i = 0; i < ENEMY_MAX_NUM; ++i)
		{
			if(isShown[i] == true)	drawBox(enemy[i]);
		}
		// Debug
		int font_size = GetFontSize();
		for (int i = 0; i < ENEMY_MAX_NUM; ++i)
		{
			if (enemy_wait_frame[i] > 0)
				continue;
			if (isShown[i] == true)
			{
			DrawFormatStringF(enemy[i].x + enemy[i].w / 2 - 14, enemy[i].y - enemy[i].h / 2 - font_size, BLACK, "%d", i);
			}
		}
	}
}
// =====================================================
//		終了
// =====================================================
void GameExit()
{


}

//int EnemyWaitReroll(int i)
//{
//	int wait_frame_rand = GetRand(1);
//	switch (wait_frame_rand)
//	{
//	case 0:
//		return enemy_wait_frame[i] = 160;
//		break;
//	case 1:
//		return enemy_wait_frame[i] = 180;
//		break;
//	}
//
//}