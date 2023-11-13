#pragma once

class Person
{
private:
protected:
	const char* name_ = nullptr;

public:
	void set(const char* name);
	const char* getName() const
	{
		return name_;
	}
};