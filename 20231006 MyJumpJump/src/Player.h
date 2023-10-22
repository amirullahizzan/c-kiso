#pragma once
void playerInit();
void playerUpdate();
void playerRender();
void playerSetDamage();
void playerDamageUpdate();
Box getPlayer();


enum JUMP_STATE
{
	NONE = 0,
	STEP1, STEP2,
};

