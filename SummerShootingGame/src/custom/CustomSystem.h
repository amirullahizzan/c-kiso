#pragma once
#include "../WinMain.h"

int pointer_handler = 0;
//SYSTEM

int game_frame = 0;
int fontsize = 24;
int MOJISIZE = 7;

struct Debug
{
private:

public:

	void DisplayCenterGrid()
	{
		DrawLine(0, CENTERY, WINDOW_W, CENTERY, YELLOW, 1);
		DrawLine(CENTERX, 0, CENTERX, WINDOW_H, YELLOW, 1);
	}

	void DebugControl();
};

struct GameDialogBox
{
private:
	int x = WINDOW_W / 2;
	int y = 620;
	int border = 3;
	bool isDone = false;
	int counter_ms = 0;
	bool isBoxAnimDone = false;

	int x_anim = 0;
	int y_anim = 0;

	int cursor_y_anim = 0;
	int cursor_y_anim_ms = 0;
public:

	bool isTutorialOver = false;

	GameDialogBox() : isDone(false)
	{
	}

	void DrawContinueDialog(int x, int y)
	{
		DrawRotaGraph(x + 90, y - 120 + cursor_y_anim, 1, PI / 2, pointer_handler, 1, 0, 0);
		cursor_y_anim_ms++;
		if (cursor_y_anim_ms > 6)
		{
			cursor_y_anim++;
			cursor_y_anim_ms = 0;
			if (cursor_y_anim > 7)
			{
				cursor_y_anim = 0;
			}
		}
	}

	void DrawDialogBox(int width, const char* string)
	{
		counter_ms++;

		if (counter_ms > 5 && !isBoxAnimDone)
		{
			x_anim += 5;
			y_anim += 3;
			//DrawBox(x_anim - border, y_anim - border, x_anim + + border, y_anim + 100 + border, WHITE, 1);
			DrawBox(x - x_anim - width / 2, y + (50) - y_anim, x + x_anim + width / 2, y + (50) + y_anim, BLACK, 1);

			if (counter_ms > 25)
			{
				isBoxAnimDone = true;
			}
		}
		if (isBoxAnimDone)
		{
			if (!isDone)
			{
				DrawBox(x - width - border, y - border, x + width + border, y + 100 + border, WHITE, 1);
				DrawBox(x - width, y, x + width, y + 100, BLACK, 1);
				DrawString(x - width + border * 2, y + border * 2, string, YELLOW, 0);
				DrawContinueDialog(x + width - width / 3, y + 200);

			}
			if (IsKeyOn(KEY_INPUT_RETURN) && isBoxAnimDone)
			{
				isDone = true;
				isTutorialOver = true;
			}
		}

	}


};

struct GameUI 
{
private :
	int skill_bullet_handler = 0;
	int skill_dodge_handler = 0;
	int skill_slash_handler = 0;
	const int IMAGESIZE = 100;
	int _IMGSIZE = 96;
	
	void DrawCooldownNumber(int x, int y, int cooldown, int base_cooldown);
	
	void DrawSkill(int x, int y, int icon_handler, int skillcooldown, int base_skillcooldown);

public :

	void Init()
	{
		skill_bullet_handler = LoadGraph("data/skill_shoot_icon.png");
		skill_dodge_handler = LoadGraph("data/skill_dodge_icon.png");
		skill_slash_handler = LoadGraph("data/skill_slash_icon.png");
	}

	void DrawHotbar();

};
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

	int confirmtimer = 300;
	bool isGameConfirm = false;

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
			isGameConfirm = true;
		}
		if (isGameConfirm==true)
		{
			FadeEffect(FADEOUT);
			confirmtimer--;
			if (confirmtimer<=0)
			{
				isMainMenu = false;
				isGame = true;
			}
		}

		if (pointer_int == 1 && IsKeyOn(KEY_INPUT_RETURN))
		{
			exit(0);
		}
	}

public:

	void DrawMainMenu()
	{
		//fadein
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
GameUI gameui;
GameDialogBox tutorialbox;
Debug debug;