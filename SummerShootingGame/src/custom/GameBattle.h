#pragma once

int xcam = 0;
int map_x = 0;
float hill_x = 0;
int map_y_wall = 0;
//int ycam = 0;

int gun_handler = 0;
int sword_handler = 0;
int slash_anim_handler = 0;

///stage
int map1_handler = 0;
int arrowicon_handler = 0;
int killremaining = 35;

#define MAXENTITY 30
#define BULLET_IMGSIZE 30

bool GetStageCleared();

struct Player
{
private:
	int player_handler = 0;
	int bullet_handler = 0;
	int speedmult = 2;
	/// /////
	int anim_ms = 0;
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

	void MovingToFinish(const char* directionkey)
	{
		if (finishdistance <= 0)
		{
			finishdistance = 0;
		}

		if (directionkey == "right" && GetStageCleared())
		{
			finishdistance--;
		}
		else if (directionkey == "left")
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
				hill_x += 0.8 + speedmult;

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
				hill_x -= 0.8 + speedmult;

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
				y -= speedmult;
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
				bullet_y[i] = y_MIDDLE - 20;
			}

		}
	}


	void MoveBullet()
	{

		for (int i = 0; i < MAXENTITY; i++)
		{
			if (isBulletMode[i])
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
		
			DrawBulletIcon();
			DrawFormatString(100, WINDOW_H - 100, YELLOW, "Bullet 6/%1d", bulletcount);
			DrawString(100, WINDOW_H - 80, "K to Reload",WHITE);
		
	}

	void DrawBullet()
	{
		for (int i = 0; i < MAXENTITY; i++)
		{
			DrawRectGraph(bullet_x[i], bullet_y[i], 0, 0, BULLET_IMGSIZE, BULLET_IMGSIZE, bullet_handler, 1, !isBulletReverse[i], 0);
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
		if (bulletcount < 0)
		{
			//TODO OUT OF BULLETBULLET SFX
		}
		if (IsKeyOn(KEY_INPUT_L) && bulletcount > 0 && !isShooting && shootcooldown == 0)
		{
			isShooting = true;
			isInControl = false;
			bulletcount--;
			shootcooldown = base_shootcooldown;
			ActivateBullet();
		}
		//Anim
		if (isShooting)
		{
			shoot_anim_ms++;
			x_scr_mult = Shooting;

			if (shoot_anim_ms > 30)
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

	void DrawSlashAnim(bool& isSlashfxAnimation)
	{
		
			if (!isPlayerReverse)
			{
				DrawRectGraph(x - 55, y + 35, slash_x_scr, 0, 100, 100, slash_anim_handler, 1, isPlayerReverse, TRUE);
			}
			if (isPlayerReverse)
			{
				DrawRectGraph(x + 55, y + 35, slash_x_scr, 0, 100, 100, slash_anim_handler, 1, isPlayerReverse, TRUE);
			}
		

		slashfx_anim_ms++;
		slash_x_scr = 0;
		if (slashfx_anim_ms > 5)
		{
			slash_x_scr = 100;
			slashfx_anim_ms = 0;
			isSlashfxAnimation = false;
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
				DrawRectGraph(x + 65, y + 25, 0, 0, 40, 40, sword_handler, 1, isPlayerReverse, FALSE);

			}
		}


	}

	bool isSlashfxAnimation = false;

	void DrawEquippedSword2()
	{

		if (x_scr_mult == Slashing2)
		{
			if (isPlayerReverse)
			{
				isSlashfxAnimation = true;
				DrawRectGraph(x - 5, y + 60, 0, 0, 60, 60, sword_handler, 1, isPlayerReverse, TRUE);

			}
			else
			{
				isSlashfxAnimation = true;
				DrawRectGraph(x + 35, y + 60, 0, 0, 60, 60, sword_handler, 1, isPlayerReverse, TRUE);

			}
		}
		
	
	}

	void TriggerSlashHitbox(int i);

	void Slash()
	{
		
		if (IsKeyOn(KEY_INPUT_J) && !isSlashing && slashcooldown == 0)
		{
			for (int i = 0; i < MAXENTITY; i++)
			{
				TriggerSlashHitbox(i);
			}
			slashcooldown = base_slashcooldown;
			isSlashing = true;
			isInControl = false;
		}
		if (isSlashing)
		{
			if (slash_anim_ms == 1)
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

	bool IsCanDodge(bool& isInControl, bool& isDodging , int& dodgecooldown)
	{
		return isInControl && !isDodging && dodgecooldown == 0;
	}
	
	bool isDodging = false;



	void DodgeTrigger()
	{
		
		if (IsKeyOn(KEY_INPUT_SPACE) && IsCanDodge(isInControl,isDodging,dodgecooldown) )
		{
			isDodging = true;
			dodgecooldown = base_dodgecooldown;
		}
		
		if(isDodging)
		{
			//draw shadows
			isInControl = false;
			isImmune = true;
			dodgeduration++;
			if (isPlayerReverse)
			{
				xcam -= 6;
				map_x -= 6;
			}
			if (!isPlayerReverse)
			{
				xcam += 6;
				map_x += 6;
				
			}

			if (dodgeduration > base_dodgeduration)
			{
				//dodgecooldown = base_dodgecooldown;
				dodgeduration = 0;
				isDodging = false;
				isImmune = false;
				isInControl = true;
			}
		}
		
	}

	void CoolDownManager()
	{
		if (dodgecooldown > 0)
		{
			dodgecooldown--;
		}
		if (shootcooldown > 0)
		{
			shootcooldown--;
		}
		if (slashcooldown > 0)
		{
			slashcooldown--;
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
	int x_MIDDLE = 0;
	int y_MIDDLE = 0;
	int bullet_x[MAXENTITY] = {};
	int bullet_y[MAXENTITY] = {};
	int finishdistance = 0;
	int base_shootcooldown = 70;
	int base_slashcooldown = 30;
	int shootcooldown = base_shootcooldown;
	int slashcooldown = base_slashcooldown;

	bool isImmune = false;

	int shoot_anim_ms = 0;

	int base_dodgeduration = 60;
	int dodgeduration = 0;

	int base_dodgecooldown = 600;
	int dodgecooldown = 0;

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
		for (int i = 0; i < MAXENTITY; i++)
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
		x_MIDDLE = x + WIDTH / 2;
		y_MIDDLE = y + HEIGHT / 2;
		if (isSlashing)
		{
			DrawEquippedSword2();
		}
		if (isSlashfxAnimation)
		{
			DrawSlashAnim(isSlashfxAnimation);
		}


		if (tutorialbox.isTutorialOver)
		{

		}
		if (isReadyCheck && !isGOText)
		{
			gameui.DrawHotbar();
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
		CoolDownManager();
		HPManager();
		Moving();
		Shoot();
		Slash();
		DodgeTrigger();
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
private:

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
			killremaining--;
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
		if (!player.isImmune && IsCollisionDetect(player.x_MIDDLE, player.y_MIDDLE, x[i] + xcam, y[i], player.RAD, RAD))
		{
			if (player.hp > 0)
			{
				player.hp -= 0.5;
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
		if (hp[i] < 100)
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

public:
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
		enemy_slime_handler = LoadGraph("data/slime.png", TRUE);
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
		killcount += i;
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
				int spawnpos_y = GetRand(WINDOW_H - 50) + map_y_wall+20 + RAD;
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
		for (int i = 0; i < MAXENTITY; i++)
		{
			//DrawCircle(x[i] + xcam, y[i], RAD, YELLOW, 1, 1);
			DrawRectGraph(x[i] - IMGSIZE / 2 + xcam, y[i] - IMGSIZE / 2,
				x_scr * x_scr_mult[i], 1, 100, 100, enemy_slime_handler, 1, isEnemyReverse, FALSE);

			FacingManager(i);
			DrawHP(i);
			DoAnim(i);
		}
		DrawFormatString(220, 350, RED, "Kill Remaining : %d", killremaining);
		DrawStageOver();

	}



};

Enemy enemy;