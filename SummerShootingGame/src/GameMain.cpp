#include "WinMain.h"
#include "custom/CollisionDetect.h"
#include "custom/CustomSystem.h"

#define MAXENTITY 30
#define BULLET_IMGSIZE 30

//SYSTEM

int fontsize = 24;
int MOJISIZE = 7;

//SCENES
bool isMainMenu = true;
bool isGame = false;
bool isGameOver = false;
bool isGameClear = false;

bool isInControl = true;
bool isReadyCheck = false;
bool isGOText = false;

int xcam = 0;
int map_x = 0;
int map_y_wall = 0;
//int ycam = 0;

int gun_handler = 0;
int sword_handler = 0;
int slash_anim_handler = 0;

///stage
int map1_handler = 0;
int arrowicon_handler = 0;
int killremaining = 15;

bool GetStageCleared();

struct MainMenu
{
private:
	const int menu_posx_1 = CENTERX - MOJISIZE * 10;
	const int menu_posy_1 = CENTERY + 64;
	const int menu_posx_2 = CENTERX - MOJISIZE * 4;
	const int menu_posy_2 = CENTERY + 104;
	///////////
	int pointer_posx = 0;
	int pointer_posy = 0;
	int pointer_int = 0;



	void UpdatePointer()
	{
		if (IsKeyOn(KEY_INPUT_UP) || IsKeyOn(KEY_INPUT_W))
		{
			pointer_int = 0;
			pointer_posx = menu_posx_1 - 50;
			pointer_posy = menu_posy_1 - 2;
		}
		else if (IsKeyOn(KEY_INPUT_DOWN) || IsKeyOn(KEY_INPUT_S))
		{
			pointer_int = 1;
			pointer_posx = menu_posx_2 - 50;
			pointer_posy = menu_posy_2 - 2;
		}

		if (pointer_int == 0 && IsKeyOn(KEY_INPUT_RETURN))
		{
			isMainMenu = false;
			isGame = true;
		}
		if (pointer_int == 1 && IsKeyOn(KEY_INPUT_RETURN))
		{
			exit(0);
		}
	}

public:

	void DrawMainMenu()
	{
		DrawBox(0, 0, WINDOW_W, WINDOW_H, BLACK, 1);

		DrawString(menu_posx_1, menu_posy_1, "START GAME", YELLOW, 0);
		DrawString(menu_posx_2, menu_posy_2, "QUIT", YELLOW, 0);
	}

	///////////////
	void InitPointer()
	{
		pointer_handler = LoadGraph("data/pointicon.png", 1);
		pointer_posx = menu_posx_1 - 50;
		pointer_posy = menu_posy_1 - 2;
	}

	void DrawPointer()
	{

		DrawGraph(pointer_posx, pointer_posy, pointer_handler, 1);
		UpdatePointer();
	}


};

MainMenu mainmenu;




struct Player
{
private:
	int player_handler = 0;
	int bullet_handler = 0;
	int speedmult = 2;
	/// /////
	int anim_ms = 0;
	int shoot_anim_ms = 0;
	int x_scr = 90;
	int x_scr_mult = 1;
	int y_scr = 0;
	int y_scr_mult = 1;
	const int WIDTH = 90;
	const int HEIGHT = 144;
	bool isMoving = false;
	//////////////
	bool isShooting = false;
	bool isSlashing = false;
	const int base_bulletcount = 6;
	int bulletcount = base_bulletcount;
	int bullet_entity[3] = {};
	int bulletspeed = 3;
	bool isBulletReverse[MAXENTITY] = { };


	

	
	int bulletTravelDistance[MAXENTITY] = {};

	enum Facing { Left = 0, Between = 1, Right = 2, Slashing1 = 10, Slashing2 = 11, Shooting = 14 };

	void DoAnim()
	{
		if (anim_ms > 0)
		{
			x_scr_mult = Right;
		}
		if (anim_ms > 30)
		{
			x_scr_mult = Between;
		}
		if (anim_ms > 60)
		{
			x_scr_mult = Left;
		}
		if (anim_ms > 90)
		{
			x_scr_mult = Between;
		}
		if (anim_ms > 120)
		{
			anim_ms = 0;
		}
	}

	void MovingToFinish(const char *directionkey)
	{
		if (finishdistance <= 0)
		{
			finishdistance = 0;
		}

		if (directionkey == "right" && GetStageCleared())
		{
			finishdistance--;
		}
		else if(directionkey == "left")
		{
			finishdistance++;
		}

		
	}

