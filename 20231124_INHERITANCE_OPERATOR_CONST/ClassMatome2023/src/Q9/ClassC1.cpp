#include "ClassP.h"
#include "ClassC1.h"
#include <iostream>
using namespace std;

ClassC1::ClassC1(int a_)
{
	m_a = a_;
	m_a = m_a * 2;
}

void ClassC1::Set()
{
	m_a += rand() % 10;
}

void ClassC1::Show()
{
	cout << "”’l: " << m_a << endl;
}

