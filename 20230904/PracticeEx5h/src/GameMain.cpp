#include "WinMain.h"

// =====================================================
//	グローバル変数
//	複数の関数で共通して使いたい変数はここに書く
// =====================================================
const float BOX_W = 150;
const float BOX_H = 50;

//float select_box1_x			   = 0;	// X座標
//float select_box1_y			   = 0;	// Y座標
//float select_box1_w			   = 0;	// 幅
//float select_box1_h			   = 0;	// 高さ
//unsigned int select_box1_color = 0;	// 色

//float select_box2_x			   = 0;	// X座標
//float select_box2_y			   = 0;	// Y座標
//float select_box2_w			   = 0;	// 幅
//float select_box2_h			   = 0;	// 高さ
//unsigned int select_box2_color = 0;	// 色
//
//float select_box3_x			   = 0;	// X座標
//float select_box3_y			   = 0;	// Y座標
//float select_box3_w			   = 0;	// 幅
//float select_box3_h			   = 0;	// 高さ
//unsigned int select_box3_color = 0;	// 色

struct Pos
{
	int x = 0;
	int y = 0;
};
Pos mousePos;

struct UIBox 
{
	float x_ = 0;
	float y_ = 0;
	float w_ = 0;
	float h_ = 0;
	unsigned int color_ = 0;

	/*if (mousePos.x >= select_box1_x &&
		mousePos.x <= select_box1_x + select_box1_w &&
		mousePos.y >= select_box1_y &&
		mousePos.y <= select_box1_y + select_box1_h)
	{
		select_box1_color = BLUE;
	}*/
	void MouseHoverHitbox(float x,float y,float w,float h,int color,int colorhover)
	{
		color_ = color;
		if (mousePos.x >= x &&
			mousePos.y <= x + w &&
			mousePos.y >= y &&
			mousePos.y <= y  + h)
		{
			color_ = colorhover;
		}
	}

	void Draw()
	{
		DrawBoxAA(x_, y_, x_ + w_, y_ + h_, color_, TRUE, 1);
	}

};


int bg_ghandle = -1;	// 背景画像

//UIBox box1[] =
//{
//	{WINDOW_W / 2 - BOX_W / 2, WINDOW_H / 2, BOX_W , BOX_H,WHITE}
//}; //配列にする
UIBox box1;
UIBox box2;
UIBox box3;

void GameInit()
{
	box1 = { WINDOW_W / 2 - BOX_W / 2, WINDOW_H / 2, BOX_W , BOX_H,WHITE };
	box2 = { box1.x_, box1.y_ + 10, BOX_W , box1.h_+ 10,YELLOW };
	box3 = { box2.x_, box2.y_ + 10, BOX_W , box2.h_ + 10,BLACK };
	Pos mousePos[] = {0,0};

	/*box1.x	  = WINDOW_W / 2 - BOX_W / 2;
	box1.y	  = WINDOW_H / 2;
	box1.w = BOX_W;
	box1.h = BOX_H;
	box1.color = WHITE;*/

	// 選択用のボックス1の初期化
	/*select_box1_x	  = WINDOW_W / 2 - BOX_W / 2;
	select_box1_y	  = WINDOW_H / 2;
	select_box1_w	  = BOX_W;
	select_box1_h	  = BOX_H;
	select_box1_color = WHITE;*/

	//// 選択用のボックス2の初期化
	//select_box2_x	  = select_box1_x;
	//select_box2_y	  = select_box1_y + BOX_H + 10;
	//select_box2_w	  = BOX_W;
	//select_box2_h	  = BOX_H;
	//select_box2_color = WHITE;

	//// 選択用のボックス3の初期化
	//select_box3_x	  = select_box1_x;
	//select_box3_y	  = select_box2_y + BOX_H + 10;
	//select_box3_w	  = BOX_W;
	//select_box3_h	  = BOX_H;
	//select_box3_color = WHITE;


	// 背景画像の読み込み
	bg_ghandle = LoadGraph("data/BG/pipo-battlebg001.jpg");

}
// =====================================================
//		更新
//	ゲームが終了されるまで実行される関数
//	1秒間に約60回呼ばれる
//	1フレームで行う処理をここに書く
// =====================================================
void GameUpdate()
{
	/*select_box2_color = WHITE;
	select_box3_color = WHITE;*/


	/*int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();*/

	//mousePos.x = GetMouseX();
	//mousePos.y = GetMouseY();
	mousePos = { GetMouseX(), GetMouseY() };

	box1.MouseHoverHitbox(box1.x_, box1.y_, box1.w_, box1.h_, WHITE,BLUE);
	box2.MouseHoverHitbox(box1.x_, box1.y_, box1.w_, box1.h_, RED, PINK);
	box3.MouseHoverHitbox(box1.x_, box2.y_, box1.w_, box2.h_, BLACK,YELLOW);
	// マウスカーソルと選択用ボックス1が当たっている
	/*if (mousePos.x >= select_box1_x &&
		mousePos.x <= select_box1_x + select_box1_w &&
		mousePos.y >= select_box1_y &&
		mousePos.y <= select_box1_y + select_box1_h)
	{
		select_box1_color = BLUE;
	}*/
	// マウスカーソルと選択用ボックス2が当たっている
	//if (mouse_x >= select_box2_x &&
	//	mouse_x <= select_box2_x + select_box2_w &&
	//	mouse_y >= select_box2_y &&
	//	mouse_y <= select_box2_y + select_box2_h)
	//{
	//	select_box2_color = BLUE;
	//}
	//// マウスカーソルと選択用ボックス3が当たっている
	//if (mouse_x >= select_box3_x &&
	//	mouse_x <= select_box3_x + select_box3_w &&
	//	mouse_y >= select_box3_y &&
	//	mouse_y <= select_box3_y + select_box3_h)
	//{
	//	select_box3_color = BLUE;
	//}


}
// =====================================================
//		描画
//	ゲームが終了されるまで実行される関数
//	1秒間に約60回呼ばれる
//	GameUpdate関数が実行された後に実行される関数
// =====================================================
void GameDraw()
{
	// 背景画像の描画
	DrawGraph(0, 0, bg_ghandle, FALSE);

	// 選択用ボックスの描画
	//DrawBoxAA(select_box1_x, select_box1_y, select_box1_x + select_box1_w, select_box1_y + select_box1_h, select_box1_color, TRUE);
	//DrawBoxAA(select_box2_x, select_box2_y, select_box2_x + select_box2_w, select_box2_y + select_box2_h, select_box2_color, TRUE);
	//DrawBoxAA(select_box3_x, select_box3_y, select_box3_x + select_box3_w, select_box3_y + select_box3_h, select_box3_color, TRUE);

	box1.Draw();
//	box2.Draw();
//	box3.Draw();
	//DrawBoxAA(box1.x_, box1.y_, box1.x_ + box1.w_, box1.y_ + box1.h_, box1.color_, TRUE, 1);


}
// =====================================================
//		終了
//	ゲームが終了する前に1回だけ実行される関数
//	何か最後に後片付けを行うときに使う
// =====================================================
void GameExit()
{
	// 背景画像の削除
	DeleteGraph(bg_ghandle);


}
