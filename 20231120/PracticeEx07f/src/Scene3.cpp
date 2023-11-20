#include "WinMain.h"
#include "SceneBase.h"
#include "Scene3.h"

void Scene3::init()
{
	timer = 100;
}

void Scene3::updateBody()
{
	static int tick = 0;
	tick++;
	if (tick % 1000)
	{
		timer -= 1;
	}
	if (timer <= 0)
	{
		setSceneEnd();
	}
}

void Scene3::renderBody()
{
	DrawCenterString(WINDOW_H / 2, "SCEENE #3!", 25, RED);
	 int storefont = GetFontSize();
	 SetFontSize(50);
	 const char* str = " Time left : %d";
	 int font_w = GetDrawStringWidth(str, (int)strlenDx(str));
	DrawFormatString(WINDOW_W/2 - font_w / 2, WINDOW_H / 2 + 50,GREEN,str,timer);
	SetFontSize(storefont);
}