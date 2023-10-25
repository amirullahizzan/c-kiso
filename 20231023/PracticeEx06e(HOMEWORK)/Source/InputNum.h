#pragma once

class InputNum
{
private :
	int min_ = 0;
	int max_ = 0;
	int value_ = 0;
public :
	InputNum(int min, int max);
	void set();
	int get();

};

