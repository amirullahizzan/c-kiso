//#ifndef ARRAYSTREAM_H_
//#define ARRAYSTREAM_H_
#pragma once

#include "Stream.h"
#include <iostream>

class ArrayStream : public Stream
{
private:
	const double* m_array = nullptr;
	int m_i = 0; //index

public:
	ArrayStream(const double* array);
	bool Set();
};

//#endif