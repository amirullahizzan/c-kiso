#include "InputStream.h"
#include <iostream>
using namespace std;

//InputStream::InputStream(): Stream(-1)
InputStream::InputStream()
{
	cout << "InputStream �R���X�g���N�^�[���Ă΂�܂��� " << endl;
}

bool InputStream::Set()
{
	std::cin >> m_n;
	return m_n >= 0;
}

void InputStream::SetBase()
{
	cout << "InputStream::SetBase" << endl;
	cin >> m_n;
}


