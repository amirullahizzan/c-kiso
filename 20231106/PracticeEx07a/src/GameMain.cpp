#include "WinMain.h"
#include "Player.h"
#include "Enemy.h"
#include "PlayerBullet.h"

// =====================================================
//	グローバル変数
//	複数の関数で共通して使いたい変数はここに書く
// =====================================================
namespace
{
	const int PLAYER_BULLET_NUM = 15;
	constexpr int WINDOW_W_DIV3 = (WINDOW_W / 3);

	Player player;
	constexpr int MAX_ENEMY = 3;
	Enemy enemy[MAX_ENEMY];
	PlayerBullet player_bullets[PLAYER_BULLET_NUM];

	// 当たり判定用関数
	bool IsHit(float x1, float y1, float r1, float x2, float y2, float r2)
	{
		float dist_x = x1 - x2;
		float dist_y = y1 - y2;
		float dist   = sqrtf(dist_x * dist_x + dist_y * dist_y);

		return dist < (r1 + r2);
	}
	
	bool IsHit(const Player& player, const Enemy& enemy)
	{
		float dist_x = player.GetPosX() - enemy.GetPosX();
		float dist_y = player.GetPosY() - enemy.GetPosY();
		float dist = sqrtf(dist_x * dist_x + dist_y * dist_y);

		return dist < (player.GetR() + enemy.GetR() );
	}
	bool IsHit(const PlayerBullet& bullet, const Enemy& enemy)
	{
		float dist_x = bullet.GetPosX() - enemy.GetPosX();
		float dist_y = bullet.GetPosY() - enemy.GetPosY();
		float dist = sqrtf(dist_x * dist_x + dist_y * dist_y);

		return dist < (bullet.GetR() + enemy.GetR());
	}

}

// =====================================================
//		初期化
//	ゲーム開始直後に最初に1回だけ実行される関数
//	最初の値を変数に入れたいときに使う
// =====================================================
void GameInit()
{
	player.Init();

	for (int i= 0;i<MAX_ENEMY ;i++)
	{
		constexpr static int ENEMY_Y_INIT = 50;
		enemy[i].Init();
		enemy[i].SetPos( i *WINDOW_W_DIV3 + (WINDOW_W_DIV3/2) ,ENEMY_Y_INIT);
	}

	for (int i = 0; i < PLAYER_BULLET_NUM; ++i)
	{
		player_bullets[i].Init();
	}

}
// =====================================================
//		更新
//	ゲームが終了されるまで実行される関数
//	1秒間に約60回呼ばれる
//	1フレームで行う処理をここに書く
// =====================================================
void GameUpdate()
{
	// 各オブジェクトの更新処理
	player.Update();
	for (int i = 0; i < PLAYER_BULLET_NUM; ++i)
	{
		player_bullets[i].Update();
	}

	for (int i = 0; i < MAX_ENEMY; i++)
	{
	enemy[i].Update();

		//if (IsHit(player.GetPosX(), player.GetPosY(), player.GetR(), enemy[i].GetPosX(), enemy[i].GetPosY(), enemy[i].GetR()))
		if (	IsHit(player,enemy[i])	)
		{
			player.SetDamage();
		}

	}

	// 弾発射処理
	if (IsKeyOn(KEY_INPUT_SPACE))
	{
		for (int i = 0; i < PLAYER_BULLET_NUM; ++i)
		{
			if (player_bullets[i].IsShot())
				continue;
			// 撃った状態の弾じゃないやつから発射
			player_bullets[i].SetPos(player.GetPosX(), player.GetPosY());
		
			break;
		}
	}

	for (int i = 0; i < PLAYER_BULLET_NUM; ++i)
	{
		for (int j = 0; j < MAX_ENEMY; j++)
		{
			//if (IsHit(player_bullets[i].GetPosX(), player_bullets[i].GetPosY(), player_bullets[i].GetR(), enemy[j].GetPosX(), enemy[j].GetPosY(), enemy[j].GetR()))
			if (IsHit(	player_bullets[i], enemy[j] )	)
			{
				enemy[j].SetDamage();
			}
		}
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
	for (int i = 0; i < PLAYER_BULLET_NUM; ++i)
	{
		player_bullets[i].Draw();
	}
	player.Draw();
	for (int i = 0; i < MAX_ENEMY; i++)
	{
	enemy[i].Draw();
	}
}
// =====================================================
//		終了
//	ゲームが終了する前に1回だけ実行される関数
//	何か最後に後片付けを行うときに使う
// =====================================================
void GameExit()
{


}
