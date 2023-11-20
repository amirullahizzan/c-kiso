#include "WinMain.h"
#include "SceneBase.h"
#include "Scene2.h"


void Scene2::init()
{
	A_pressed_counter = 0;
}


void Scene2::updateBody()
{
	if (IsKeyOn(KEY_INPUT_A))
	{
		A_pressed_counter++;
	}
	if (A_pressed_counter >= 3)
	{
		setSceneEnd();
	}
}

void Scene2::renderBody()
{
	DrawCenterString(WINDOW_H / 2, "Scene 2!", 25, GREEN);
}