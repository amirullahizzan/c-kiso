#pragma once

class Pos2
{
public:
	float x = 0, y = 0;
	Pos2(float x_ = 0, float y_ = 0);
	~Pos2() {}

	float getDist(const Pos2& other) const;	// ψuothervΖΜ£πͺι
};

