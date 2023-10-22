#include "WinMain.h"
#include "Common.h"

bool CheckHitBox(const Box& box1, const Box& box2)
{

	if (
		(box1.x + box1.w / 2) >= (box2.x - box2.w / 2) &&
		(box1.x - box1.w / 2) <= (box2.x + box2.w / 2)
		)
		{
		if (
			(box1.y + box1.h / 2) >= (box2.y - box2.h / 2) &&
			(box1.y - box1.h / 2) <= (box2.y + box2.h / 2)
			)
		{
		return true;
		}
		}
	return false;
}