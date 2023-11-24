#pragma once

class Stream 
{
public :
	//Stream(int n);
	Stream();
	const double Get();
	 bool Set();
protected:
	virtual void SetBase() = 0;

	double m_n = 0;
};