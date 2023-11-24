#pragma once
#include "Stream.h"

class InputStream : public Stream
{
public:
	InputStream();
	bool Set();
protected:
	void SetBase() override;
};