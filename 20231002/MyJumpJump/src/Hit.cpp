#include "WinMain.h"
#include "Common.h"

bool CheckHitBox(Box& box1, Box& box2)
{
	if (box1.x + box1.w / 2 >= box2.x && box1.x <= box2.x + box2.w)
	{
		if (box1.y + box1.h / 2 >= box2.y && box1.y <= box2.y + box2.h)
		{
		return true;
		}
	}
	return false;
}