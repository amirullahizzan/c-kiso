#pragma once

/////////////////////////////////
//”z—ñ‚ð‚P‚O‚OŒÂ
/////////////////////////////////
static const int INTARRAY_SIZE = 100;

class IntArray
{
public:
	int m_array[INTARRAY_SIZE];

	IntArray();

	int Get(int i);
	void Set(int i, int value);

	void CheckIndex(int i);

};