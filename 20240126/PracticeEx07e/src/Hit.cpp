#include "WinMain.h"
#include "Hit.h"

bool HitPoint(const Pos& point_pos, const Pos& obj_pos, float obj_r)
{
	float a = point_pos.x - obj_pos.x;
	float b = point_pos.y - obj_pos.y;
	float c = sqrtf(a * a + b * b);

	return c <= obj_r;
}