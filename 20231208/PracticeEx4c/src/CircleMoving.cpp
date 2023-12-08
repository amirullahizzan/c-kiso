#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "CircleBase.h"
#include "CircleMoving.h"
// =====================================================
//	移動する円クラス（ソースファイル）
//	 ターゲットに移動する円
// =====================================================
CircleMoving::CircleMoving(float size) :
	CircleBase(size),
	MAX_SIZE(size)
{

}

void CircleMoving::MoveTo(Pos _targetpos)
{
	float px = pos_.x - _targetpos.x;
	float py = pos_.y - _targetpos.y;

	double dist = getDist(getPos(), target_->getPos());
	double angle = (atan2(py, px));
	double mult = speed * 0.01 * dist;
	force.x = static_cast<float>(cos(angle) * mult);
	force.y = static_cast<float>(sin(angle) * mult);

	pos_.x -= force.x;
	pos_.y -= force.y;

}
// -----------------------------------------------------
//	更新処理
// -----------------------------------------------------
void CircleMoving::update()
{
	setColor(PINK, true);
	size_ = 25;
	if (target_ != nullptr)
	{
		//pos_ = target_->getPos();
		MoveTo(target_->getPos());
		//setPos(target_->getPos());
	}

}

void CircleMoving::ResetSpeed()
{
	speed = base_speed;
}