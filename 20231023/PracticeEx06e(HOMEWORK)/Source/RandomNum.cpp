#include "RandomNum.h"
#include <iostream>

RandomNum::RandomNum(int min, int count)
{
	min_ = min;
	count_ = count;
	value_ = -1;
}

void RandomNum::set()
{
	value_ = count_+min_;
}

void RandomNum::show()
{
	std::cout << "‰¿F" << value_ << std::endl;
}