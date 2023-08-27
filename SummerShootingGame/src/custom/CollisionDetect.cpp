#include "../WinMain.h"

bool IsCollisionDetect(int x1, int y1, int x2, int y2, int r1, int r2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	double distance = sqrt((dx * dx) + (dy * dy));
	return distance < r1 + r2;
}

bool IsBoxCollide(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	if (x1 + w1 >= x2 && x1 <= x2 + w2) 
	{
		if (y1 + h1 >= y2 && y1 <= y2 + h2) 
		{
			return true;
		}
	}
	return false;
}