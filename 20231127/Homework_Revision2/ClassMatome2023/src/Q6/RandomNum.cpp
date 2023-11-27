#include "BaseNum.h"
#include "RandomNum.h"
#include <iostream>
using namespace std;

void RandomNum::Set()
{
	m_n = 1 + rand() % 100;
}

int RandomNum::Get() 
{
	return m_n;
}
