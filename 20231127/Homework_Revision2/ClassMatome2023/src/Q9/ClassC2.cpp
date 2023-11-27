#include "ClassP.h"
#include "ClassC2.h"
#include <iostream>
using namespace std;

ClassC2::ClassC2(int a_)
{
	m_a = a_;
}

void ClassC2::Set()
{
	m_a += (10 + rand() % 10);
}

void ClassC2::Show()
{
	cout << "”’l: " << m_a << endl;
}

