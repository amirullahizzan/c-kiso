#include "InputNum.h"
#include <iostream>
using namespace std;

void InputNum::Set()
{
	cout << "数値を入力 > " << flush;
	cin >> m_n;
}

int InputNum::Get() const
{
	return m_n;
}
