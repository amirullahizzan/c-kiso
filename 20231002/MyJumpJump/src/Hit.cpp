#include "WinMain.h"
#include "Common.h"

bool CheckHit(Box& box1, Box& box2)
{
	if (box1.x + box1.w >= box2.x && box1.x <= box1.x + box1.w)
	{
		if (box1.y + box1.h >= box2.y && box1.y <= box2.y + box2.h)
		{
		return true;
		}
	}
	return false;
}