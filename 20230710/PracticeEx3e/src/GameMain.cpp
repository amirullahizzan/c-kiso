#include "WinMain.h"
#include <cmath>

int circle_x[10];
int circle_y[10];
int circle_rad[10];


int middle_distance[10];
int dx;
int dy;

int line_x;
int line_y;

void GameInit()
{
	InitCircle();


}



void GameUpdate()
{

	if (IsKeyOn(KEY_INPUT_SPACE))
	{
		for (int i = 0; i < 10; i++)
		{
			//Count MinMax Random
			circle_rad[i] = GetRand(35 - 15) + 15;
			circle_x[i] = GetRand(WINDOW_W - circle_rad[i]);
			circle_y[i] = GetRand(WINDOW_H - circle_rad[i]);

			if (circle_x[i] < (0 + circle_rad[i]))
			{
				circle_x[i] = GetRand(WINDOW_W - circle_rad[i]);
				i--;
				continue;
			}

			if (circle_y[i] < (0 + circle_rad[i]))
			{
				circle_y[i] = GetRand(WINDOW_H - circle_rad[i]);
				i--;
				continue;
			}

		}
	}
	

	for (int i = 0; i < 10; i++)
	{
		//somethig wrong
		dx = circle_x[i] - WINDOW_W / 2;
		dy = circle_y[i] - WINDOW_H / 2;
		middle_distance[i] = sqrt((dx * dx) + (dy * dy));
		if ((middle_distance[i] < middle_distance[i - 1]))
		{
			line_x = circle_x[i];
			line_y = circle_y[i];
		}

	}
	
}


void GameDraw()
{

	MiddleCircle();
	DrawRandomCircles();

	
	
	DrawLine(WINDOW_W / 2, WINDOW_H / 2, line_x, line_y, RED, 1);



}


void GameExit()
{


}

void MiddleCircle()
{
	DrawCircle(WINDOW_W / 2, WINDOW_H / 2, 25, PINK, 1, 1);
}

void InitCircle()
{
	for (int i = 0; i < 10; i++)
	{
		//Count MinMax Random
		circle_rad[i] = GetRand(35 - 15) + 15;
		circle_x[i] = GetRand(WINDOW_W - circle_rad[i]);
		circle_y[i] = GetRand(WINDOW_H - circle_rad[i]);

		if (circle_x[i] < (0 + circle_rad[i]))
		{
			circle_x[i] = GetRand(WINDOW_W - circle_rad[i]);
			i--;
			continue;
		}

		if (circle_y[i] < (0 + circle_rad[i]))
		{
			circle_y[i] = GetRand(WINDOW_H - circle_rad[i]);
			i--;
			continue;
		}

	}



}

void DrawRandomCircles()
{
	for (int i = 0; i < 10; i++)
	{
		DrawCircle(circle_x[i], circle_y[i], circle_rad[i], YELLOW, 1, 1);
	}
}