	void Moving()
	{
		
		if (isInControl)
		{
			if ((CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A)))
			{
				
				xcam += 1 + speedmult;
				map_x += 1 + speedmult;

				anim_ms++;
				isPlayerReverse = false;
				isMoving = true;
				DoAnim();
				MovingToFinish("left");
			}
			else if ((CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D)))
			{
				xcam -= 1 + speedmult;
				map_x -= 1 + speedmult;

				anim_ms++;
				isPlayerReverse = true;
				isMoving = true;
				DoAnim();
				MovingToFinish("right");
			}
			else
			{
				isMoving = false;
				x_scr_mult = Between;
			}

			if ((CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W)) && y > map_y_wall)
			{
				if (!isMoving)
				{
					anim_ms++;
				}
				y-=speedmult;
				DoAnim();
			}
			else if ((CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S)) && y < WINDOW_H)
			{
				if (!isMoving)
				{
					anim_ms++;
				}
				y += speedmult;
				DoAnim();
			}

			if (CheckHitKey(KEY_INPUT_LSHIFT))
			{
				speedmult = 3;
			}
			else
			{
				speedmult = 2;
			}
		}

	}

	bool isBulletMode[MAXENTITY] = { };

	void InitBullet(int i)
	{
		bullet_handler = LoadGraph("data/bullet.png", 1);
		bullet_x[i] = -100;
		bullet_y[i] = -100;
	}

	int BulletInitDirection()
	{
		if (isPlayerReverse)
		{
			return 30;
		}
		else
		{
			return -40;
		}
	}


	void ActivateBullet()
	{
		for (int i = 0; i < MAXENTITY; i++)
		{
			if (!isBulletMode[i])
			{
				isBulletMode[i] = true;
				isBulletReverse[i] = isPlayerReverse;
				bullet_x[i] = CENTERX + BulletInitDirection();
				bullet_y[i] = y_MIDDLE -20;
			}	
		
		}
	}
	

	void MoveBullet()
	{
		
		for (int i = 0; i < MAXENTITY; i++)
		{
			if(isBulletMode[i])
			{
				bulletTravelDistance[i]++;
				if (isBulletReverse[i])
				{
					bullet_x[i] += bulletspeed;
				}
				if (!isBulletReverse[i])
				{
					bullet_x[i] -= bulletspeed;
				}
				
			}
		}

		for (int i = 0; i < MAXENTITY; i++)
		{
		
			DamageEnemy(i);
			if (bulletTravelDistance[i] > 100)
			{
				DestroyBullet(i);
			}

		}
	}

	void DrawBulletIcon()
	{
		DrawGraph(250, WINDOW_H - 100, bullet_handler, 1);
	}

	void DrawBulletCount()
	{
		if (isReadyCheck && !isGOText)
		{
			DrawBulletIcon();
			DrawFormatString(100, WINDOW_H - 100, YELLOW, "Bullet 6/%1d", bulletcount);
		}
	}

	void DrawBullet()
	{
		for (int i = 0; i < MAXENTITY; i++)
		{
			DrawRectGraph(bullet_x[i] , bullet_y[i],0,0,BULLET_IMGSIZE, BULLET_IMGSIZE, bullet_handler, 1,!isBulletReverse[i],0);
		}
	}


	void DrawEquippedGun()
	{
		if (isPlayerReverse)
		{
			DrawRectGraph(x + WIDTH - 35, y + 45, 0, 0, 60, 60, gun_handler, 1, isPlayerReverse, FALSE);
		}
		else
		{
			DrawRectGraph(x - 25, y + 45, 0, 0, 60, 60, gun_handler, 1, isPlayerReverse, FALSE);
		}
	}

	void ReloadGun()
	{
		if (IsKeyOn(KEY_INPUT_K) && isInControl)
		{
			bulletcount = base_bulletcount;
			//TODO RELOAD BULLET SFX
		}
	}


	void Shoot()
	{
		shootcooldown = shoot_anim_ms;
		//Bool Trigger
		if (bulletcount < 0)
		{
			//TODO OUT OF BULLETBULLET SFX
		}
		if (IsKeyOn(KEY_INPUT_L) && bulletcount > 0 && !isShooting)
		{
			isShooting = true;
			isInControl = false;
			bulletcount--;
			ActivateBullet();
		}
		//Anim
		if (isShooting)
		{
			shoot_anim_ms++;
			x_scr_mult = Shooting;

			if (shoot_anim_ms > 50)
			{
				shoot_anim_ms = 0;
					x_scr_mult = Between;
					isInControl = true;
					isShooting = false;
			}
		}
		MoveBullet();
		ReloadGun();
	}

	/////////////// SLASH
	int slash_anim_ms = 0;
	int slashfx_anim_ms = 0;
	int slash_x_scr = 0;
	void DrawSlashAnim()
	{
		DrawRectGraph(x - 55, y + 35, slash_x_scr, 0, 100, 100, slash_anim_handler, 1, isPlayerReverse, TRUE);
		slashfx_anim_ms++;
		slash_x_scr = 0;
		if (slashfx_anim_ms > 5)
		{
			slash_x_scr = 100;
			slashfx_anim_ms = 0;
		}
	}

