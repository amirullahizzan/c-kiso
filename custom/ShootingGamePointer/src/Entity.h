#pragma once

extern float camera_x;
extern float camera_y;

class Pos2
{
private:
	float x_ = 0;
	float y_ = 0;


public:

	float GetX()
	{
		return x_ + camera_x;
	}
	float GetY()
	{
		return y_ + camera_y;
	}
	void SetX(float x)
	{
		x_ = x + camera_x;
	}

	void SetY(float y)
	{
		y_ = y + camera_y;
	}

	float PointDistance(Pos2 point1, Pos2 point2)
	{
		float dx = point2.GetX() - point1.GetX();
		float dy = point2.GetY() - point1.GetY();
		return static_cast<float>(	sqrt(pow(dx, 2) + pow(dy, 2))	);
	}

	bool IsPointHit()
	{

	}

	void  InitEntity(float x, float y)
	{
		x_ = x;
		y_ = y;
	}
	
	void  UpdateEntity()
	{

	}

	void RenderEntity(int color)
	{
		DrawCircleAA(GetX(), GetY(), 50, 64, color, 1, 1);
	}

	void RenderEntityFreeze(int color)
	{
		DrawCircleAA(x_, y_, 50, 64, color, 1, 1);
	}

};

void KeyControl();