#include "BaseObj.h"
#include "SnowFlake.h"

SnowFlake::SnowFlake(Pos pos_) :
	BaseObj(pos_)
{
	SetGhandle("data/snowflake.png");
}

SnowFlake::~SnowFlake()
{

}
