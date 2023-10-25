#include <iostream>
#include "DoubleNum.h"

DoubleNum::DoubleNum()
{
	value_ = 0;
}

int DoubleNum::set(int value)
{
	return value_ = value * 2;
}

void const DoubleNum::show()
{
	std::cout << value_ << std::endl;
}