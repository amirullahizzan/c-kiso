#include "BaseObj.h"
#include "RedBall.h"

RedBall::RedBall(Pos pos_):
	BaseObj(pos_)
{
	SetGhandle("data/ornament.png");
}

RedBall::~RedBall()
{

}

void RedBall::Update()
{
	constexpr float MIN_SIZE= 0.2f;
	constexpr float MAX_SIZE = 1.2f;
	switch (isExpanding)
	{
	case true :
			m_ex_rate += 0.02f;
		if (m_ex_rate > MAX_SIZE)
		{
			isExpanding = false;
		}
		break;

	case false:
			m_ex_rate -= 0.02f;
		if (m_ex_rate < MIN_SIZE)
		{
			isExpanding = true;
		}
		break;
	}
	

	
}

