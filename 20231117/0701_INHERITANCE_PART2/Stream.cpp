#include "Stream.h"
#include <iostream>
using namespace std;

const double Stream::Get()
{
	return m_n;
}

bool Stream::Set()
{
	std::cout << "Stream::Set" << std::endl;
	m_n = -1;
	return false;
}

void Stream::SetBase()
{
	cout << "Stream::SetBase()" << endl;
	{

	}
}