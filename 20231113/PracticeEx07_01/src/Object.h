#pragma once

class Object
{
protected:
	int x_ = 0;
	int y_ = 0;
public:
	int  getRandNum(int max, int min = 0);

	int getX() const
	{
		return x_;
	}
	int getY() const
	{
		return y_;
	}
};