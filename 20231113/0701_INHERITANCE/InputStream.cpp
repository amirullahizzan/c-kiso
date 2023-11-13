#include "InputStream.h"

bool InputStream::Set()
{
	std::cin >> m_n;
	return m_n >= 0;
}
