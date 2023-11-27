#pragma once

class BaseNum
{
private:
	int value = 0;
public:
	virtual void Set();
	virtual int Get();
};