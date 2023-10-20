#pragma once

class Circle
{
protected:
	//anything this one cannot be 
	//inherited by other class
	//also counts as a private 

	int protectedint = 0;

private:
	// --------------------------
	//	メンバ変数
	// --------------------------
			 float x_ = 0, y_ = 0;		// 座標
			 float r_ = 0;				// 半径
			 float target_y_ = 0;		// 目標座標（Y）
	unsigned int   color_    = 0;		// 色
			 bool  is_spawn_  = false;	// 出現したかどうか
			 int dirstate_ = 0;
			 int maxbouncecount = 0;
			 int currentbouncecount = 0;
			 int randforce = 0;
			 
			 void bounce(); //goes in update
public:
			 

	Circle();		// コンストラクタ
	~Circle();		// デストラクタ //ティルダ　チルダ

	// --------------------------
	//	メンバ関数
	// --------------------------
	void spawn();	// 出現処理(出現する1回だけ呼ぶ)
	void update();	// 更新処理
	void render();	// 描画処理

	void debuglog();

	bool isSpawn() const;	// 出現しているかどうか

};