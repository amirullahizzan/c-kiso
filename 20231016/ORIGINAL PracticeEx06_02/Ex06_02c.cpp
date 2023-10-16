// RectクラスのsetSize関数, getW関数, getH関数を使用して、
// 2つの長方形の面積を求めて、どちらが大きいのか（もしくは同じサイズなのか）を
// 出力するプログラムを完成させてください。
// なお、長方形のサイズは以下の通りです。
// 1つ目の長方形: 幅/10, 20, 30, 40, 50の乱数, 高さ/20
// 2つ目の長方形: 幅/20, 50の乱数, 高さ/10, 20, 30, 40, 50の乱数
#include <iostream>
#include <ctime>
using namespace std;

// --------------------------------------------------
//	ここから編集禁止
class Rect
{
private:
	int width_  = 0;	// 幅
	int height_ = 0;	// 高さ

public:
	// 長方形のサイズを設定する関数
	//	幅と高さを引数に渡して、メンバ変数に値を代入する
	void setSize(int w, int h);
	// 幅を取得する
	int getW();
	// 高さを取得する
	int getH();

};

// 幅と高さを引数に渡して、メンバ変数に値を代入する
void Rect::setSize(int w, int h)
{
	width_  = w;
	height_ = h;
}

// 幅を取得する
int Rect::getW()
{
	return width_;
}

// 高さを取得する
int Rect::getH()
{
	return height_;
}
//	ここまで編集禁止
// --------------------------------------------------

