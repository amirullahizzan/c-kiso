#include "WinMain.h"



int map_ghandles[6];	// マップチップ用画像の配列変数
int chara_ghandles[9];

int player_x;
int player_y;

int player_w;
int player_h;



int map[MAP_H][MAP_W] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};

int map1[MAP_H][MAP_W] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,0,0,0,0,0,0,0,3,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1,0,1,},
	{1,0,0,1,1,1,0,1,1,0,0,1,3,0,1,1,0,1,1,1,1,3,1,0,0,0,1,1,0,1,},
	{1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,3,0,0,0,3,0,0,1,1,1,0,0,0,0,1,},
	{1,0,0,0,0,1,0,3,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,0,1,1,0,1,0,1,},
	{1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,1,1,0,0,0,0,3,1,},
	{1,0,1,0,1,1,0,0,0,0,0,3,0,0,3,0,1,1,0,1,0,0,0,1,0,0,3,1,0,1,},
	{1,0,1,0,0,0,1,1,1,1,1,1,0,1,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,1,},
	{5,5,5,5,1,5,1,5,5,1,5,5,5,1,1,5,1,5,5,1,1,5,5,1,1,1,1,5,5,0,},
	{1,1,0,0,0,0,1,0,1,1,0,1,0,3,0,1,0,1,0,1,0,0,0,1,0,0,1,1,1,4,},
	{1,0,0,1,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,3,},
	{1,0,1,0,1,0,0,1,0,1,0,1,3,0,0,1,0,1,1,1,0,1,0,1,1,0,1,1,0,3,},
	{1,0,0,0,0,0,3,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,1,},
	{1,0,3,1,0,1,0,0,0,1,3,1,0,1,0,1,1,0,1,1,0,0,1,0,3,0,3,1,0,1,},
	{1,0,0,0,0,0,0,3,0,0,0,0,0,1,0,0,0,0,0,0,1,3,1,0,0,0,0,0,0,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};
int map_data = 0;

int map_now[MAP_H][MAP_W];

void GenerateMap(const int this_map[MAP_H][MAP_W])
{
	for (int h = 0; h < MAP_H; h++)
	{
		for (int w = 0; w < MAP_W; w++)
		{
			map_now[h][w] = this_map[h][w];
			map_data = this_map[h][w];
			DrawGraph(IMG_SIZE * w, IMG_SIZE * h, map_ghandles[map_data], FALSE);
		}
	}
}
//int speed;
int player_facing_int;
int player_anim_int;
bool isFinish = false;

struct Vector2
{
	int x;
	int y;
};

struct DialogueMessage
{
private :
	int x;
	int y;

public :
	void DrawMessageBox(int x_size, int y_size)
	{
		DrawBox(WINDOW_W / 2 - x_size - 6, WINDOW_H / 2 - y_size - 6, WINDOW_W / 2 + x_size + 6, WINDOW_H / 2 + y_size + 6, WHITE, 1);
		DrawBox(WINDOW_W / 2 - x_size, WINDOW_H / 2 - y_size, WINDOW_W / 2 + x_size, WINDOW_H / 2 + y_size, BLACK, 1);
	}
};

DialogueMessage finishmessage;

Vector2 playerpos;

int FontSize = 20;

void PlayerInit()
{

	isFinish = true;

	playerpos.x = 0;
	playerpos.y = 0;

	player_w = 2;
	player_h = 8;

	player_facing_int = 2;
	player_anim_int = 1;

}

void LoadSprites()
{
	char map_filename[64];
	char chara_filename[64];

	for (int i = 0; i < 6; i++)
	{
		sprintfDx(map_filename, "data/map/map%02d.png", i + 1);

		map_ghandles[i] = LoadGraph(map_filename);
	}

	const char* Characters[] =
	{
		"pipo-charachip009b.png", "pipo-charachip010b.png", "pipo-charachip011b.png",
		"pipo-charachip018d.png", "pipo-charachip019a.png", "pipo-charachip019b.png",
		"pipo-charachip021e.png", "pipo-charachip022d.png", "pipo-charachip025c.png"
	};

	for (int i = 0; i < 9; i++)
	{
		sprintfDx(chara_filename, "data/animation/%s", Characters[i]);
		chara_ghandles[i] = LoadGraph(chara_filename, 0);
	}

}

