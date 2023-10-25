#include "InputNum.h"
#include <iostream>

InputNum::InputNum(int min, int max)
{
	min_ = min;
	max_ = max;
	value_ = -1;
}

void InputNum::set()
{
	std::cin >> value_;
	while (value_ < min_ || value_ > max_)
	{
	std::cin >> value_;
	}
}

int InputNum::get()
{
	return value_;
}

