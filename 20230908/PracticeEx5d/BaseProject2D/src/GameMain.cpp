#include "WinMain.h"

// =====================================================
//	列挙体
//	決まった値しか入れることのできない変数
// =====================================================



// =====================================================
//	定数
//	最初から決まっていてあとから変えることができない変数
// =====================================================



// =====================================================
//	構造体
//	変数をひとまとめにして新しく変数を作る
// =====================================================
class Reel
{
	int reel_timer = 0;
	int slot_image = 0;
	int TOTALSEQUENCE = 21;
	int slot_sequence[21] = {};
public:
	void SetSlotImage(int NewSlot)
	{
		slot_image = NewSlot;
	}
	int GetSlotImage()
	{
		return slot_image;
	}
	void RollReel()
	{
		reel_timer++;
		if (reel_timer % 10 == 0)
		{
			//change reel image
		}
	}
	void SetSequence(int newsequence[])
	{
		for (int i = 0;i<TOTALSEQUENCE;i++)
		{
			slot_sequence[i] = newsequence[i];
		}
	}
	
};

Reel reel1;
Reel reel2;
Reel reel3;


// =====================================================
//	グローバル変数
//	複数の関数で共通して使いたい変数はここに書く
// =====================================================
#define SLOTS_TYPES_COUNT 8

int slot_handler[SLOTS_TYPES_COUNT] = {};

// =====================================================
//	関数プロトタイプ
//	関数の宣言のみ・定義は後で行う
// =====================================================



void GameInit()
{

	for (int i = 0; i < 8; i++)
	{
	char slot_filename[128];
	sprintfDx(slot_filename, "data/slot_img%02d.png", (i+1));
	slot_handler[i] = LoadGraph(slot_filename); //258 x 258
	}
	//slot_handler[1] = LoadGraph("data/slot_img02.png"); //258 x 258
	//slot_handler[2] = LoadGraph("data/slot_img03.png"); //258 x 258
	//slot_handler[3] = LoadGraph("data/slot_img04.png"); //258 x 258
	//slot_handler[4] = LoadGraph("data/slot_img05.png"); //258 x 258
	//slot_handler[5] = LoadGraph("data/slot_img06.png"); //258 x 258
	//slot_handler[6] = LoadGraph("data/slot_img07.png"); //258 x 258
	//slot_handler[7] = LoadGraph("data/slot_img08.png"); //258 x 258

	reel1.SetSlotImage(slot_handler[0]);
	reel2.SetSlotImage(slot_handler[1]);
	reel3.SetSlotImage(slot_handler[2]);

	reel1.SetSequence();
}

void GameUpdate()
{

	if (IsKeyOn(KEY_INPUT_SPACE))
	{
		//roll 3 
		reel1.RollReel();
	}
	if (IsKeyOn(KEY_INPUT_A))
	{
		//stop
	}

	int game_frame = 0;
	game_frame++;

}
// =====================================================
//		描画
//	ゲームが終了されるまで実行される関数
//	1秒間に約60回呼ばれる
//	GameUpdate関数が実行された後に実行される関数
// =====================================================


void GameDraw()
{
	DrawGraph(0, (WINDOW_H / 2)-(IMG_SIZE/2),reel1.GetSlotImage(), 1);
	DrawGraph(IMG_SIZE, (WINDOW_H / 2)-(IMG_SIZE/2),reel2.GetSlotImage(), 1);
	DrawGraph(IMG_SIZE*2, (WINDOW_H / 2)-(IMG_SIZE/2),reel3.GetSlotImage(), 1);



}
// =====================================================
//		終了
//	ゲームが終了する前に1回だけ実行される関数
//	何か最後に後片付けを行うときに使う
// =====================================================
void GameExit()
{



}
