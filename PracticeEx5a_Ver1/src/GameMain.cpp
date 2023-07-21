#include "WinMain.h"

// =====================================================
//	グローバル変数
//	複数の関数で共通して使いたい変数はここに書く
// =====================================================
int map_ghandles[6];	// マップチップ用画像の配列変数
int chara_ghandles[9];

void GameInit()
{
	// マップチップ用画像の読み込み処理

	char map_filename[64];
	char chara_filename[64];


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

void GameUpdate()
{

}

void GameDraw()
{
	for (int i = 0;i<10;i++)
	{
		DrawGraph(100, 100, map_ghandles[0], FALSE);
	}
	
	DrawRectGraph(200, 200, 0, 0,25,35, chara_ghandles[0], 1);

}

void GameExit()
{
	for (int i = 0; i < 6; ++i)
	{
		DeleteGraph(map_ghandles[i]);
	}

}