void DrawEquippedSword()
	{

	if (x_scr_mult == Slashing1)
	{
		if (isPlayerReverse)
		{
			DrawRectGraph(x - 35, y + 25, 0, 0, 40, 40, sword_handler, 1, isPlayerReverse, FALSE);
		}
		else
		{
			DrawRectGraph(x+65, y + 25, 0, 0, 40, 40, sword_handler, 1, isPlayerReverse, FALSE);
			
		}
	}


	}

void DrawEquippedSword2()
{
	if (x_scr_mult == Slashing2)
	{
		if (isPlayerReverse)
		{
			DrawRectGraph(x - 5, y + 60, 0, 0, 60, 60, sword_handler, 1, isPlayerReverse, TRUE);
			//DrawRectGraph(x - 35, y + 60, 0, 0, 100, 100, slash_anim_handler, 1, isPlayerReverse, TRUE);

		}
		else
		{
			DrawRectGraph(x + 35, y + 60, 0, 0, 60, 60, sword_handler, 1, isPlayerReverse, TRUE);
			DrawSlashAnim();
			//DrawRectGraph(x - 35, y + 60, 100, 0, 100, 100, slash_anim_handler, 1, isPlayerReverse, TRUE);

		}
	}
}

void TriggerSlashHitbox(int i);

	void Slash()
	{
		if (IsKeyOn(KEY_INPUT_J) && !isSlashing)
		{
			for (int i = 0; i < MAXENTITY; i++)
			{
				TriggerSlashHitbox(i);
			}
			isSlashing = true;
			isInControl = false;
		}
		if(isSlashing)
		{
			if (slash_anim_ms==1)
			{
				
			}
			x_scr_mult = Slashing1;
			slash_anim_ms++;
				if (slash_anim_ms > 5)
				{
					x_scr_mult = Slashing2;
				}
				if (slash_anim_ms > 20)
				{
					isSlashing = false;
					isInControl = true;
					slash_anim_ms = 0;
				}
		}
		
	}

	const int HPBORDER = 3;
	const int HPPOSX = 500;
	const int HPPOSY = 700;
	const int HPPOS_WIDTH = 250;
	const int HPPOS_HEIGHT = 40;



	void HPManager()
	{
		if (hp <= 0)
		{
			//ResetGame();
			/*isGame = false;
			isMainMenu = true;*/

			isGame = false;
			isGameOver = true;
		}
	}

	

