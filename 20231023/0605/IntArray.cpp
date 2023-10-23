#include "IntArray.h"
#include <iostream>

using namespace std;

IntArray::IntArray()
{
	//fill_n は指定したデータで配列などを埋める関数のようなものです
	fill_n(m_array, INTARRAY_SIZE, 0);

	cout << "コンストラクターが呼ばれました" << endl;
}

int IntArray::Get(int i)
{
	CheckIndex(i);
	return m_array[i];
}

void IntArray::Set(int i, int value)
{
	CheckIndex(i);
	m_array[i] = value;
}

void IntArray::CheckIndex(int i)
{

	if (0 <= i && i < INTARRAY_SIZE)
	{
		//Index 正常
	}
	else
	{
		cout << "インデックスが不正です！！" << endl
		<< "値：" << i << endl;
		exit(EXIT_FAILURE);
	}

}
