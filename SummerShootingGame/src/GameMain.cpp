#include "WinMain.h"
#include "custom/CutsceneManager.h"
#include "custom/CollisionDetect.h"
#include "custom/CustomSystem.h"
#include "custom/GameBattle.h"







struct GameGame
{
private :
	const int basestartcounter_ms = 100;
	int startcounter_ms = basestartcounter_ms;
	int startcounter_sec = 3;
	int text_gap = 0;
	int map1_mountain_handler = 0;
	int map1_hill_handler = 0;
	int cat_handler = 0;
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
		tutorialbox.DrawDialogBox(350,"WASD = Move, Space = Dodge, Shift = Sprint");
		//DrawBox(0,0,20,20,BLACK,1);
	}

	void DrawScore()
	{
		DrawFormatString(20,750,YELLOW,"Enemy Killed : %d",enemy.killcount);
	}

	void CatIdleAnim()
	{
		if (game_frame%30 == 0)
		{
			
			cat_xframe = 0;
		}
		if (game_frame % 60 == 0)
		{
			cat_xframe = 65;
		}
		
	}

	int cat_xframe = 0;

public :
	bool isStageCleared = false;
	int stagetime_sec = 0;

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
		if (hill_x*0.05 <= -1320 || hill_x * 0.05 >= 1320)
		{
			hill_x = 0;
		}
		DrawGraphF((hill_x*0.05), (float)150, map1_hill_handler, 1);
		DrawGraphF((hill_x*0.05)+1320, (float)150, map1_hill_handler, 1);
		DrawGraphF((hill_x*0.05) - 1320, (float)150, map1_hill_handler, 1);

		DrawRectGraph(20+xcam, 280, cat_xframe, 0, 65, 65, cat_handler, TRUE);
		CatIdleAnim();
		DrawGraphF((xcam*0.09)+(float)300 , 9 , map1_mountain_handler, 1);

		//DrawFormatString(1000,200,YELLOW,"MAP %d", map_x);
	}

	void InitStage1()
	{
		player.finishdistance = 150;
		map1_handler = LoadGraph("data/map1.png",TRUE);
		map1_mountain_handler = LoadGraph("data/mountain_bg.png", 1);
		map1_hill_handler = LoadGraph("data/hill_bg.png", 1);
		cat_handler = LoadGraph("data/cat.png", 1);
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

	int stagetime_ms = 0;
	void RoundTimer()
	{
		stagetime_ms++;
			if (stagetime_ms > 59)
			{
			stagetime_sec++;
			stagetime_ms = 0;
			}
	}

	void StartStage()
	{
		if (isReadyCheck && !isGOText)
		{
			
			DrawScore();
			RoundTimer();
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
	game_frame++;
	//debug.DebugControl();
	SetFontSize(fontsize);
	if (isGame && !isGOText)
	{
		player.Control();
		if (isReadyCheck)
		{
			gamegame.UpdateRound();
		}
	}

	slash_x1 = player.x_MIDDLE;
	slash_y1 = player.y;
	//slash_w1 = player.x_MIDDLE+100;
	//slash_h1 = player.y_MIDDLE+100;
	
}



void GameDraw()
{

	if (isMainMenu)
	{
		//DrawTitle
		mainmenu.DrawMainMenu();
		mainmenu.DrawPointer();
		//DrawGraph(200, 200, mainmenu.pointer_handler, 1);
		FadeEffect(FADEIN);

	}


	if (isGame)
	{

		gamegame.DrawMap1();
		player.Draw();
		
		gamegame.StartStage();
		
		gamegame.StartTutorial();

		FadeEffect(RESET);
		FadeEffect(FADEIN);

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
		DrawFormatString(CENTERX - 7 * MOJISIZE, CENTERY+180, WHITE, "Your Time : %d", gamegame.stagetime_sec);
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
		enemy.hp[i] -= 40;
	}
	if (!isPlayerReverse && IsBoxCollide(slash_x1-200, slash_y1, 200, 200, enemy.x[i] + xcam, enemy.y[i], 50, 50))
	{
		enemy.hp[i] -= 40;
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

void GameUI::DrawCooldownNumber(int x, int y, int cooldown, int base_cooldown)
{
	if (player.shootcooldown > 0)
	{
		DrawFormatString(x, y, WHITE, "%d", base_cooldown-cooldown);
	}
}

void GameUI::DrawSkill(int x, int y, int icon_handler, int skillcooldown, int base_skillcooldown)
{
	DrawGraph(x, y, icon_handler, 1);
	if (skillcooldown > 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 105);
		DrawBox(x, y + _IMGSIZE - (skillcooldown % base_skillcooldown * 96 / base_skillcooldown), x + 96, y + _IMGSIZE, BLACK, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	DrawString(1020,690,"SPACE",WHITE,0);
	DrawString(1120,690,"L",WHITE,0);
	DrawString(1220,690,"J",WHITE,0);
	DrawCooldownNumber(x, y, player.dodgecooldown, player.base_dodgecooldown);
	DrawCooldownNumber(x, y, player.shootcooldown, player.base_shootcooldown);
	DrawCooldownNumber(x, y, player.slashcooldown, player.base_slashcooldown);
}

void GameUI::DrawHotbar()
{
	DrawSkill(1000, 600, skill_dodge_handler, player.dodgecooldown,player.base_dodgecooldown);
	DrawSkill(1100, 600, skill_bullet_handler,player.shootcooldown, player.base_shootcooldown);
	DrawSkill(1200, 600, skill_slash_handler, player.slashcooldown, player.base_shootcooldown);
}