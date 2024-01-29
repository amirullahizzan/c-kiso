#include "WinMain.h"
#include "AnimationImage.h"
// =====================================================
//	アニメーションクラス（ソースファイル）
//	 1枚でアニメーションする画像を管理するクラス
// =====================================================
// -----------------------------------------------------
//		コンストラクタ
// -----------------------------------------------------
AnimationImage::AnimationImage() :
	play_speed_(0),
	orders_({ 0 }),	size_(-1), index_(-1),
	frame_(0)
{

}

// -----------------------------------------------------
//		デストラクタ
// -----------------------------------------------------
AnimationImage::~AnimationImage()
{
	if (ghandle_ != -1)
	{
		DeleteGraph(ghandle_);
	}
}

// -----------------------------------------------------
//		アニメーションアタッチ
// -----------------------------------------------------
void AnimationImage::attach(const dest& anim_info)
{
	assert(ghandle_ != -1);

	initInfo();

	play_speed_ = anim_info.speed;
	int i = 0;
	for ( ; i < 4; ++i)
	{
		if (anim_info.orders[i] == -1)
			break;

		orders_[i] = anim_info.orders[i];
	}
	is_loop_ = anim_info.is_loop;

	size_  = i;
	index_ = 0;
	frame_ = 0;
}

// -----------------------------------------------------
//		画像の読み込み
// -----------------------------------------------------
void AnimationImage::load(const std::string& fname)
{
	if (ghandle_ != -1)
	{
		DeleteGraph(ghandle_);
	}
	ghandle_ = LoadGraph(fname.c_str());

	assert(ghandle_ != -1);
}

// -----------------------------------------------------
//		更新
// -----------------------------------------------------
void AnimationImage::update()
{
	assert(size_ != -1);

	++frame_;
	frame_ %= play_speed_;

	if (frame_ == 0)
	{
		++index_;
		if (is_loop_ == true)
		{
			index_ %= size_;
		}
		else
		{
			if (index_ >= (int)(size_ - 1))
			{
				index_  = (int)(size_ - 1);
			}
		}
	}

}

// -----------------------------------------------------
//		変数初期化
//	アニメーション関連の変数をattach前に初期化する
// -----------------------------------------------------
void AnimationImage::initInfo()
{
	std::fill(orders_.begin(), orders_.end(), -1);
	size_		= -1;
	index_		= -1;
	frame_		= 0;
	play_speed_ = 0;
	is_loop_	= false;
}

