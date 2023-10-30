

#include "WinMain.h"
#include "Entity.h"
#include "../custom/VisualNovel.h"
//#include "//"

float camera_x = 0;
float camera_y = 0;
bool spaceKeyPressed = false;

#define MAX_ENEMY 15

enum gameStateEnum
{
	MainMenuInit = 0,
	MainMenuState = 1,
	GameplayInit = 2,
	GameplayState = 3,
};

static int gameState = GameplayInit;

static Pos2 playerpos;
static Pos2 enemypos;
DialogueBox box1(50, 50, 300, 100, "boxImage1.png", 20);
DialogueBox box2(50, 200, 300, 100, "boxImage2.png", 20);
DialogueBox* currentDialogue = &box1;

void Debug()
{
	printfDx("player pos : %f\n",enemypos.GetX());
	printfDx("cam pos : %f\n",camera_x);
	printfDx("gamestate %d\n",gameState);
}


void GameInit()
{
	box1.AddText("This is the first line of dialogue. Press Space for the next.");
	box1.AddText("Second line of the first dialogue box.");
	box2.AddText("Next dialogue box. Press Space to continue.");
	box2.AddText("Second line of the second dialogue box.");
	
}


void GameUpdate()
{



	switch (gameState)
	{
	case MainMenuInit:
		gameState = MainMenuState;
		break;

	case MainMenuState:
		//if click play
		break;

	case GameplayInit:
		playerpos.InitEntity(WINDOW_W_HALF, WINDOW_H - 55);
		gameState = GameplayState;
		break;

	case GameplayState:
		
		KeyControl();
		currentDialogue->DisplayText();

		if (CheckHitKey(KEY_INPUT_SPACE)) {
			spaceKeyPressed = true;
		}
		else if (spaceKeyPressed) {
			if (currentDialogue->GetDialogueTextsSize() == currentDialogue->GetCurrentTextIndex()) {
				// If all texts in the current dialogue box have been displayed
				if (currentDialogue == &box1) {
					currentDialogue = &box2;  // Move to the next dialogue box
				}
			}
			spaceKeyPressed = false;
			currentDialogue->NextText();

		}

		

		break;

	}

}


void GameDraw()
{
	Debug();
	switch (gameState)
	{
	case MainMenuInit:
		break;

	case MainMenuState:
		//if click play
		break;

	case GameplayInit:
		break;

	case GameplayState:
		printfDx("%d",currentDialogue->GetCurrentTextIndex());
		currentDialogue->DisplayText();

		playerpos.RenderEntityFreeze(GREEN);
		KeyControl();

		enemypos.RenderEntity(RED);


		for (int i = 0; i < MAX_ENEMY; i++)
		{
			//DrawCircle(enemypos.GetX(), enemypos.GetY(), 25, RED, 1, 1);
		}

		break;

	}

}

void GameExit()
{

}
