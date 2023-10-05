#include "WinMain.h"
#include "Common.h"
#include "Hit.h"

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
enum JUMP_STATE
{
	NONE = 0,
	STEP1, STEP2,
};

static Box player;
static Box enemy[ENEMY_MAX_NUM];

// =====================================================
//	グローバル変数
//	 内部リンケージにするので、
//	 変数の宣言時に「static」をつける
// =====================================================
// -----------------------------------------------------
//	プレイヤー用変数
// -----------------------------------------------------
//static float		player_x	 = 0;	// X座標
//static float		player_y	 = 0;	// Y座標
//static float		player_w	 = 0;	// 幅
//static float		player_h	 = 0;	// 高さ
//static unsigned int player_color = 0;	// 色
// ジャンプ処理用
static int	 player_jump_state = JUMP_STATE::NONE;	 // 状態
static float player_jump_power = 0;				 // ジャンプ力
const static float PLAYER_JUMP_POWER_STEP1 = 20.0f;				 // ジャンプ力
const static float PLAYER_JUMP_POWER_STEP2 = 25.0f;				 // ジャンプ力
// ダメージ処理用
//	ダメージ中は点滅をする
int player_damage_frame = 0;	// ダメージ時間
const  int PLAYER_DAMAGE_FRAME_MAX = 60;	// ダメージ時間
static bool isImmune = false;

int playerhp = 100;

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


// =====================================================
//		初期化
// =====================================================
void GameInit()
{
	// プレイヤー
	{
		player.w = 60;
		player.h = 60;
		player.x = 120;
		player.y = GROUND_Y - player.h / 2;
		player.color = BLUE;
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

			enemy_wait_frame[i] = (i + 1) * 160;
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
		if (player_jump_state != JUMP_STATE::NONE)
		{
			//Gravity when JUMP_STATE
			player.y		  -= player_jump_power;
			player_jump_power -= 1;
			if (player.y > (GROUND_Y - player.h / 2))
			{
				// 床に接地したら再度ジャンプできるようにする
				player.y		  = GROUND_Y - player.h / 2;
				player_jump_power = 0;
				player_jump_state = JUMP_STATE::NONE;
			

			}
		}

		if (IsKeyOn(KEY_INPUT_SPACE))
		{
			switch (player_jump_state)
			{
			case NONE:
				player_jump_state = JUMP_STATE::STEP1;
				player_jump_power = PLAYER_JUMP_POWER_STEP1;
				break;
			case STEP1:
				player_jump_state = JUMP_STATE::STEP2;
				player_jump_power = PLAYER_JUMP_POWER_STEP2;
				break;
			case STEP2:
				break;
			}
		}
		// ------------------------------------------
		// ダメージ処理
		//	敵との当たり判定の処理が完成したら、
		//	キー入力ではなく、敵と当たったときにダメージ処理を行う
		//	現在はデバッグのため、Aキーを押したらデバッグ処理になるようにする
		if (IsKeyOn(KEY_INPUT_A))
		{
			// ダメージ開始
			SetPlayerFrameMax();
		}
		// ダメージ中処理
		if (player_damage_frame > 0)
		{
			--player_damage_frame;
		}
		else
		{
			// ダメージ終了
			player_damage_frame = 0;
		}
		// ------------------------------------------

		for (int i = 0;i < ENEMY_MAX_NUM; i++)
		{
		if (CheckHitBox(player,enemy[i]) && isImmune == false)
		{
			SetPlayerFrameMax();
			playerhp -= 10;
			isImmune = true;
		}
		}

		if (player_damage_frame <= 0)
		{
			isImmune = false;
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
					enemy_wait_frame[i] = (i + 1) * 160;
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
	printfDx("player jump power : %f\n", player_jump_power);
	printfDx("player jump : %d\n", player_jump_state);
	printfDx("player hp : %d\n", playerhp);
	printfDx("currentenemy : %d\n", enemy_wait_frame[0]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[1]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[2]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[3]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[4]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[5]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[6]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[7]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[8]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[9]);

	// 背景
	{
		DrawBoxAA(0, GROUND_Y, WINDOW_W, WINDOW_H, BLACK, TRUE);
	}

	// プレイヤー
	{
		if (player_damage_frame % 3 == 0)
		{
			// ダメージ中（player_damage_frameが3フレームに1回）のとき、
			// または、ダメージじゃない（player_damage_frameが0）とき、
			// プレイヤーを描画する
			drawBox(player);
		}
		
	}

	// 敵
	{
		for (int i = 0; i < ENEMY_MAX_NUM; ++i)
		{
			drawBox(enemy[i]);
		}
		// Debug
		int font_size = GetFontSize();
		for (int i = 0; i < ENEMY_MAX_NUM; ++i)
		{
			if (enemy_wait_frame[i] > 0)
				continue;

			DrawFormatStringF(enemy[i].x + enemy[i].w / 2 - 14, enemy[i].y - enemy[i].h / 2 - font_size, BLACK, "%d", i);
		}
	}
}
// =====================================================
//		終了
// =====================================================
void GameExit()
{


}

int EnemyWaitReroll(int i)
{
	int wait_frame_rand = GetRand(1);
	switch (wait_frame_rand)
	{
	case 0:
		return enemy_wait_frame[i] = 160;
		break;
	case 1:
		return enemy_wait_frame[i] = 180;
		break;
	}

}