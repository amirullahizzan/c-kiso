#include "WinMain.h"
#include "Hit.h"
// ============================================
//	“–‚½‚è”»’èŠÖ”ŒQ
// ============================================
bool isHit(const Pos2& pos1, float r1, const Pos2& pos2, float r2)
{
	float distance = pos1.getDist(pos2);
	float r_sum	   = r1 + r2;

	return distance < r_sum;
}