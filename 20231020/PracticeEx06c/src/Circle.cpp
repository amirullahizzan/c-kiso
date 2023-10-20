#include "WinMain.h"
#include "Circle.h"

// --------------------------------------------------
//	コンストラクタ
// --------------------------------------------------
Circle::Circle()
{

}

// --------------------------------------------------
//	デストラクタ
// --------------------------------------------------
Circle::~Circle()
{

}

// --------------------------------------------------
//	初期セットアップ
//	 出現する1回だけ呼ぶ
//	 ※ 毎フレーム呼ぶと、色や座標が毎フレーム変わる
// --------------------------------------------------
void Circle::spawn()
{
	if (isSpawn())
	{
		// すでに出現している場合は、以下の処理を行わない
		return;
	}
	// 出現処理
	is_spawn_ = true;	// 出現フラグをtrue(出現)にする
	currentbouncecount = 0; //Reset

	randforce = GetRand(8-3) + 3; //3~8
	maxbouncecount = GetRand(5 - 2) + 2; //2~5

	// サイズ(半径)の設定
	r_ = 15.0f + ((float)GetRand(5) * 5);	// 半径: 15, 20, 25, 30, 35, 40 のいずれか
	// 座標の設定
	x_ = WINDOW_W / 2;		// X座標: 画面中心
	y_ = WINDOW_H - r_ * 2;	// Y座標: 画面下部
	// 目標座標（Y）の設定
	target_y_ = r_ + (float)GetRand(WINDOW_H / 2 - (int)r_ * 3);	// 画面の上半分でランダム

	// 色の設定
	const unsigned int COLORS[] =
	{
		RED, GREEN, BLUE, PINK, WHITE
	};
	const int COLORS_NUM = sizeof(COLORS) / sizeof(*COLORS);
	color_ = COLORS[GetRand(COLORS_NUM - 1)];

	// ↑と同じ処理を配列を使わずにする場合
	//switch (GetRand(4))
	//{
	//case 0:	color_ = RED;	break;
	//case 1:	color_ = GREEN;	break;
	//case 2:	color_ = BLUE;	break;
	//case 3:	color_ = PINK;	break;
	//case 4:	color_ = WHITE;	break;
	//}

}

// --------------------------------------------------
//	更新処理関数
//	 GameUpdate関数内で毎フレーム呼ぶこと
// --------------------------------------------------
void Circle::bounce()
{
	enum
	{
		right = 0,
		left = 1,
	};
	
		switch (dirstate_)
		{
		case right:
			x_ += randforce;
			if (x_ > WINDOW_W - r_)
			{
				currentbouncecount++;
				dirstate_ = 1;
			}
			break;
		case left:
			x_ -= randforce;
			if (x_ < 0 + r_)
			{
				currentbouncecount++;
				dirstate_ = 0;
			}
			break;
		}

	
}

void Circle::update()
{
	if (!isSpawn())
	{
		// 出現していない場合は、以降の処理を行わない
		return;
	}

	// Y座標を目標座標に近づける
	y_ += (target_y_ - y_) * 0.05f;
	// 現在位置と目標位置の距離が10より小さくなったら破棄
	if (getDistance(x_, y_, x_, target_y_) < 10.0f)
	{
		bounce();
		if (currentbouncecount > maxbouncecount)
		{
			is_spawn_ = false;
		}
	}
}

// --------------------------------------------------
//	描画処理関数
//	 GameDraw関数内で毎フレーム呼ぶこと
// --------------------------------------------------
void Circle::render()
{
	
	if (!isSpawn())
	{
		// 出現していない場合は、以降の処理を行わない
		return;
	}

	DrawCircleAA(x_, y_, r_, 32, color_);

	// Debug
	//printfDx("dist: %.2f\n", getDistance(x_, y_, x_, target_y_));
}

void Circle::debuglog()
{
	//render
	printfDx("rand : %d\n", randforce);
	printfDx("rand : %d\n", currentbouncecount);
	printfDx("rand : %d\n", maxbouncecount);

	printfDx("┗けいせんと言います。");
}

// --------------------------------------------------
//	出現しているかどうか取得用関数
//	 出現している場合、trueが返り、
//	 出現していない場合、falseが返る
// --------------------------------------------------
bool Circle::isSpawn() const
{
	return is_spawn_;
}

//inherits a class
//anything can be redefined except protected
class Box :
public Circle
{
private :
	int color = 255;
public :

};