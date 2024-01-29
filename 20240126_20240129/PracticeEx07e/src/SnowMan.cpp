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

void SnowMan::Update()
{
	constexpr float MIN_MOV = 0.0f;
	constexpr float MAX_MOV = 5.0f;
	switch (isFalling)
	{
	case true:
		m_pos.y += 1.0f;
		moveAmount += 1.0f;
		if (moveAmount > MAX_MOV)
		{
			isFalling = false;
		}
		break;

	case false:
		m_pos.y -= 1.0f;
		moveAmount -= 1.0f;
		if (moveAmount < MIN_MOV)
		{
			isFalling = true;
		}
		break;
	}


}
