#include "RandomNum.h"
#include <iostream>
using namespace std;

void RandomNum::Set()
{
	m_n = 1 + rand() % 100;
}

int RandomNum::Get() const
{
	return m_n;
}
