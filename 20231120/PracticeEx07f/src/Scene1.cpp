#include "WinMain.h"
#include "SceneBase.h"
#include "Scene1.h"

void Scene1::init()
{

}

void Scene1::updateBody()
{
	if (IsKeyOn(KEY_INPUT_RETURN))
	{
		setSceneEnd();
	}
}

void Scene1::renderBody()
{
	
	DrawCenterString(WINDOW_H/2,"YELLOw!",25,YELLOW);
}