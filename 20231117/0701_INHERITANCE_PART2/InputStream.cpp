#include "InputStream.h"
#include <iostream>

bool InputStream::Set()
{
	std::cin >> m_n;
	return m_n >= 0;
}
