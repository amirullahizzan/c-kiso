#pragma once
#include "../src/WinMain.h"
#include "../src/Hit.h"
#include "Player.h"

class Enemy : public Player
{
private :
	bool isDestroyed = false;

	void initPos()
	{
		pos_ = Pos2(static_cast<float>(WINDOW_W / 2)
			, (float)0 + r_ * 2);
	}
public:
	void init();
	//void update();
	void const render();
	void spawn();
	void moveWave();
	void destroy();
	bool getIsDestroyed();
};