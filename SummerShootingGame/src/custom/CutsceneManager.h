#pragma once

//SCENES
bool isMainMenu = true;
bool isGame = false;
bool isGameOver = false;
bool isGameClear = false;

bool isInControl = true;
bool isReadyCheck = false;
bool isGOText = false;

int alphain = 255;
int alphaout = 0;

void FadeEffect(int status);

enum FadeEnum
{
	FADEIN = 0,
	FADEOUT = 1,
	RESET = 2
};
