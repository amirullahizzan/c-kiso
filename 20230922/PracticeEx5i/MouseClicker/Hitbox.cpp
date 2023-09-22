#include "src/WinMain.h"

bool CheckCircleHitBox(int pointx, int pointy, float x, float y, float rad)
{
	float dx = pointx - x;
	float dy = pointy - y;
	float distance = sqrtf((dx * dx) + (dy * dy));
	if (distance <= rad)
	{
		return true;
	}
}

