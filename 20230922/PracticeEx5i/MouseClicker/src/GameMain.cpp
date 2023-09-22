#include "WinMain.h"
#include "../Hitbox.h"

int score = 0;
int mousex = 0;
int mousey = 0;

class Circle
{
	
	void ResetOnDisappear()
	{
		if (rad[radindex] < 0.15)
		{
			RandomizeCircle();
		}
	}
	void DecayMe()
	{
		raddecay += 0.01f;
		rad[radindex] -= raddecay;
	}

public :
	float x = 0;
	float y = 0;
	float rad[6] = { 25,35,45,55,65,75 };
	int radindex = 0;
	float raddecay = 0;

void RandomizeCircle()
{

 radindex = GetRand(5);
 raddecay = 0;
 x = GetRand(WINDOW_W - (int)rad[radindex]) + (int)rad[radindex];
 y = GetRand(WINDOW_H - (int)rad[radindex]) + (int)rad[radindex];

}

bool ClickHitBox()
{
	return IsMouseOn(0x0001) && CheckCircleHitBox(mousex, mousey, x, y, rad[radindex]);
}


void Update()
{
	DecayMe();
	ResetOnDisappear();
}

void Render(int red, int green, int blue)
{
	DrawCircleAA(x, y, rad[radindex],64, GetColor(red, green, blue), 1);
}
};
Circle hitcircle;
Circle enemycircle;

bool CheckCircleHitBox(int pointx,int pointy,const Circle circle)
{
	float dx = pointx - circle.x;
	float dy = pointy - circle.y;
	float distance = sqrtf((dx * dx) + (dy * dy));
	if (distance <= circle.rad[circle.radindex])
	{
		return true;
	}
}

void AddScore()
{
	score++;
}
void ReduceScore()
{
	score--;
}



// =====================================================
//		‰Šú‰»
// =====================================================
void GameInit()
{
	hitcircle.RandomizeCircle();
}

void GameUpdate()
{
	mousex = GetMouseX();
	mousey = GetMouseY();
	
	hitcircle.Update();
	
	if (hitcircle.ClickHitBox())
	{
		hitcircle.RandomizeCircle();
		AddScore();
	}

	if (CheckCircleHitBox(mousex,mousey,enemycircle))
	{
		enemycircle.RandomizeCircle();
		ReduceScore();
	}

}

// =====================================================
//		•`‰æ
// =====================================================
void GameDraw()
{
	hitcircle.Render(255,0,0);
	enemycircle.Render(255,255,0);
	DrawFormatString(20,20,GetColor(255,255,0),"Score : %d", score);
	DrawFormatString(20,20,GetColor(255,255,0),"Raddecay : %d", enemycircle.raddecay);
}

// =====================================================
//		I—¹
// =====================================================
void GameExit()
{

}
