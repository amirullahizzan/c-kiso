#include "WinMain.h"
#include "Entity.h"

static bool isInControl = true;



void KeyControl()
{

	if (IsKeyRepeat(KEY_INPUT_RIGHT) || IsKeyRepeat(KEY_INPUT_D))
	{
		camera_x += 5;
	}
	if (IsKeyRepeat(KEY_INPUT_LEFT) || IsKeyRepeat(KEY_INPUT_A))
	{
		camera_x -= 5;
	}
	if (IsKeyRepeat(KEY_INPUT_UP) || IsKeyRepeat(KEY_INPUT_W))
	{
		camera_y -= 5;

	}
	if (IsKeyRepeat(KEY_INPUT_DOWN) || IsKeyRepeat(KEY_INPUT_S))
	{
		camera_y += 5;

	}
}