#include "Base.h"
#include <iostream>
using namespace std;

Base::Base() :
	m_n(0)
{

}

void Base::Set()
{
	cout << "Base::Set()" << endl;
}

void Base::Mul()
{
	m_n *= 2;
}

int Base::Get() const
{
	return m_n;
}
