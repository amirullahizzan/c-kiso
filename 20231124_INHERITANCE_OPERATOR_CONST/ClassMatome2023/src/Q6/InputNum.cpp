#include "InputNum.h"
#include <iostream>
using namespace std;

void InputNum::Set()
{
	cout << "���l����� > " << flush;
	cin >> m_n;
}

int InputNum::Get() const
{
	return m_n;
}
