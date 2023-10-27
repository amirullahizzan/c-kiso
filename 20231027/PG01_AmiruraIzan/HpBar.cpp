#include "WinMain.h"
#include "HpBar.h"


HpBar::HpBar(int x, int y, int width, int height)
{
	pos_x = x;
	pos_y = y;
	BAR_WIDTH = width;
	BAR_HEIGHT = height;
	pos_x2 = x+width;
	pos_y2 = y+height;
}

void HpBar::init()
{
	heart_handler = LoadGraph("data/icon_heart64.png",1);

	heart_size = 1;
	green_pos_x2 = pos_x2;

	heart_x = green_pos_x2;
	heart_y = pos_y+BAR_HEIGHT/2;
}

void HpBar::update()
{
	if (heart_x > green_pos_x2)
	{
		heart_x--;
	}
	else if (heart_x < green_pos_x2)
	{
		heart_x++;
	}
	if (hp_ <= 0)
	{
		hp_ = 0;
	}

}

void HpBar::render()
{
	green_pos_x2 = BAR_WIDTH * hp_ / basehp_ + pos_x;

	DrawFillBox(pos_x , pos_y, pos_x2, pos_y2, BLACK);
	DrawFillBox(pos_x, pos_y, green_pos_x2, pos_y2, GREEN);
	DrawLineBox(pos_x,pos_y,pos_x2, pos_y2,WHITE);
	//DrawRotaGraph(heart_x, heart_y, heart_size,0,heart_handler,1,0,0);
	
}
void HpBar::exit()
{
	DeleteGraph(heart_handler);
}
void HpBar::reset()
{
	hp_ = basehp_;
}
//void HpBar::damage(int damageamount)
//{
//	hp_ -= damageamount;
//}

void HpBar::operator-=(int value)
{
	hp_ -= value;
}

bool HpBar::operator<=(int value)
{
	return hp_ <= value;
}