void GameInit()
{
	// マップチップ用画像の読み込み処理
	LoadSprites();
	PlayerInit();
}

int movementframe = 0;

void MovementAnimHandler()
{
	movementframe++;
	if (movementframe >= 1)
	{
		player_anim_int = 2;
	}
	if (movementframe >= 2)
	{
		player_anim_int = 1;
	}
	if (movementframe >= 3)
	{
		player_anim_int = 0;
	}
	if (movementframe >= 4)
	{
		player_anim_int = 1;
		movementframe = 0;
	}
}

enum Path { Grass = 0, Sand = 5, FinishHole = 4 };



bool IsNotWall(int h_facing, int w_facing)
{
	return map_now[player_h + h_facing][player_w + w_facing] == Grass || map_now[player_h + h_facing][player_w + w_facing] == Sand || map_now[player_h + h_facing][player_w + w_facing] == FinishHole;
}

bool bDisplayGrid = false;
int map_number = 0;

bool IsBorder(bool isPressed)
{
	return isPressed && player_w > 0;
}

void PlayerControl()
{
	if (IsKeyOn(KEY_INPUT_RIGHT) && player_w < MAP_W - 1 && IsNotWall(0, 1))
	{
		player_facing_int = 2;
		MovementAnimHandler();
		player_w++;

	}
	if (IsBorder( IsKeyOn(KEY_INPUT_LEFT))&& IsNotWall(0, -1))
	{
		player_facing_int = 1;
		MovementAnimHandler();
		player_w--;

	}
	if (IsKeyOn(KEY_INPUT_UP) && player_h > 0 && IsNotWall(-1, 0))
	{
		player_facing_int = 3;
		MovementAnimHandler();
		player_h--;
	}
	if (IsKeyOn(KEY_INPUT_DOWN) && player_h < MAP_H - 1 && IsNotWall(1, 0))
	{
		player_facing_int = 0;
		MovementAnimHandler();
		player_h++;
	}

	playerpos.x = player_w;
	playerpos.y = player_h;

}

void DebugControl()
{
	if (IsKeyOn(KEY_INPUT_SPACE))
	{
		map_number++;

		if (map_number > 1)
		{
			map_number = 0;
		}
	}

	if (IsKeyOn(KEY_INPUT_F2))
	{
		bDisplayGrid = !bDisplayGrid;
	}
}

void GameUpdate()
{
	//SetFontSize(FontSize++);

	//IsKeyOn
	DebugControl();

	if (!isFinish)
	{
		PlayerControl();
	}

	if (map_now[player_h][player_w] == FinishHole)
	{
		isFinish = true;
	}
}

void DrawMap()
{
	if (map_number == 0)
	{
		GenerateMap(map);
	}

	if (map_number == 1)
	{
		GenerateMap(map1);
	}
}

void DisplayGrid()
{
	if (bDisplayGrid)
	{
		for (int h = 0; h < MAP_H; h++)
		{
			for (int w = 0; w < MAP_W; w++)
			{
				DrawLine(IMG_SIZE * w, 0, IMG_SIZE * w, WINDOW_H, RED, 1);
			}
			DrawLine(0, IMG_SIZE * h, WINDOW_W, IMG_SIZE * h, RED, 1);
		}
	}
}

//LoadDivGraph -> Load one image and automatically divide it into graphs. (In contrast to LoadGraph and DrawRectGraph)
//SCR : the coordinatepos inside the image file.
//Weight,Height : the size of the image

void GameDraw()
{
	//f1 dsiplay grid
	//DrawGraph(0, 0, map_ghandles[0], FALSE);
	DrawMap();	
	

	if (isFinish == true)
	{
		finishmessage.DrawMessageBox(200, 30);
		DrawString(WINDOW_W / 2 - 140, WINDOW_H / 2, "脱出しました！おめでとうございます！！！", YELLOW, 0);
	}

	DisplayGrid();
	DrawRectGraph(playerpos.x * 32, playerpos.y*32, IMG_SIZE * player_anim_int, IMG_SIZE * player_facing_int, IMG_SIZE, IMG_SIZE, chara_ghandles[0], 1);

}

void GameExit()
{
	for (int i = 0; i < 6; ++i)
	{
		DeleteGraph(map_ghandles[i]);
	}

}
