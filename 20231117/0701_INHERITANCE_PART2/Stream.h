#pragma once

class Stream 
{
public :
	const double Get();
	 bool Set();
protected:
	virtual void SetBase();
	double m_n;
};