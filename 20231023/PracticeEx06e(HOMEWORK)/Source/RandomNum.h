#pragma once

class RandomNum
{
private :
	int value_ = 0;
	int count_ = 0;
	
public :
	int min_ = 0; //minimum number of rand
	RandomNum(int min, int count);
	void set();
	void show();

};

