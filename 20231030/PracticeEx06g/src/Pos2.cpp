#include "Pos2.h"
#include <cmath>

Pos2::Pos2(float x_, float y_) :
	x(x_), y(y_)
{

}

float Pos2::getDist(const Pos2& other) const
{
	float dist_x = x - other.x;
	float dist_y = y - other.y;
	return sqrtf(dist_x * dist_x + dist_y * dist_y);
}
