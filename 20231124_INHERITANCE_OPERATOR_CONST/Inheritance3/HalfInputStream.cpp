#include "HalfInputStream.h"
#include <iostream>
using namespace std;

void HalfInputStream::SetBase()
{
	InputStream::SetBase();
	cin >> m_n;

	m_n /= 2;
}

