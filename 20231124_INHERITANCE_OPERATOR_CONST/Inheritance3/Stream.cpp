#include "Stream.h"
#include <iostream>
using namespace std;

//Stream::Stream(int n)
Stream::Stream() : m_n (-1)
{
	cout << "Stream コンストラクターが呼ばれました " << endl;
}

const double Stream::Get()
{
	return m_n;
}

bool Stream::Set()
{
	return m_n >= 0;
}

//void Stream::SetBase()
//{
//	cout << "Stream::SetBase()" << endl;
//	m_n = -1;
//}