public:
	int x = 0;
	int y = 0;
	float hp = 100;
	bool isPlayerReverse = false;

	const int RAD = 30;
	//Middle of Player Asset
	int x_MIDDLE=0;
	int y_MIDDLE = 0;
	int bullet_x[MAXENTITY] = {};
	int bullet_y[MAXENTITY] = {};
	int finishdistance = 0;
	int baseshootcooldown = 60;
	int shootcooldown = baseshootcooldown;

	void Init()
	{
		hp = 100;
		x_MIDDLE = x + WIDTH / 2;
		y_MIDDLE = y + HEIGHT / 2;
		x = CENTERX - x_MIDDLE;
		y = CENTERY - y_MIDDLE;
		player_handler = LoadGraph("data/mc.png");
		gun_handler = LoadGraph("data/revolver.png");
		sword_handler = LoadGraph("data/sword.png");
		slash_anim_handler = LoadGraph("data/slash_anim.png");
		for (int i = 0;i < MAXENTITY;i++)
		{
			InitBullet(i);
		}
	}
	///////

	void DrawHP()
	{
		DrawBox(HPPOSX - HPBORDER, HPPOSY - HPBORDER, HPPOSX + HPPOS_WIDTH + HPBORDER, HPPOSY + HPPOS_HEIGHT + HPBORDER, WHITE, 1);
		DrawBox(HPPOSX, HPPOSY, HPPOSX + HPPOS_WIDTH, HPPOSY + HPPOS_HEIGHT, BLACK, 1);
		DrawBox(HPPOSX + 3, HPPOSY + 3, (int)(HPPOSX + 3 + (hp / 0.41)), HPPOSY + HPPOS_HEIGHT - 2, GREEN, 1); //https://dxlib.xsrv.jp/cgi/patiobbs/patio.cgi?mode=view&no=5462 // /change the division to add size
	}

	void Draw()
	{
		if (isShooting)
		{
			DrawEquippedGun();
		}
		if (isSlashing)
		{
			DrawEquippedSword();
		}
		DrawRectGraph(x, y, x_scr * x_scr_mult, y_scr * y_scr_mult, 90, 144, player_handler, 1, isPlayerReverse, FALSE);
		x_MIDDLE = x+WIDTH/2;
		y_MIDDLE = y+HEIGHT/2;
		if (isSlashing)
		{
			DrawEquippedSword2();
		}

		if (tutorialbox.isTutorialOver)
		{
			
		}
		if (!isGOText)
		{
			DrawBulletCount();
			DrawBullet();
		}
	
	}

	const float cooldown_ultimate_BASE = 5;
	float cooldown_ultimate = 0;
	//declaration
	void ReleaseUltimate();
	void DamageEnemy(int i);

	void Control()
	{
			HPManager();
			Moving();
			Shoot();
			Slash();
			//ReleaseUltimate();
			
	}

	void DestroyBullet(int i)
	{
		isBulletMode[i] = false;
		bullet_x[i] = -50;
		bullet_y[i] = -50;
		bulletTravelDistance[i] = 0;
	}
};

Player player;
////////////////////////////


struct Enemy
{
private :
	
	int RAD = 25;
	int speedmult[MAXENTITY] = {};
	bool isSpawned[MAXENTITY] = {};
	int followRandomizer[MAXENTITY] = {};
	int follower_dx[MAXENTITY] = {};
	int x_scr = 100;
	int x_scr_mult[MAXENTITY] = {};
	int enemy_slime_handler = 0;
	int isEnemyReverse = false;

	void CalculateDistance(int i)
	{
		follower_dx[i] = abs(player.x_MIDDLE - (x[i] + xcam));
	}

	//bool IsCollisionDetect(int x1, int y1, int x2, int y2, int r1,int r2)
	//{
	//	int dx = x2 - x1;
	//	int dy = y2 - y1;
	//	double distance = sqrt((dx * dx) + (dy * dy));
	//	return distance < r1+r2;
	//}

	void KillRemaining()
	{
		if (killremaining > 0)
		{
			killremaining --;
		}
	}
	
	//int remainingenemy = 0;
	void HPManager(int i)
	{
		if (hp[i] <= 0)
		{
			hp[i] = 0;
			DestroyEnemy(i);
			KillRemaining();
			AddScore();
		}
	}

	

	void DamagePlayer(int i)
	{
		if (IsCollisionDetect(player.x_MIDDLE, player.y_MIDDLE,x[i] + xcam, y[i],player.RAD,RAD))
		{
			if (player.hp > 0)
			{
				player.hp-=0.5;
				//Damage sound
			}
		}
	}

	void FollowPlayer(int i)
	{
		if (x[i] + xcam > player.x_MIDDLE)
		{
			x[i] -= speedmult[i];
		}
		else if (x[i] + xcam < player.x_MIDDLE)
		{
			x[i] += speedmult[i];
		}

		if ((y[i] > player.y_MIDDLE && followRandomizer[i] <= 0) || (follower_dx[i] < (75 + followRandomizer[i]) && y[i] > player.y_MIDDLE))
		{
			y[i] -= speedmult[i];
		}
		else if ((y[i] < player.y_MIDDLE && followRandomizer[i] <= 0) || (follower_dx[i] < 150 && y[i] < player.y_MIDDLE))
		{
			y[i] += speedmult[i];
		}
	}
	

	void DistanceBorder(int i)
	{
		if (follower_dx[i] > 1200)
		{
			DestroyEnemy(i);
		}
	}

