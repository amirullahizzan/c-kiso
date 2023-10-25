#include "Num.h"

Num::Num()
{
	num1_ = 0;
	num2_ = 0;
}

void Num::set(int num1, int num2)
{
	num1_ = num1;
	num2_ = num2;
}
int Num::getMin()
{
	if (num1_ < num2_)
	{
		return num1_;
	}
	else
	{
		return num2_;
	}
}

int Num::getMax()
{
	if (num1_ > num2_)
	{
		return num1_;
	}
	else
	{
		return num2_;
	}
}