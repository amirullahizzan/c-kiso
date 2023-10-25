#include <iostream>
#include "ArrayNum.h"


ArrayNum::ArrayNum()
{
	for (int i = 0; i < 5; i++)
	{
		values_[i] = 0;
	}

	size_ = 5;
}

void ArrayNum::set(int index, int newval)
{
	if (index < size_)
	{
		values_[index] = newval;
	}
	else
	{
		return;
	}

}

int ArrayNum::get(int index)
{
	if (index < size_)
	{
		return values_[index];
	}
	else if (index >= size_)
	{
		return -1;
	}
}

int ArrayNum::getSize()
{
	return size_;
}

void ArrayNum::show()
{
	for (int i = 0;i < size_;i++)
	{
		std::cout << i<<": " << values_[i] << std::endl;
	}

}