	void AI(int i)
	{
			CalculateDistance(i);
			DistanceBorder(i);
			FollowPlayer(i);
	}

	void DrawHP(int i)
	{
		if (hp[i]<100)
		{
			DrawBox(x[i] + xcam - 35, y[i] - RAD / 2 - 35, x[i] + (hp[i] / 1) + xcam - 35, y[i] - RAD / 2 - 25, GREEN, 1);
		}
	}

	int msframe = 0;
	void DoAnim(int i)
	{
		msframe++;
		if (msframe > 140 && IsCollisionDetect(player.x_MIDDLE, player.y_MIDDLE, x[i] + xcam, y[i], player.RAD, RAD))
		{
			x_scr_mult[i] = 2;
		}
		else if (msframe > 140)
		{
			x_scr_mult[i] = 1;
		}

		if (msframe > 260 && IsCollisionDetect(player.x_MIDDLE, player.y_MIDDLE, x[i] + xcam, y[i], player.RAD, RAD))
		{
			x_scr_mult[i] = 3;
		}
		else if (msframe > 260)
		{
			x_scr_mult[i] = 0;
		}

		if (msframe > 380)
		{
			msframe = 0;
		}


	}

	void FacingManager(int i)
	{
		if (player.x < x[i])
		{
			isEnemyReverse = false;
		}
		else if (player.x > x[i])
		{
			isEnemyReverse = true;
		}
	}

public :
	int hp[MAXENTITY] = {};
	int x[MAXENTITY] = {};
	int y[MAXENTITY] = {};
	int killcount = 0;

	int spawnpos_x = 0;
	int spawnpos_y = 0;

	//////////////////////
	void DrawStageOver();

	/////////////////////////

	void Init()
	{
		enemy_slime_handler = LoadGraph("data/slime.png",TRUE);
		/*for (int i = 0; i < MAXENTITY; i++)
		{
			isSpawned[i] = false;
			x[i] = -50;
			y[i] = -50;
		}*/
	}

	void DestroyEnemy(int i)
	{
		isSpawned[i] = false;
	}


	//Overloading
	void AddScore()
	{
		killcount++;
	}

	void AddScore(int i)
	{
		killcount+=i;
	}
	/////////

	enum IntSpawn { Left = 0, Right = 1 };

	int GetLeftRightRand()
	{
		int leftrightrandomizer = GetRand(1);
		if (leftrightrandomizer == Left)
		{
			return WINDOW_W + GetRand(WINDOW_W) - xcam;
		}
		else
		{
			return 0 - GetRand(WINDOW_W) - xcam;
		}
	}

	void Spawn()
	{

		for (int i = 0; i < MAXENTITY; i++)
		{
			if (!isSpawned[i])
			{
				if (killremaining <= 0)
				{
					x[i] = -100;
					y[i] = -100;
					continue;
				}
				int spawnpos_x = GetLeftRightRand();
				int spawnpos_y = GetRand(WINDOW_H - 50)+ map_y_wall+RAD;
				hp[i] = 100;
				x[i] = spawnpos_x;
				y[i] = spawnpos_y;
				follower_dx[i] = 0;
				followRandomizer[i] = GetRand(500) + 250;
				speedmult[i] = 1;
				isSpawned[i] = true;
			}
			
			AI(i);
			HPManager(i);
			//DamageEnemy(i);
			DamagePlayer(i);
		}
	}


	

	int IMGSIZE = 100;
	void Draw()
	{
		for (int i = 0;i< MAXENTITY;i++)
		{
			//DrawCircle(x[i] + xcam, y[i], RAD, YELLOW, 1, 1);
			DrawRectGraph(x[i] - IMGSIZE / 2 +xcam, y[i] - IMGSIZE / 2, 
				x_scr * x_scr_mult[i], 1, 100, 100, enemy_slime_handler, 1, isEnemyReverse, FALSE);
			
			FacingManager(i);
			DrawHP(i);
			DoAnim(i);
		}
		DrawFormatString(220,350,RED,"Kill Remaining : %d" , killremaining);
		DrawStageOver();
		
	}

	

};

Enemy enemy;


struct GameGame
{
private :
	const int basestartcounter_ms = 100;
	int startcounter_ms = basestartcounter_ms;
	int startcounter_sec = 3;
	int text_gap = 0;
	bool isFontReset = false;

	int map1_x = 0;

