#pragma once
#include "../WinMain.h"
#include "CustomSystem.h"

int pointer_handler = 0;

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
	const int IMAGESIZE = 100;

	
void DrawCooldown(int x, int y);
	
	void DrawSkillBullet(int x, int y)
	{
		DrawGraph(x, y, skill_bullet_handler, 1);
		DrawCooldown(x, y);
	}

public :

	void Init()
	{
		skill_bullet_handler = LoadGraph("data/skill_shoot_icon.png");
	}

	void DrawHotbar()
	{
		DrawSkillBullet(600,100);
	}

};

GameUI gameui;
GameDialogBox tutorialbox;
Debug debug;