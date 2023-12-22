#include "WinMain.h"

// =====================================================
//	グローバル変数
//	複数の関数で共通して使いたい変数はここに書く
// =====================================================
namespace
{
	class Circle
	{
	private:
		Color color_;
		Pos   pos_;
		float r_		 = 0;
		float vel_		 = 0;
		float acc_		 = 0;
		float move_x_	 = 0;
		int	  frame_	 = 0;
		bool  is_remove_ = false;

	public:
		Circle() {}
		virtual ~Circle() {}

		void init();
		void update();
		void render() const;

		bool isRemove() const
		{
			return is_remove_;
		}
	};
	void Circle::init()
	{
		r_		   = (float)(15 + (GetRand(5) * 5));
		pos_	   = { WINDOW_W / 2, WINDOW_H / 2 };
		frame_	   = 60 * (1 + GetRand(5));
		is_remove_ = false;
		color_	   = { (unsigned int)(127 + GetRand(128)), (unsigned int)(GetRand(128)), (unsigned int)(GetRand(255)) };
		vel_	   = (float)(10 + GetRand(10)) * -1;
		acc_	   = 1;
		move_x_	   = (float)(1 + GetRand(10));
		move_x_	   = (GetRand(100) % 2 == 0) ? move_x_ * -1 : move_x_;
	}
	void Circle::update()
	{
		if (is_remove_)
			return;

		--frame_;
		if (frame_ < 0)
		{
			is_remove_ = true;
		}
		vel_ += acc_;
		pos_.y += vel_;
		pos_.x += move_x_;

		if (pos_.y >= WINDOW_H - r_)
		{
			pos_.y	= WINDOW_H - r_;
			acc_	= 0;
			move_x_ = 0;
		}
	}
	void Circle::render() const
	{
		if (is_remove_)
			return;
		DrawCircleAA(pos_.x, pos_.y, r_, 64, color_.get(), TRUE);
	}

	Circle* circles	  = nullptr;
	int		size	  = 0;
	int		add_frame = 0;

}

// =====================================================
//		初期化
//	ゲーム開始直後に最初に1回だけ実行される関数
//	最初の値を変数に入れたいときに使う
// =====================================================
void GameInit()
{

}
// =====================================================
//		更新
//	ゲームが終了されるまで実行される関数
//	1秒間に約60回呼ばれる
//	1フレームで行う処理をここに書く
// =====================================================
void GameUpdate()
{
	++add_frame;
	if (add_frame > 60)
	{
		add_frame = 0;
		// 円の追加（配列の加算）
		if (size == 0)
		{
			++size;
			circles = new Circle[size];
			circles[size - 1].init();
		}
		else
		{
			Circle* tmp_circles = new Circle[size];
			for (int i = 0; i < size; ++i)
			{
				tmp_circles[i] = circles[i];
			}
			delete[] circles;
			circles = nullptr;
			circles = new Circle[size + 1];
			for (int i = 0; i < size; ++i)
			{
				circles[i] = tmp_circles[i];
			}
			circles[size] = Circle();
			++size;
			delete[] tmp_circles;
			tmp_circles = nullptr;

			circles[size - 1].init();
		}
	}

	for (int i = 0; i < size; ++i)
	{
		circles[i].update();
	}

	// 不要な円の削除（配列の減少）
	int remove_count = 0;
	for (int i = 0; i < size; ++i)
	{
		if (circles[i].isRemove() == false)
			continue;
		remove_count++;
	}
	if (remove_count > 0)
	{
		int new_size = size - remove_count;
		Circle* tmp_circle = new Circle[new_size];

		for (int i = 0, j = 0; i < size; ++i)
		{
			if (circles[i].isRemove() != false)
				continue;
			tmp_circle[j] = circles[i];
			++j;
			if (j >= new_size)
			{
				break;
			}
		}
		delete[] circles;
		circles = nullptr;
		circles = new Circle[new_size];
		for (int i = 0; i < new_size; ++i)
		{
			circles[i] = tmp_circle[i];
		}
		size = new_size;
		delete[] tmp_circle;
		tmp_circle = nullptr;
	}
}
// =====================================================
//		描画
//	ゲームが終了されるまで実行される関数
//	1秒間に約60回呼ばれる
//	GameUpdate関数が実行された後に実行される関数
// =====================================================
void GameDraw()
{
	for (int i = 0; i < size; ++i)
	{
		circles[i].render();
	}

	DrawFormatString(5, 5, WHITE, "現在の円の数: %2d", size);
}
// =====================================================
//		終了
//	ゲームが終了する前に1回だけ実行される関数
//	何か最後に後片付けを行うときに使う
// =====================================================
void GameExit()
{
	if (circles != nullptr)
	{
		delete[] circles;
		circles = nullptr;
	}


}
