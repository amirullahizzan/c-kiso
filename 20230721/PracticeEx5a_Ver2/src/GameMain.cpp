#include "WinMain.h"


// =====================================================
//	グローバル変数
//	複数の関数で共通して使いたい変数はここに書く
// =====================================================
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
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	{5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,},
	{0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
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
int player_anim_int = 1;

void GameInit()
{
	// マップチップ用画像の読み込み処理

	char map_filename[64];
	char chara_filename[64];

	player_x = 0;
	player_y = 0;

	player_w = 2;
	player_h = 8;

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


enum Path{Grass = 0, Sand = 5};

bool IsNotWall(int h_facing, int w_facing)
{
	Path path1;
	Path path2;
	path1 = Grass;
	path2 = Sand;
	return map_now[player_h + h_facing][player_w + w_facing] == Grass || map_now[player_h + h_facing][player_w + w_facing] == Sand ;
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
	
	if (IsKeyOn(KEY_INPUT_RIGHT) && player_w < MAP_W-1 && IsNotWall(0,1))
	{
		player_facing_int = 2;
		MovementAnimHandler();
		player_w++;

	}
	if (IsKeyOn(KEY_INPUT_LEFT) && player_w > 0 && IsNotWall(0,-1))
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
}

void GameUpdate()
{

	//IsKeyOn
	PlayerControl();
	
}
//LoadDivGraph -> Load one image and automatically divide it into graphs. (In contrast to LoadGraph and DrawRectGraph)
//SCR : the coordinatepos inside the image file.
//Weight,Height : the size of the image
void GameDraw()
{
	//f1 dsiplay grid

	//DrawGraph(0, 0, map_ghandles[0], FALSE);

	if (map_number == 0)
	{
		
		GenerateMap(map);

	}

	if (map_number == 1)
	{
		GenerateMap(map1);

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

		player_x = player_w * IMG_SIZE;
		player_y = player_h * IMG_SIZE;
	
	DrawRectGraph(player_x, player_y, IMG_SIZE *player_anim_int, IMG_SIZE *player_facing_int, IMG_SIZE, IMG_SIZE, chara_ghandles[0], 1);

}

void GameExit()
{
	for (int i = 0; i < 6; ++i)
	{
		DeleteGraph(map_ghandles[i]);
	}

}
