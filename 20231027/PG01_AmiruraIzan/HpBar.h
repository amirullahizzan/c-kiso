#pragma once

class HpBar
{
private :
	int heart_handler = 0;
	int basehp_ = 100;

	//bar
	int BAR_WIDTH = 0;
	int BAR_HEIGHT = 0;
	int pos_x = 0;
	int pos_y = 0;
	int pos_x2 = 0;
	int pos_y2 = 0;

	//heart
	int heart_size = 0;
	int heart_x = 0;
	int heart_y = 0;
public :
	int green_pos_x2 = 0;
	int hp_ = 100;
	HpBar(int x, int y, int width, int height);

	void init();
	void update();
	void render();
	void exit();
	void reset();
	//void damage(int damageamount);

	//default operator overloading
	void operator-=(int value);
	bool operator<=(int value);

};
