#include "WinMain.h"


// =====================================================
//	グローバル変数
//	複数の関数で共通して使いたい変数はここに書く
// =====================================================
int map_ghandles[6];	// マップチップ用画像の配列変数
int chara_ghandles[9];

int player_x;
int player_y;


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
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	{5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};

//int speed;
int player_facing_int;
int player_anim_int = 1;

void GameInit()
{
	// マップチップ用画像の読み込み処理

	char map_filename[64];
	char chara_filename[64];

	player_x = 32*1;
	player_y = 32*8;

	player_facing_int = 2;
//	speed = 0;

	for (int i =0 ;i<6;i++)
	{
		sprintfDx(map_filename, "data/map/map%02d.png", i+1);
		
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



int movementframe_ms = 0;

void MovementAnimHandler()
{
	movementframe_ms++;
	if (movementframe_ms >= 1)
	{
		player_anim_int = 2;
	}
	if (movementframe_ms >= 2)
	{
		player_anim_int = 1;
	}
	if (movementframe_ms >= 3)
	{
		player_anim_int = 0;
	}
	if (movementframe_ms >= 4)
	{
		player_anim_int = 1;
		movementframe_ms = 0;
	}
}

bool bDisplayGrid = false;
int map_number = 0;
void PlayerControl()
{
	/*if (CheckHitKey(KEY_INPUT_LSHIFT))
	{
		speed = 2;
	}
	else
	{
		speed = 0;
	}*/
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
	
	if (IsKeyOn(KEY_INPUT_RIGHT) && player_x < WINDOW_W-32)
	{
		player_facing_int = 2;
		MovementAnimHandler();
		player_x +=IMG_SIZE;

	}
	if (IsKeyOn(KEY_INPUT_LEFT) && player_x > 0)
	{
		player_facing_int = 1;
		MovementAnimHandler();
		player_x -= IMG_SIZE;

	}
	if (IsKeyOn(KEY_INPUT_UP) && player_y > 0)
	{
		player_facing_int = 3;
		MovementAnimHandler();
		player_y -= IMG_SIZE;
	}
	if (IsKeyOn(KEY_INPUT_DOWN) && player_y < WINDOW_H - 32)
	{
		player_facing_int = 0;
		MovementAnimHandler();
		player_y += IMG_SIZE;

	}
}

void GameUpdate()
{

	//IsKeyOn
	PlayerControl();
	
}
//LoadDivGraph -> Load one image and automatically divide it into graphs. (In contrast to LoadGraph and DrawRectGraph)
//SCR : the coordinatepos inside the image file.
//Weight,Height : the size of the image
int map_data = 0;
void GameDraw()
{
	//f1 dsiplay grid

	//DrawGraph(0, 0, map_ghandles[0], FALSE);

	if (map_number == 0)
	{
		for (int h = 0; h < MAP_H; h++)
		{
			for (int w = 0; w < MAP_W; w++)
			{
				 map_data = map[h][w];
				DrawGraph(IMG_SIZE * w, IMG_SIZE * h, map_ghandles[map_data], FALSE);
			}
		}
	}

	if (map_number == 1)
	{
		for (int h = 0; h < MAP_H; h++)
		{
			for (int w = 0; w < MAP_W; w++)
			{
				 map_data = map1[h][w];
				DrawGraph(IMG_SIZE * w, IMG_SIZE * h, map_ghandles[map_data], FALSE);
			}
		}
	}
	
		
		
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
	
	
	DrawRectGraph(player_x, player_y, IMG_SIZE *player_anim_int, IMG_SIZE *player_facing_int, IMG_SIZE, IMG_SIZE, chara_ghandles[0], 1);

}

void GameExit()
{
	for (int i = 0; i < 6; ++i)
	{
		DeleteGraph(map_ghandles[i]);
	}

}