	void StartStageCountdown()
	{
		startcounter_ms--;
		if (startcounter_ms <= 0 && startcounter_sec >= 0)
		{
			//Prevets the timer to Adjust after GO
			if (startcounter_sec > 0)
			{
				fontsize += 28;
				text_gap -= 10;
			}
			if (startcounter_sec > -2)
			{
				startcounter_sec--;
			}
			
			//TODO play TICK AUDIO
			startcounter_ms = basestartcounter_ms;

		}
		
		if (startcounter_sec > 0)
		{
			DrawFormatString(CENTERX - MOJISIZE + text_gap, CENTERY + text_gap * 2, YELLOW, "%d", startcounter_sec);
		}
		if (startcounter_sec == 0)
		{
			DrawString(CENTERX - MOJISIZE * 2 + text_gap, CENTERY + text_gap * 2, "GO", YELLOW);
			isReadyCheck = true;
			isGOText = true;
		}
		if (startcounter_sec < 0 && !isFontReset)
		{
			isGOText = false;
			fontsize = 24;
			isFontReset = true;
		}
	}

	void DrawTutorial()
	{
		tutorialbox.DrawDialogBox(350,"WASD = Move, K = Reload, L = Shoot");
		//DrawBox(0,0,20,20,BLACK,1);
	}

	void DrawScore()
	{
		DrawFormatString(20,750,YELLOW,"Enemy Killed : %d",enemy.killcount);
	}

	

public :
	bool isStageCleared = false;

	void DrawFadeIn()
	{
		DrawBox(0,0,WINDOW_W,WINDOW_H,BLACK,1);
	}

	void DrawMap1()
	{
		map_y_wall = WINDOW_H / 2 - 150;
		if (map_x <= -1320 || map_x >= 1320)
		{
			map_x = 0; 
		}
		DrawRectGraph(map_x, 0, 0, 0, 1320, 800, map1_handler, 0, FALSE, FALSE);
		DrawRectGraph(map_x+1320, 0, 0, 0, 1320, 800, map1_handler, 0, FALSE, FALSE);
		DrawRectGraph(map_x-1320, 0, 0, 0, 1320, 800, map1_handler, 0, FALSE, FALSE);

		//DrawFormatString(1000,200,YELLOW,"MAP %d", map_x);
	}

	void InitStage1()
	{
		player.finishdistance = 150;
		map1_handler = LoadGraph("data/map1.png",TRUE);
		arrowicon_handler = LoadGraph("data/movingarrow.png",TRUE);
	}

	void StartTutorial()
	{
		DrawTutorial();
		if (tutorialbox.isTutorialOver)
		{
			StartStageCountdown();
		}

	}

	void DrawRound()
	{
		if (isReadyCheck)
		{
			//GAME is here
			enemy.Draw();
			player.DrawHP();
		}

	}

	void StartStage()
	{
		if (isReadyCheck && !isGOText)
		{
			DrawScore();
			//gameui.DrawHotbar();
			DrawRound();
		}
	}

	void UpdateRound()
	{
		enemy.Spawn();
	}

	
	////////////////////

};


GameGame gamegame;

void GameInit()
{
	SetFontSize(24);
	mainmenu.InitPointer();
	gameui.Init();
	player.Init();
	gamegame.InitStage1();
	enemy.Init();
}
int slash_x1 = 0;
int slash_y1 = 0;
int slash_w1 = 0;
int slash_h1 = 0;

void GameUpdate()
{
	//debug.DebugControl();
	SetFontSize(fontsize);
	if (isGame && isReadyCheck)
	{
		player.Control();
		gamegame.UpdateRound();
	}

	slash_x1 = player.x_MIDDLE;
	slash_y1 = player.y;
	//slash_w1 = player.x_MIDDLE+100;
	//slash_h1 = player.y_MIDDLE+100;
	
}



