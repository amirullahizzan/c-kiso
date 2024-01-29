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

void SnowFlake::Update()
{
		if (m_angle < 3.14f) { m_angle += 0.02f; return; }
		else if(m_angle >= 3.14f) { m_angle = 0.1f; }
}
