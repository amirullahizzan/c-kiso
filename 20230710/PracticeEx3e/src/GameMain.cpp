#include "WinMain.h"
#include <iostream>
#include <cmath>
#include <limits>
#include <minwindef.h>


using namespace std;

int circle_x[10];
int circle_y[10];
int circle_rad[10];


int middle_distance[10];
double dx;
double dy;

int line_x;
int line_y;

int mid_x = WINDOW_W / 2;
int mid_y = WINDOW_H / 2;

void GameInit()
{
	InitCircle();
}

int closest_dist = INT_MAX;


void GameUpdate()
{

	if (IsKeyOn(KEY_INPUT_SPACE))
	{
		closest_dist = INT_MAX;

		for (int i = 0; i < 10; i++)
		{
		
			//Count MinMax Random
			/*circle_rad[i] = GetRand(35 - 15) + 15;*/
			circle_x[i] = GetRand(WINDOW_W - circle_rad[i]);
			circle_y[i] = GetRand(WINDOW_H - circle_rad[i]);

			if (circle_x[i] < (0 + circle_rad[i]))
			{
				circle_x[i] = GetRand(WINDOW_W - circle_rad[i]);
				i--;
				continue;
			}

			/*if (circle_y[i] < (0 + circle_rad[i]))
			{
				circle_y[i] = GetRand(WINDOW_H - circle_rad[i]);
				i--;
				continue;
			}*/

			

		}

	}
	


	
	
}


void GameDraw()
{

	MiddleCircle();
	DrawRandomCircles();


	for (int i = 0; i <10 ;i++)
	{
		dx = abs(mid_x - circle_x[i]);
		dy = abs(mid_y - circle_y[i]);

		middle_distance[i] = static_cast<int>(sqrt(pow(dx, 2) + pow(dy, 2)));

		if (closest_dist > middle_distance[i])
		{
			closest_dist = middle_distance[i];
			line_x = circle_x[i];
			line_y = circle_y[i];
			

		}
	}
	
	DrawLine(mid_x, mid_y, line_x, line_y, RED, 1);


}



void GameExit()
{


}

void MiddleCircle()
{
	DrawCircle(mid_x, mid_y, 25, PINK, 1, 1);
}

void InitCircle()
{
	for (int i = 0; i < 10; i++)
	{
		//Count MinMax Random
		circle_rad[i] = GetRand(35 - 15) + 15;
		circle_x[i] = GetRand(WINDOW_W/2 - circle_rad[i]);
		circle_y[i] = GetRand(WINDOW_H/2 - circle_rad[i]);

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