void GameDraw()
{
	//if (isMainMenu)
	//{
	//	//DrawTitle
	//	mainmenu.DrawMainMenu();
	//	mainmenu.DrawPointer();
	//	//DrawGraph(200, 200, mainmenu.pointer_handler, 1);
	//}
	isGame = true;

	if (isGame)
	{
		gamegame.DrawMap1();
		player.Draw();
		
		gamegame.StartStage();
		
		gamegame.StartTutorial();


		//DrawBox(slash_x1, slash_y1, slash_w1, slash_h1, YELLOW, 1);

	}

	if (isGameOver)
	{
		DrawBox(0, 0, WINDOW_W, WINDOW_H, BLACK, 1);
		DrawString(CENTERX-8*MOJISIZE,CENTERY,"GAME OVER",YELLOW,1);
		DrawString(CENTERX-10*MOJISIZE,CENTERY+30,"Press Enter",YELLOW,1);
		if (IsKeyOn(KEY_INPUT_RETURN))
		{
			exit(0);
		}

	}

	if (isGameClear)
	{
		DrawBox(0, 0, WINDOW_W, WINDOW_H, BLACK, 1);
		DrawString(CENTERX - 8 * MOJISIZE, CENTERY+30, "You Win", YELLOW, 1);
		DrawString(CENTERX - 10 * MOJISIZE, CENTERY + 60, "Press Enter", YELLOW, 1);
		if (IsKeyOn(KEY_INPUT_RETURN))
		{
			exit(0);
		}
	}

	//debug.DisplayCenterGrid();
	//DrawFormatString(25, 25, YELLOW, "HP : %.1f", player.hp);
	//DrawFormatString(25, 50, YELLOW, "player_x mid : %d", player.x_MIDDLE);
	//DrawFormatString(25, 75, YELLOW, "player_y mid : %d", player.y_MIDDLE);
	//DrawFormatString(25, 95, YELLOW, "enemy : %d", enemy.x[0]);
	//DrawFormatString(25, 115, YELLOW, "enemy : %d", enemy.x[1]);
}


//void ResetGame()
//{
//	xcam = 0;
//	player.Init();
//	enemy.Init();
//}


void GameExit()
{


}

///////////////////////////////////////////
//DEFINE
void Player::ReleaseUltimate()
{
	if (cooldown_ultimate > 0)
	{
		cooldown_ultimate -= 0.1f;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) && cooldown_ultimate <= 0)
	{
		for (int i = 0; i < MAXENTITY; i++)
		{
			enemy.hp[i] = 0;
			cooldown_ultimate = cooldown_ultimate_BASE;
			enemy.AddScore(i);
		}
	}
}

void Player::DamageEnemy(int i)
{
	
	if (IsCollisionDetect(enemy.x[i] + xcam, enemy.y[i], player.bullet_x[i], player.bullet_y[i], BULLET_IMGSIZE + 10, 30))
	{
		player.DestroyBullet(i);
		if (enemy.hp[i] > 0)
		{
			enemy.hp[i] -= 50;
		}
	}


	/*if (player.isSlashing && player.isPlayerReverse && IsBoxCollide(slash_x1, slash_y1, slash_w1, slash_h1, enemy.x[i] - 25, enemy.y[i] - 25, enemy.x[i] + 25, enemy.y[i] + 25))
	{

	}*/
}

void Player::TriggerSlashHitbox(int i)
{
	if (isPlayerReverse && IsBoxCollide(slash_x1, slash_y1, 200, 200, enemy.x[i] + xcam, enemy.y[i], 50, 50))
	{
		enemy.hp[i] -= 50;
	}
	if (!isPlayerReverse && IsBoxCollide(slash_x1-200, slash_y1, 200, 200, enemy.x[i] + xcam, enemy.y[i], 50, 50))
	{
		enemy.hp[i] -= 50;
	}
	

}

void Enemy::DrawStageOver()
{
	if (killremaining <= 0)
	{
		gamegame.isStageCleared = true;
		//DrawCircle(1200, 400, 55, GREEN, 1, 1);
		DrawRectGraph(1200, 400, 0, 0, 90, 40, arrowicon_handler, TRUE, FALSE, FALSE);
		DrawString(1100,250,"MISSION CLEAR", RED,0);
		DrawFormatString(1100,300,YELLOW," %3d metre left",player.finishdistance);
		if (player.finishdistance <=0 )
		{
			isGame = false;
			isGameClear = true;
			//load Scene2
		}
	}
}

bool GetStageCleared()
{
	return gamegame.isStageCleared;
}

void Debug::DebugControl()
{
	if (CheckHitKey(KEY_INPUT_0))
	{
		player.hp -= 1;
	}
	if (CheckHitKey(KEY_INPUT_9))
	{
		player.hp = 100;
	}
}

void GameUI::DrawCooldown(int x, int y)
{
	if (player.shootcooldown > 0)
	{
		DrawFormatString(x, y, YELLOW, "%d", player.baseshootcooldown-player.shootcooldown);
	}
}

