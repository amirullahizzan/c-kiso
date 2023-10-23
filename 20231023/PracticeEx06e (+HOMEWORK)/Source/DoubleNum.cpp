#include <iostream>
#include "DoubleNum.h"

DoubleNum::DoubleNum(int value)
{
	value_ = value;
}

int DoubleNum::set(int value)
{
	return value_ = value * 2;
}

void const DoubleNum::show()
{
	std::cout << value_ << std::endl;
}