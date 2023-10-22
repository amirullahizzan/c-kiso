#include "Winmain.h"
#include "Common.h"
#include "Player.h"
#include "Hit.h"


const float GROUND_Y = (float)WINDOW_H - 60;	// 地面の座標
const int	ENEMY_MAX_NUM = 10;						// 敵の数

static Box player;

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
static int player_damage_frame = 0;	// ダメージ時間
const static int PLAYER_DAMAGE_FRAME_MAX = 60;	// ダメージ時間

void playerInit()
{
	player.w = 60;
	player.h = 60;
	player.x = 120;
	player.y = GROUND_Y - player.h / 2;
	player.color = BLUE;
}


void playerRender()
{
if (player_damage_frame % 3 == 0)
{
	drawBox(player);
}
}

void playerUpdate()
{
	if (player_jump_state != JUMP_STATE::NONE)
	{
		//Gravity when JUMP_STATE
		player.y -= player_jump_power;
		player_jump_power -= 1;
		if (player.y > (GROUND_Y - player.h / 2))
		{
			// 床に接地したら再度ジャンプできるようにする
			player.y = GROUND_Y - player.h / 2;
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
		playerSetDamage();
	}
	// ------------------------------------------
	
	
}

void playerSetDamage()
{
	player_damage_frame = PLAYER_DAMAGE_FRAME_MAX;
}


void playerDamageUpdate()
{
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
}

Box getPlayer()
{
	return player;
}