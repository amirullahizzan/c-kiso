#include "BaseNum.h"
#include "InputNum.h"
#include <iostream>
using namespace std;

void InputNum::Set() 
{
	cout << "”’l‚ð“ü—Í > " << flush;
	cin >> m_n;
}

int InputNum::Get()  
{
	return m_n;
}
