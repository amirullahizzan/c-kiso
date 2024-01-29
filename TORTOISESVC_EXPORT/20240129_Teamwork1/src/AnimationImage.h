#pragma once
// =====================================================
//	アニメーションクラス（ヘッダーファイル）
//	 1枚でアニメーションする画像を管理するクラス
// =====================================================
class AnimationImage
{
public:
	struct dest
	{
		int	 orders[4] = { -1, -1, -1, -1 }; // アニメーションの順番
		int	 speed	  = 0;					 // 再生速度（フレーム数）
		bool is_loop  = true;				 // ループするかどうか
	};

	AnimationImage();
	virtual ~AnimationImage();

	void attach(const dest& anim_info);
	void load(const std::string& fname);
	void update();

	int get() const
	{
		return orders_[index_];
	}
	int size() const
	{
		return size_;
	}
	int getGhandle() const
	{
		assert(ghandle_ != -1);

		return ghandle_;
	}
	int reset()
	{
		index_ = 0;
		frame_ = 0;
	}
	bool isPlay() const
	{
		if (is_loop_ == true)
			return true;

		return index_ < (int)(size_ - 1);
	}

private:
				bool   is_loop_ = false;	 // ループするかどうか
				int	   play_speed_	= 0;	 // 再生速度
	std::array<int, 4> orders_		= { 0 }; // 順番
	unsigned int	   size_		= -1;	 // ordersのサイズ
				int	   index_		= -1;	 // インデックス
				int	   frame_		= 0;	 // フレーム数

	void initInfo();					     // 上記を初期化する


	int ghandle_ = -1;			 // アニメーション画像
};