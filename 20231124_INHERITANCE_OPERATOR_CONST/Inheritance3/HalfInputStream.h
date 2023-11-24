#pragma once

#include "Stream.h"
#include "InputStream.h"

using namespace std;

class HalfInputStream : public InputStream
{
protected :
	void SetBase() override;
};
