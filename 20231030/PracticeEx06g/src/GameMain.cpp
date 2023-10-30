//#include <cstdlib>
#include "WinMain.h"
#include "Pos2.h"
#include "Hit.h"
#include "../add/Player.h"
#include "../add/Bullet.h"
#include "../add/Enemy.h"

// =====================================================
//	グローバル変数
//	複数の関数で共通して使いたい変数はここに書く
// =====================================================
static Player player;
#define MAX_BULLETS 25
static Bullet bullet[MAX_BULLETS];
Pos2 bulletleft;
Pos2 bulletright;
#define MAX_ENEMY 9
static Enemy enemy[MAX_ENEMY];

int enemywaveType = 0;
// =====================================================
//		初期化
//	ゲーム開始直後に最初に1回だけ実行される関数
//	最初の値を変数に入れたいときに使う
// =====================================================
void GameInit()
{
	player.init();
	for (int i = 0; i<MAX_BULLETS ;i++)
	{
	bullet[i].init();
	}

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		enemy[i].init();
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
	player.update();
	for (int i = 0;i < MAX_ENEMY;i++)
	{
		enemy[i].moveWave();

	if (
		isHit(player.getPos(),player.getR(), enemy[i].getPos(), player.getR())
		&& !enemy[i].getIsDestroyed()
	   )
			{
			player.setDamage();
			}
	}

	bulletleft.x = player.getX() - 25;
	bulletright.x = player.getX() + 25;
	bulletleft.y = player.getY();
	bulletright.y = player.getY();

	for (int i = 0;i < MAX_BULLETS;i++)
	{
		bullet[i].update();

		if (IsKeyOn(KEY_INPUT_SPACE) && !bullet[i].isShot())
		{
			bullet[i].setShot(bulletleft);
			break;
		}
	}
	for (int i = 0; i < MAX_BULLETS; i++)
	{

		if (IsKeyOn(KEY_INPUT_SPACE) && !bullet[i].isShot())
		{
			//if shot, move on to the next bullet
			if (bullet[i].isShot())
			{
				continue;
			}
			bullet[i].setShot(bulletright);
			break;
		}
	}


	switch (enemywaveType)
	{
	case 0:
	//Init Wave
		for (int i = 0 ;i<MAX_ENEMY;i++)
		{
		enemy[i].spawn();
		}
		enemywaveType+=1;
		break;
	case 1:
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (
				isHit	(bullet[i].getPos(), bullet[i].getR(), enemy[i].getPos(), enemy[i].getR()	)
				&& !enemy[i].getIsDestroyed()
				)
			{
				bullet[i].setErase();
				enemy[i].destroy();
			}
		}
		break;
	case 2:
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
	player.render();
	for (int i = 0; i < MAX_BULLETS; i++)
	{
	bullet[i].render();
	}
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		bullet[i].render();
	}
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		enemy[i].render();
	}

	printfDx(" pos : %f\n",bulletleft.x);
	printfDx(" pos : %f\n", bulletright.x);
	printfDx(" wavetype : %d\n", enemywaveType);
}
// =====================================================
//		終了
//	ゲームが終了する前に1回だけ実行される関数
//	何か最後に後片付けを行うときに使う
// =====================================================
void GameExit()
{
	player.exit();
	for (int i = 0; i < MAX_BULLETS; i++)

	{
	bullet[i].exit();
	}

}
