#include "../WinMain.h"

enum CharDirection
{
	NOBLACK = 0,
	FULLBLACK = 255
};


void CutsceneManager()
{
	
}

void AddRainEffect()
{

}

extern int alphain;
extern int alphaout;

void FadeBlackBox()
{
	DrawBox(0, 0, WINDOW_W, WINDOW_H, BLACK, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
};

bool isDone = false;
void FadeEffect(int status)
{
	enum FadeEnum
	{
		FADEIN = 0,
		FADEOUT = 1,
		RESET = 2
	};

	switch (status)
	{
	case FADEIN:
		if (alphain > NOBLACK)
		{
			alphain-=2;
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, alphain);
			DrawBox(0, 0, WINDOW_W, WINDOW_H, BLACK, TRUE);
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;

	case FADEOUT:
		if (alphaout < FULLBLACK)
		{
			alphaout+=2;
		}
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alphaout);
		DrawBox(0, 0, WINDOW_W, WINDOW_H, BLACK, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		break;
	case RESET :
		if (!isDone)
		{
		alphaout = NOBLACK;
		alphain = FULLBLACK;
		isDone = true;
		}
	}
	

}

