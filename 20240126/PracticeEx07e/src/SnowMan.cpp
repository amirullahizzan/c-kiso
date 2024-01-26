#include "BaseObj.h"
#include "SnowMan.h"

SnowMan::SnowMan(Pos pos_) :
	BaseObj(pos_)
{
	SetGhandle("data/SnowMan.png");
}

SnowMan::~SnowMan()
{

}
